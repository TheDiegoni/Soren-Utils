// https://www.geeksforgeeks.org/cpp/how-do-i-create-a-library-in-cpp/
// sorenutils.h

#ifdef _WIN32 // Windows (sia 32 che 64 bit)
	#include <windows.h>
#else // Linux o macOS
	#include <sys/ioctl.h>
	#include <unistd.h>
#endif

#include <string>
using namespace std;

#ifndef SORENUTILS_H
	#define SORENUTILS_H

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
#endif
