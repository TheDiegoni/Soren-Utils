#include "sorenutils.h"
#include <iostream>
#include <string>
using namespace std;

struct Test{
    string name;
    int punt;
};

int main(){
	int I[6]={2, 4, 3, 1, 5, 6};
	float F[6]={4.3, 4.7, 1.5, 5.9, 6.7, 2.5};
	Test T[6]={{"Ciao", 5}, {"Mondo", 3}, {"Prova", 4}, {"Test", 2}, {"Soren", 1}, {"Utils", 6}};
	Color color;
	cls();
	cout<<lower("BuOnGiorNO!")<<endl;
	int columns=termSize(0); int rows=termSize(1);
	cout<<"Colonne: "<<columns<<endl;
	cout<<"Righe: "<<rows<<endl;
	for(int i=0; i<rows; i++){
		for(int j=0; j<columns; j++){
			cout<<'o';
		};
		cout<<endl;
	};
	order(I, 6, I[0], false);
	for(int i=0; i<6; i++) {
		cout<<I[i]<<endl;
	};
	cout<<endl;
	order(F, 6, F[0]);
	for(int i=0; i<6; i++) {
		cout<<F[i]<<endl;
	};
	cout<<endl;
	order(T, 6, T[0].punt, true);
	for(int i=0; i<6; i++) {
		cout<<T[i].name<<": "<<T[i].punt<<endl;
	};
	cout<<endl;
	Time t;	Date d;
	t.getTime(2); d.getDate(2);
	cout<<t.hour<<':'<<t.minute<<':'<<t.second<<' '<<d.day<<'/'<<d.month<<'/'<<d.year<<endl;
	alignOut("Ciao, questo e un testo di prova per l'allineamento a destra...dafssssssssssssssssssssssssssssssssssssssssssssswwwwwwwwwwwwwwwwwwwarwerrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrfesaaffffffffffffffffww", 0, 10); cout<<endl;
	alignOut("Ciao, questo e un testo di prova per l'allineamento a centro...dafssssssssssssssssssssssssssssssssssssssssssssswwwwwwwwwwwwwwwwwwwarwerrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrfesaaffffffffffffffffww", 1); cout<<endl;
	alignOut("Ciao, questo e un testo di prova per l'allineamento a sinistra.dafssssssssssssssssssssssssssssssssssssssssssssswwwwwwwwwwwwwwwwwwwarwerrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrfesaaffffffffffffffffww", 2, -20); cout<<endl;
	wait(5, true);
	string c=alignIn(0, "Inserisci Stringa Sinistra: ", 3);
	cout<<endl; alignOut(c, 0); cout<<endl;
	c=alignIn(2, "Inserisci Stringa Destra: ", -3);
	cout<<endl; alignOut(c, 0); cout<<endl;
	c=alignIn(1, "Inserisci Stringa Centro Sinistra: ", 3);
	cout<<endl; alignOut(c, 0); cout<<endl;
	c=alignIn(1, "Inserisci Stringa Centro Destra: ", -3);
	cout<<endl; alignOut(c, 0);
	c=alignIn(1, "Inserisci Stringa Centro: ");
	cout<<endl; alignOut(c, 0);
	wait(3);
	cout<<color.t_bk<<color.b_gn<<"Ciao "<<color.tb_rd<<color.bb_yw<<"Mondo!"<<color.cl<<" Close";
	cin.get()
	return 0;
}
