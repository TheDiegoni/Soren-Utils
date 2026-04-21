/*
    Autore: Diego Rocco
    Traccia: Le Trasmissioni in Prima Serata su un Canale Televisivo nei
        diversi Giorni di un Mese Commerciale (1-30 Giorni) sono
        Organizzati in una Tabella con Giorno, Titolo, Regista e Durata.
        L'Elenco viene successivamente Ordinato Crescente per Giorno. Fornendo da
        Tastiera il Giorno, l'Utente puo Ottenere le altre Informazioni.
*/

// Intestazione
#include <iostream>
#include <string>
#include "sorenutils.h"
using namespace std;

// Struct Trasmissione TV
struct TV{
    string titolo;
    string regista;
    int durata;
    int giorno;
};

// Prototipazione Sottoprogrammi
void Programma(int t); // Programma Principale
void Out(TV T[], int t){for(int i=0; i<t; i++){cout<<T[i].giorno<<" "<<T[i].titolo<<endl;};} // Sottoprogramma Output Trasmissioni

// Main
int main(){
    // Inizializzazione Programma
    int t=0; // Quantita Trasmissioni
    cout<<"Quante Trasmissioni devi Inserire? "; cin>>t; // Input Quantita Trasmissioni
    cls(); // Chiamata Pulisci Schermo
    Programma(t); // Chiamata Programma Principale
    return 0;
}

// Programma Principale
void Programma(int t){
    // Dichiarazione Locale
    TV T[t]; // Array Trasmissioni
    int S; bool F; // Intero Scelta, Booleano Trovato Programma

    // Ciclo Input
    for(int i=0; i<t; i++){
        cout<<"Inserisci il Titolo della Trasmissione "<<i+1<<": "; cin.get(); getline(cin, T[i].titolo);
        cout<<"Inserisci la Durata della Trasmissione "<<i+1<<" in Minuti (Numero Arrotondato): "; cin>>T[i].durata;
        cout<<"Inserisci il Nome del Regista della Trasmissione "<<i+1<<": "; cin.get(); getline(cin, T[i].regista);
        cout<<"Inserisci il Giorno del Mese in cui la Trasmissione "<<i+1<<" andra in Onda (Numero): "; cin>>T[i].giorno;
        cls(); // Chiamata Pulisci Schermo
    };

    order(T, t, T[0].giorno); // Chiamata Ordinamento
    Out(T, t); // Chiamata Output Trasmissioni

    // Output
    do{
        F=0;
        cout<<"\nQuale Programmazione vuoi Visualizzare? (Giorno, 0=Exit, -1=Lista) "; cin>>S;
        cls();
        for(int i=0; i<t; i++){
            if(S==0){break;};
            if(S==-1){Out(T, t); break;};
            if(S==T[i].giorno){
                F=1;
                cout<<T[i].titolo<<" "<<T[i].regista<<endl;
                cout<<T[i].durata<<"m"<<endl;
            };
        };
        if(!F && S!=0 && S!=-1){
            cout<<"Nessun Programma Trovato :("<<endl;
        };
    }while(S!=0);
}