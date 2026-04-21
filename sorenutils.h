// https://www.geeksforgeeks.org/cpp/how-do-i-create-a-library-in-cpp/
// sorenutils.h

#ifdef _WIN32 // Windows (sia 32 che 64 bit)
	#include <windows.h>
#else // Linux o macOS
	#include <sys/ioctl.h>
	#include <unistd.h>
#endif

#include <time.h>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

#ifndef SORENUTILS_H
	#define SORENUTILS_H

	struct Color{
		string t_bk="\033[30m";
		string t_rd="\033[31m";
		string t_gn="\033[32m";
		string t_yw="\033[33m";
		string t_be="\033[34m";
		string t_ma="\033[35m";
		string t_cn="\033[36m";
		string t_we="\033[37m";
		string tb_bk="\033[90m";
		string tb_rd="\033[91m";
		string tb_gn="\033[92m";
		string tb_yw="\033[93m";
		string tb_be="\033[94m";
		string tb_ma="\033[95m";
		string tb_cn="\033[96m";
		string tb_we="\033[97m";
		string b_bk="\033[40m";
		string b_rd="\033[41m";
		string b_gn="\033[42m";
		string b_yw="\033[43m";
		string b_be="\033[44m";
		string b_ma="\033[45m";
		string b_cn="\033[46m";
		string b_we="\033[47m";
		string bb_bk="\033[100m";
		string bb_rd="\033[101m";
		string bb_gn="\033[102m";
		string bb_yw="\033[103m";
		string bb_be="\033[104m";
		string bb_ma="\033[105m";
		string bb_cn="\033[106m";
		string bb_we="\033[107m";
		string cl="\033[0m";
	};

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
							case 29:
								if(month==2){
									month+=1;
									day=0;
								};
								break;
							case 30:
								if(month==4 || month==6 || month==9 || month==11){
									month+=1;
									day=0;
								};
								break;
							case 31:
								month+=1;
								day=0;
								if(month==13){
									year+=1;
									month=1;
								};
								break;
						};
			    	}else{
					    switch(day){
						    case 28:
						    	if(month==2){
								    month+=1;
								    day=0;
								};
	    						break;
			    			case 30:
				    			if(month==4 || month==6 || month==9 || month==11){
				    				month+=1;
					    			day=0;
							    };
							    break;
							case 31:
    							month+=1;
		    					day=0;
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
			if(cr==0){
      			int columns=csbi.srWindow.Right - csbi.srWindow.Left + 1;
      			if(columns==0){cout<<"Columns not Found; Insert Manually: "; cin>>columns;};
				return columns;
    		}else{
    			int rows=csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    			if(rows==0){cout<<"Rows not Found; Insert Manually: "; cin>>rows;};
    			return rows;
    		};
		#else
			struct winsize w;
			ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
			if(cr==0){
    			int columns=w.ws_col;
    			if(columns==0){cout<<"Columns not Found; Insert Manually: "; cin>>columns;};
    			return columns;
    		}else{
    			int rows=w.ws_row;
    			if(rows==0){cout<<"Rows not Found; Insert Manually: "; cin>>rows;};
    			return rows;
    		};
		#endif
	}
	
	void alignOut(string Out, int a=0, int offset=0){ // 0=Left, 1=Center, 2=Right
	    int maxlen=termSize(0), strleng=Out.size()/sizeof(Out[0]);
		int remleng=strleng-maxlen*(strleng/maxlen);
	    switch(a){
	    	case 0:
				for(int i=0; i<strleng/maxlen; i++){
              		cout<<setw(maxlen)<<Out.substr((i*maxlen), maxlen+(i*maxlen))<<endl;
				};
         		cout<<setw(remleng+offset)<<Out.substr((strleng-remleng), remleng);
				break;
	      case 1:
				for(int i=0; i<strleng/maxlen; i++){
            	  	cout<<setw(maxlen)<<Out.substr((i*maxlen), maxlen+(i*maxlen))<<endl;
				};
         		cout<<setw((maxlen+remleng)/2+offset)<<Out.substr((strleng-remleng), remleng);
				break;
	      case 2:
				for(int i=0; i<strleng/maxlen; i++){
            	  	cout<<setw(maxlen)<<Out.substr((i*maxlen), maxlen+(i*maxlen))<<endl;
				};
         		cout<<setw(maxlen+offset)<<Out.substr((strleng-remleng), remleng);
				break;
	   };
	}

	void order(auto arr[], int q, auto &field, bool ord=true){ // 0=Decrescente 1=Crescente
		auto f=static_cast<bool*>(static_cast<void*>(&field))-static_cast<bool*>(static_cast<void*>(&arr[0]));
		for(int i=0; i<q-1; i++){
			auto ip=static_cast<decltype(&field)>(static_cast<void*>(static_cast<bool*>(static_cast<void*>(&arr[i]))+f));
			for(int j=i+1; j<q; j++){
				auto jp=static_cast<decltype(&field)>(static_cast<void*>(static_cast<bool*>(static_cast<void*>(&arr[j]))+f));
				// Scelta Ordine
				if(ord){ // Ordinamento Crescente
					// Scambio Posizione
					if(*jp<*ip){
						auto temp=arr[j];
						arr[j]=arr[i];
						arr[i]=temp;
					};
				}else{ // Ordinamento Decrescente
					// Scambio Posizione
					if(*jp>*ip){
						auto temp=arr[j];
						arr[j]=arr[i];
						arr[i]=temp;
					};
				};
			};
		};
	}
#endif