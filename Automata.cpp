
//	Ing. en Sistemas Computacionales
//	Luis Alfredo Cervantes González
//	Programación de Sistemas
//	Autómata

#include<iostream>
#include<windows.h>
#include <string>
using namespace std;

int main(){
	int tab[100][100], 
		litNum[100], 
		contGram=0, 
		col=0, 
		fil=0, 
		i=0, 
		j=0, 
		k=0, 
		l=0, 
		m=1,
		spc, 
		x, 
		y, 
		h;
	
	bool validar;
	
	string  validarCol,
			validarFil,
			gramInput, 
			gram[100], 
			lit[100], 
			option;
	
	//AJUSTAR LA CONSOLA.
	system("mode con: cols=60 lines=30");
	
	
	//INGRESO EN CANTIDAD DE ENTRADAS Y ESTADOS.
	cout<<"||========================================================||"<<endl;
	cout<<"||                        AUTOMATA                        ||"<<endl;
	cout<<"||========================================================||"<<endl;
		
		//VALIDACIÓN DE ENTRADAS
		validar = false;	
		while(validar != true){
			cout<<"   > CANTIDAD DE ENTRADAS: "; cin>>validarCol;
			col = atoi(validarCol.c_str());
			
			if(col > 0 && col < 100){	
				validar = true;
			}
		}
		
		//VALIDACIÓN DE ESTADOS
		validar = false;
		while(validar != true){
			cout<<"   > CANTIDAD DE ESTADOS: "; cin>>validarFil;
			fil = atoi(validarFil.c_str());
			
			if((fil > 0) && (fil < 100)){
				validar = true;
			}
		}	
				
	cout<<"||========================================================||"<<endl;	


	//INGRESO DE ENTRADAS.
	for(j=0;j<col;j++){
		cout<<"   > ENTRADA "<<j+1<<": ";
		cin>>lit[j];
	}	
	
	
	//INGRESO DE VALORES EN LOS ESTADOS Y ENTRADAS.
	cout<<"||========================================================||"<<endl;
	for(i=0;i<fil;i++){
		for(j=0;j<col;j++){
			
			
			//VALIDA EL INGRESO DE LAS FUNCIONES.
			do{
				validar = false;
				cout<<"   > F(Q("<<l<<"), "<<lit[j]<<") = ";
				cin>>tab[i][j];
			
				// k=0;k<fil;k++
				for(k=0;k<=fil;k++){
					if((tab[i][j]==k) || (tab[i][j]==-1)){
						validar=true;
					}
				}	
			}while(validar == false);
		}
		l++;
		cout<<"||========================================================||"<<endl;
	}
	
	
	//FUNCION DE TRANSICION.
	system("cls"); k=0;
	cout<<"||========================================================||"<<endl;
	cout<<"||                1. FUNCION DE TRANSICION                ||"<<endl;
	cout<<"||========================================================||"<<endl;
	
	
	for(i=0;i<fil;i++){
		for(j=0;j<col;j++){
			cout<<"   > F[Q("<<k<<"), "<<lit[j]<<"] = Q("<<tab[i][j]<<")"<<endl;
		}
		k++;
		cout<<"||========================================================||"<<endl;
	}
	system("pause");
	
	
	//TABLA DE TRANSICIONES.
	system("cls");
	cout<<"";
	k=0;
	cout<<"||========================================================||"<<endl;
	cout<<"||                 2. TABLA DE TRANSICION                 ||"<<endl;
	cout<<"||========================================================||"<<endl;
	cout<<"||  ESTADO  ||                  ENTRADAS                  ||"<<endl; 
	cout<<"||========================================================||"<<endl;
	cout<<"   >        ||";
	for(j=0;j<col;j++){
		cout<<"  "<<lit[j]<<" ";
		if(j==(col-1)){
			cout<<endl;
		}
	}
	cout<<"||========================================================||"<<endl;
	
	for(i=0;i<fil;i++){	
		cout<<"   > Q("<<k++<<")   ||";	
		for(j=0;j<col;j++){
			cout<<" ("<<tab[i][j]<<")";		
			if(j == (col-1)){
				cout<<endl;
			}	
		}	
		cout<<"||========================================================||"<<endl;
	}
	system("pause");
	
	
	//QUINTUPLA M DEL AUTOMATA.
	system("cls");
	cout<<"||========================================================||"<<endl;
	cout<<"||                     3. QUINTUPLA M                     ||"<<endl;
	cout<<"||========================================================||"<<endl;
	cout<<endl<<"   > M = ({";
	for(i=0;i<fil;i++){
		cout<<"Q("<<i<<")";
		
		if(i!=fil-1){
			cout<<", ";	
		}
		
		if(i==fil-1){
			cout<<"}, ";
		}
	}
	cout<<"{";
	
	for(j=0;j<col;j++){
		cout<<lit[j];
		
		if(j!=col-1){
			cout<<", ";	
		}
		
		if(j==col-1){
			cout<<"}, Q(0), F, ";
		}
	}
	
	for(i=0;i<fil;i++){		
		if(i==fil-1){
			cout<<"Q("<<i<<"))"<<endl;
		}
	}
	cout<<endl<<"||========================================================||"<<endl;
	system("pause");
	
	
	//MENU
	do{
		system("cls"); m=1;
		cout<<"||========================================================||"<<endl;
		cout<<"||                          MENU                          ||"<<endl;
		cout<<"||========================================================||"<<endl;
		cout<<"||              0.- FINALIZAR EL PROGRAMA                 ||"<<endl;
		cout<<"||              1.- INGRESAR NUEVA GRAMATICA              ||"<<endl;
		cout<<"||========================================================||"<<endl;
		cout<<"   > "; cin>>option;
		
		if(option=="1"){
			
			
			//LIMPIAR EL ARREGLO DE LAS LITERALES.
			for(i=0;i<=contGram;i++){
				gram[i]="";
				if(i==contGram){
					contGram=0;
				}
			}
			system("cls");	
			
			
			//GRAMATICAS QUE PERTENENCEN AL LENGUAJE.
			k=0;
			cout<<"||========================================================||"<<endl;
			cout<<"||                 GRAMATICA DEL LENGUAJE                 ||"<<endl;
			cout<<"||========================================================||"<<endl;
			cout<<"||                TECLEA 'EXIT' PARA SALIR                ||"<<endl;
			cout<<"||========================================================||"<<endl;
			
			do{ 
				do{
					//VALIDA LAS LITERALES CON LAS ENTRADAS.
					validar = false;
					cout<<"   > LITERAL "<<k+1<<": "; cin>>gramInput;
					for(j=0;j<col;j++){
						//cout<<"gramInput = "<<gramInput<<" | lit["<<j<<"] = "<<lit[j]<<endl;
						if((gramInput=="EXIT") && (k==0)){
							gramInput="";
							k=0;
						}else if((gramInput==lit[j]) || (gramInput=="EXIT")){
							validar=true;
							j=col;
						}
					}
				}while(validar == false);
				
				if(gramInput != "EXIT"){
					gram[k] = gramInput;
					contGram++; 
					k++;
				}
			}while(gramInput != "EXIT");
			
			//MUESTA LA GRAMATICA Y LA CANTIDAD DE LITERALES EN LA MISMA.
			system("cls");
			cout<<"||========================================================||"<<endl;
			cout<<"||        4. GRAMATICAS QUE PERTENECEN AL LENGUAJE        ||"<<endl;
			cout<<"||========================================================||"<<endl;
			cout<<endl<<"   > PARA A(1) = ";
			for(k=0;k<contGram;k++){
				cout<<gram[k];
				if(k == (contGram-1)){
					cout<<endl<<endl<<"||========================================================||"<<endl;
					cout<<endl<<"   > CANTIDAD DE LITERALES = "<<contGram<<endl;
					cout<<endl<<"||========================================================||"<<endl;
				}
			}
			
			
			//ORDENAR LAS LITERALES.
			for(i=0;i<contGram;i++){
				for(j=0;j<col;j++){
					if(gram[i]==lit[j]){
						litNum[i] = j;
						//cout<<litNum[i]<<" = "<<j<<endl;
					}
				}	
			}
			
			
			//GRAMATICAS CORRECTAS
			x = 0;
			y = litNum[0];
			
			for(h=0;h<=contGram;h++){
				i = x;
				j = y;		
				
				if(h>0){
					cout<<endl<<"   > F[Q(0), ";
					for(l=0;l<m;l++){
						cout<<gram[l];
					}
					cout<<"] = "<<tab[i][j];
					m++;	
				}
				
				//COMPROBACION DEL RESULTADO
				if((h==contGram) || (tab[i][j]==-1)){
					cout<<endl<<endl<<"   > RESULTADO DE LA ULTIMA FUNCION = Q("<<tab[i][j]<<")"<<endl;	
					cout<<endl<<"||========================================================||"<<endl;
				}
	
				if(h==0){
					x=0;
					y=litNum[h];
					//cout<<endl<<"   > X="<<x<<" - ";
					//cout<<"Y="<<y<<" ";
				}else{
					x = tab[i][j]; 
					y = litNum[h]; 
					if(h<contGram){
						//cout<<"   > X="<<x<<" - ";
						//cout<<"Y="<<y<<" ";	
					}
				}	
				
				//RESULTADO
				if(x==-1){
					if(h==contGram){
						cout<<endl<<"   > PERTENECE AL LENGUAJE, ULTIMA LITERAL = Q(-1)"<<endl;
						cout<<endl<<"||========================================================||"<<endl;			
						break;
					}else if(h!=contGram){
						cout<<endl<<"   > NO PERTENECE AL LENGUAJE"<<endl;
						cout<<endl<<"||========================================================||"<<endl;	
						break;
					}
				}
				
				if(x!=-1){
					if(h==contGram){					
						cout<<endl<<"   > PERTENECE AL LENGUAJE"<<endl;
						cout<<endl<<"||========================================================||"<<endl;
						break;
					}
				}
			}
			system("pause");
		}
	}while(option != "0");
	return 0;
}
