// https://www.geeksforgeeks.org/cpp/how-do-i-create-a-library-in-cpp/
// sorenutils.h

#ifdef _WIN32 // Windows (sia 32 che 64 bit)
	#include <windows.h>
#else // Linux o macOS
	#include <sys/ioctl.h>
	#include <unistd.h>
#endif

#include <time.h>
#include <string>
using namespace std;

#ifndef SORENUTILS_H
	#define SORENUTILS_H


	class Time{
		public:
			int hour;
			int minute;
			int second;
			void getTime(int bonus=0){
				time_t sec=time(NULL)+(bonus*3600);
				hour=(sec/3600)%24;
				minute=(sec-(sec/3600)*3600)/60;
				second=(sec-(sec/3600)*3600-minute*60);
			}
	};

	class Date{
		public:
			int day;
			int month;
			int year;
			void getDate(int bonus=0){
				time_t sec=time(NULL)+(bonus*3600);
				day=1; month=1; year=1970;
				for(int i=0; i+86400<sec; i+=86400){
					day+=1;
					if(year%4==0){
						switch(day){
							case 30:
								if(month==2){
									month+=1;
									day=1;
								};
								break;
							case 31:
								if(month==4 || month==6 || month==9 || month==11){
									month+=1;
									day=1;
								};
								break;
							case 32:
								month+=1;
								day=1;
								if(month==13){
									year+=1;
									month=1;
								};
								break;
						};
			    	}else{
					    day+=1;
					    switch(day){
						    case 29:
						    	if(month==2){
								    month+=1;
								    day=1;
								};
	    						break;
			    			case 31:
				    			if(month==4 || month==6 || month==9 || month==11){
				    				month+=1;
					    			day=1;
							    };
							    break;
							case 32:
    							month+=1;
		    					day=1;
			    				if(month==13){
				    				year+=1;
					    			month=1;
							    };
							    break;
						};
	    			 };
				};
			}
	};

	string lower(string Str){
        // Ciclo Lowercase
		for(int i=0; i<Str.length(); i++){
            if(Str[i]>=65&&Str[i]<=90){Str[i]+=32;}; // Controllo Uppercase e Conversione in Lowercase
	    };
        return Str; // Restituisci la Stringa Risultante
	}

	void cls(){
	    #ifdef _WIN32 // Windows (sia 32 che 64 bit)
           	system("cls");
        #else // Linux o macOS
           	system("clear");
        #endif
	}

	int termSize(bool cr){ // 0=Columns 1=Rows
		#ifdef _WIN32
			CONSOLE_SCREEN_BUFFER_INFO csbi;
			GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
			if(cr==0){return csbi.srWindow.Right - csbi.srWindow.Left + 1;}
			else{return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;};
		#else
			struct winsize w;
			ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
			if(cr==0){return w.ws_col;}
			else{return w.ws_row;};
		#endif
	}

	void order(auto vett[], int q, bool ord=true){ // 0=Decrescente 1=Crescente
		for(int i=0; i<q-1; i++){
			for(int j=i+1; j<q; j++){
				// Scelta Ordine
				if(ord){ // Ordinamento Crescente
					// Scambio Posizione
					if(vett[j]<vett[i]){
						auto temp=vett[j];
						vett[j]=vett[i];
						vett[i]=temp;
					};
				}else{ // Ordinamento Decrescente
					// Scambio Posizione
					if(vett[j]>vett[i]){
						auto temp=vett[j];
						vett[j]=vett[i];
						vett[i]=temp;
					};
				};
			};
		};
	}
#endif