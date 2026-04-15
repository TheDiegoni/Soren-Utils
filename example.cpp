#include "sorenutils.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
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
	return 0;
}
