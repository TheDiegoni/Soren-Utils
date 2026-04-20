/*
	Autore: Diego Rocco
	Traccia: Nel gioco del "Master Mind" l'obiettivo è
		scoprire un codice segreto.

		Il codice è formato da NCIFRE numero di cifre
		(ad esempio 5)

		Le cifre possono essere ripetute

		Bisogna trovare il codice segreto nel minor
		numero di tentativi

		Un tentativo è un codice dello stesso numero di
		cifre

		Il direttore di gioco (o il computer) che sa il
		codice segreto risponde indicando:
			- Quanti "strike" (cifre giuste al posto
			  giusto) sono presenti nel tentativo
			- Quanti "ball" (cifre giuste al posto
			  sbagliato) sono presenti nel tentativo

		Si vince quando il numero di strike è NCIFRE
*/

// Intestazione
#include <iostream>
#include <time.h>
#include <string>
#include "sorenutils.h"
using namespace std;

// Dichiarazione Globale
const int Mv=5, Cc=6; // Numero di Mosse, Numero di Cifre

// Prototipazione Sottoprogrammi
void codeg(int Code[]); // Sottoprogramma Generazione Codice
void input(int In[]); // Sottoprogramma Input Risposta
void compare(int In[], int Code[], bool Found[]); // Sottoprogramma Controllo Risposta
void newtry(int &Tries, int In[][Cc], bool Found[][Cc*2]); // Sottoprogramma Nuovo Tentativo
bool correct(bool Found[]); // Sottoprogramma Controllo Corrette

// Main
int main(){
	// Dichiarazione Globale
	int tries=0, code[Cc], in[Mv][Cc]; // Contatore Tentativi, Vettore Codice Segreto, Vettore Risposta Inserita
	bool found[Mv][Cc*2]; // Vettore Strike e Ball

	// Inizializzazione Gioco
	codeg(code); // Chiamata Generazione Codice
	cls(); // Chiamata Clear Screen
	alignOut("Benvenuti in Master Mind!", 1);
	alignOut("L'Obiettivo e Scoprire un Codice Segreto di "+to_string(Cc)+" Cifre, che possono esser Ripetute, nel Minor Numero di Tentativi possibili.", 1);
    alignOut("Ogni Tentativo verra Stampato a Schermo con le Cifre Colorate ad Indicare:", 1);
	alignOut("- Cifre Presenti al Posto Giusto (\033[92mVerdi\033[37m);", 1);
    alignOut("- Cifre Presenti al Posto Sbagliato (\033[91mRosse\033[37m);", 1);
    alignOut("- Cifre Non Presenti (\033[90mGrigie\033[37m).", 1);
	alignOut("Hai "+to_string(Mv)+" Tentativi.", 1);
	alignOut("Buona Fortuna.", 1);

	// Ciclo Risposte
	do{
		input(in[tries]); // Chiamata Input Risposta
		cls(); // Chiamata Clear Screen
		compare(in[tries], code, found[tries]); // Chiamata Controllo Risposta
		newtry(tries, in, found); // Chiamata Nuovo Tentativo

		// Chiamata Controllo Corrette
		if(correct(found[tries-1])){
                        alignOut("Hai Indovinato in "+to_string(tries)+" Tentativi!\n", 1); // Output Vittoria
                        cin.get(); return 0; // Fine Programma
                };
	}while(tries<Mv); // Fine Ciclo Risposte

	// Controllo Risposte Esaurite
	if(tries>=Mv){
		// Output Persa
		alignOut("Hai perso! La risposta era:\n", 1);
		string temp="";
		for(int i=0; i<Cc; i++){temp+=to_string(code[i])+" ";}; alignOut(temp, 1);
		cin.get(); return 0; // Fine Programma
	};
}

// Sottoprogramma Generazione Codice
void codeg(int Code[]){
	time_t sec=time(NULL); srand(sec); // Generazione Numeri Randomici usanto il Tempo
	for(int i=0; i<Cc; i++){Code[i]=((double)rand()/RAND_MAX)*9;}; // Ciclo Generazione Numeri
}

// Sottoprogramma Nuovo Tentativo
void newtry(int &Tries, int In[][Cc], bool Found[][Cc*2]){
	// Ciclo Stampa Tentativi
	for(int j=0; j<=Tries; j++){
        string temp="";
		// Ciclo Stampa Cifre
		for(int i=0; i<Cc*2; i+=2){
			int color=90; // Dichiarazione Variabile Colore
			// Controllo Cifra Ball
			if(Found[j][i]){
				// Controllo Cifra Strike
				if(Found[j][i+1]){color=92;}
				 else{color=91;};
			};
			temp+="\033["+to_string(color)+"m"+to_string(In[j][i/2])+"\033[37m "; // Stampa Cifra con Colore Corretto
		};
		alignOut("cen", 1);
		alignOut(temp, 1);
	};
	cout<<endl;
	Tries+=1; // Nuovo Tentativo
}

// Sottoprogramma Controllo Risposta
void compare(int In[], int Code[], bool Found[]){
	bool control[Cc]; // Vettore Posizioni Gia Controllate

	// Ciclo Controllo Strike
	for(int i=0; i<Cc*2; i+=2){
		// Controllo Cifra Combaciante
		if(In[i/2]==Code[i/2]){
			Found[i]=1;
			Found[i+1]=1;
			control[i/2]=1;
		}else{
			Found[i]=0;
			Found[i+1]=0;
			control[i/2]=0;
		 };
	};
	// Ciclo Selezione Cifra
	for(int i=0; i<Cc*2; i+=2){
		// Ciclo Controllo Ball
		for(int j=0; j<Cc; j++){
			// Controllo Cifra non Controllata
			if(!control[j] && !Found[i+1]){
				// Controllo Cifra Presente
				if(In[i/2]==Code[j]){
					Found[i]=1;
					control[j]=1;
					break;
				};
			};
		};
	};
	cout<<endl;
}

// Sottoprogramma Controllo Corrette
bool correct(bool Found[]){
	// Ciclo Controllo Corrette
	for(int i=0; i<Cc*2; i+=2){
		if(!(Found[i]&&Found[i+1])){
			return false;
		};
	};
	return true;
}

// Sottoprogramma Input Risposta
void input(int In[]){
	// Input Numeri
	cout<<"Inserisci la Tua Risposta (N1 N2 N3 N4 N5):"<<endl;
	for(int i=0; i<Cc; i++){cin>>In[i];};
}
