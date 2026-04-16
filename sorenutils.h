// https://www.geeksforgeeks.org/cpp/how-do-i-create-a-library-in-cpp/
// sorenutils.h

#ifdef _WIN32 // Windows (sia 32 che 64 bit)
	#include <windows.h>
#else // Linux o macOS
	#include <sys/ioctl.h>
	#include <unistd.h>
#endif

#include <time.h>
#include <iostream>
#include <string>
using namespace std;

#ifndef SORENUTILS_H
	#define SORENUTILS_H


	struct Time{
		int hour;
		int minute;
		int second;
	};
	struct Date{
		int day;
		int month;
		int year;
	};
	Time getTime(int bonus=0) {
		Time t; time_t sec=time(NULL)+(bonus*3600);
		t.hour=(sec/3600)%24;
		t.minute=(sec-(sec/3600)*3600)/60;
		t.second=(sec-(sec/3600)*3600-t.minute*60);
		return t;
	}
	Date getDate(int bonus=0) {
		Date d; time_t sec=time(NULL)+(bonus*3600);
		cout<<(sec/86400)%366<<endl;
		d.year=1970;
		d.day=0;
		int i=0;
		while(d.year*86400*365+(d.day+sec/(86400*365))*86400<=sec){
			cout<<d.year*86400*365+(d.day+sec/(86400*365))*86400<<endl;
			if(d.year%4==0){
				d.day--;
			};
			d.year++;
		};
		d.day+=sec/(86400*365);
		return d;
	}

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