#include "sorenutils.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
	int I[6]={2, 4, 3, 1, 5, 6};
	float F[6]={4.3, 4.7, 1.5, 5.9, 6.7, 2.5};
	cls();
	cout<<lower("BuOnGiorNO!")<<endl;
	cout<<"Colonne: "<<termSize(0)<<endl;
	cout<<"Righe: "<<termSize(1)<<endl;
	for(int i=0; i<termSize(1); i++){
		for(int j=0; j<termSize(0); j++){
			cout<<'o';
		};
		cout<<endl;
	};
	order(I, 6, 0);
	for(int i=0; i<6; i++) {
		cout<<I[i]<<endl;
	};
	cout<<endl;
	order(F, 6);
	for(int i=0; i<6; i++) {
		cout<<F[i]<<endl;
	};
	cout<<endl;
	Time t=getTime(2);
	Date d=getDate(2);
	cout<<t.hour<<':'<<t.minute<<':'<<t.second<</*' '<<d.day<<'/'<<d.month<<'/'<<d.year<<*/endl;
	return 0;
}
