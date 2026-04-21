/*
    Autore: Diego Rocco
    Traccia: Alla Fine di un Concorso vengono Pubblicati i Risultati delle
        Prove dei Concorrenti: vengono Memorizzati per ogni Partecipante
        il Nome e il Punteggio di 2 Prove. Si vuole Ottenere la Graduatoria
        Finale con la Visualizzazione dei Concorrenti Ordinati in modo
        Decrescente Rispetto al Punteggio Totale Conseguito.
*/

// Intestazione
#include <iostream>
#include <string>
#include "tabulate.hpp" // https://github.com/p-ranav/tabulate/tree/master
#include "sorenutils.h" // https://github.com/TheDiegoni/Soren-Utils
using namespace std;
using namespace tabulate;

// Struct Partecipante al Concorso
struct Partecipante{
    string name;
    int punt1;
    int punt2;
    int puntt;
};

// Prototipazione Sottoprogrammi
void Programma(int p); // Programma Principale

// Main
int main(){
    // Inizializzazione Programma
    int p=0; // Quantita Partecipanti
    cout<<"Quanti Concorrenti hanno Partecipato? "; cin>>p; // Input Quantita Partecipanti
    cls(); // Chiamata Pulisci Schermo
    Programma(p); // Chiamata Programma Principale

    return 0;
}

// Programma Principale
void Programma(int p){
    // Dichiarazione Locale
    Partecipante P[p]; // Array Partecipanti
    Table tab; tab.format().font_align(FontAlign::center); // Tabella Output

    // Ciclo Input
    for(int i=0; i<p; i++){
        cout<<"Inserisci il Nome del Concorrente "<<i+1<<": "; cin.get(); getline(cin, P[i].name);
        cout<<"Inserisci il Punteggio della Prima Prova del Concorrente "<<i+1<<" (Numero): "; cin>>P[i].punt1;
        cout<<"Inserisci il Punteggio della Seconda Prova del Concorrente "<<i+1<<" (Numero): "; cin>>P[i].punt2;
        P[i].puntt=P[i].punt1+P[i].punt2;
        cls(); // Chiamata Pulisci Schermo
    };

    order(P, p, P[0].puntt, false); // Chiamata Ordinamento

    // Output
    tab.add_row({"Nome", "Prova1", "Prova2", "Totale"}); // Aggiungi Fila alla Tabella
    for(int i=0; i<p; i++){
        tab.add_row({P[i].name, to_string(P[i].punt1), to_string(P[i].punt2), to_string(P[i].puntt)}); // Aggiungi Fila alla Tabella
    };
    cout<<tab; // Output Tabella Dati
    cin.get();
}