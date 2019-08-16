#include <fstream>
#include <iostream>
#include <string.h>
#include "Soldado.cpp"
#include "Asalto.cpp"
#include "Soporte.cpp"
#include <stdlib.h>

#include <vector>
#include <bits/stdc++.h>
using namespace std;

int menu();
string token(string, string, int);
void listar(vector<Soldado*>&,vector<Soldado*>&);

int main(){
	int opc =0;
	vector<Soldado*> equipo1;
	vector<Soldado*>equipo2;
	
	int rand1, rand2;
	int cont=1;
	int ataque;
	ofstream escribir;
	do{
		switch(opc=menu()){
			case 1:
				listar(equipo1, equipo2);
				break;
				
			case 2:
				do{
					if(cont%2!=0){
						rand1=rand() % equipo1.size();
						rand2=rand() % equipo2.size();
						if(typeid(*equipo2.at(rand2))==typeid(Asalto) && typeid(*equipo1.at(rand1))==typeid(Asalto)){
							ataque=equipo1.at(rand1)->Ataque("Asalto");
							equipo2.at(rand2)->Defensa(ataque, "Asalto");
						}
						if(typeid(*equipo2.at(rand2))==typeid(Soporte) && typeid(*equipo1.at(rand1))==typeid(Soporte)){
							ataque=equipo1.at(rand1)->Ataque("Soporte");
							equipo2.at(rand2)->Defensa(ataque, "Soporte");
						}
						if(typeid(*equipo2.at(rand2))==typeid(Soporte) && typeid(*equipo1.at(rand1))==typeid(Asalto)){
							ataque=equipo1.at(rand1)->Ataque("Soporte");
							equipo2.at(rand2)->Defensa(ataque, "Asalto");
						}
						if(typeid(*equipo2.at(rand2))==typeid(Asalto) && typeid(*equipo1.at(rand1))==typeid(Soporte)){
							ataque=equipo1.at(rand1)->Ataque("Asalto");
							equipo2.at(rand2)->Defensa(ataque, "Soporte");
						}
						
						for(int i=0; i<equipo2.size();i++){
							if(equipo2.at(i)->getP_vida==0){
								equipo2.erase(equipo2.begin()+i);
							}
						}
					}
					else{
						rand1=rand() % equipo1.size();
						rand2=rand() % equipo2.size();
						if(typeid(*equipo1.at(rand1))==typeid(Asalto) && typeid(*equipo2.at(rand2))==typeid(Asalto)){
							ataque=equipo2.at(rand2)->Ataque("Asalto");
							equipo1.at(rand1)->Defensa(ataque, "Asalto");
						}
						if(typeid(*equipo1.at(rand1))==typeid(Soporte) && typeid(*equipo2.at(rand2))==typeid(Soporte)){
							ataque=equipo2.at(rand2)->Ataque("Soporte");
							equipo1.at(rand1)->Defensa(ataque, "Soporte");
						}
						if(typeid(*equipo1.at(rand1))==typeid(Soporte) && typeid(*equipo2.at(rand2))==typeid(Asalto)){
							ataque=equipo2.at(rand2)->Ataque("Soporte");
							equipo1.at(rand1)->Defensa(ataque, "Asalto");
						}
						if(typeid(*equipo1.at(rand1))==typeid(Asalto) && typeid(*equipo2.at(rand2))==typeid(Soporte)){
							ataque=equipo2.at(rand2)->Ataque("Asalto");
							equipo1.at(rand1)->Defensa(ataque, "Soporte");
						}
						for(int i=0; i<equipo1.size();i++){
							if(equipo1.at(i)->getP_vida==0){
								equipo1.erase(equipo1.begin()+i);
							}
						}
					}
					cont++;
				}while(equipo1.size()!=0 || equipo2.size()!=0);
				escribir.open("./ganados.txt");
				if(equipo1.size()==0){
					escribir<<"Gano equipo 2"<<endl;
					
				}
				else{
					escribir<<"Gano equipo 1"<<endl;
				}
				break;
				
			case 3:
				cout<<"Saliendo"<<endl;
				clear(equipo1);
				clear(equipo2);
				break;
		}
	}while(opc!=3);
	return 0;
}

void clear(vector <Soldado*> x){
			x.clear();
				if(x.empty()){
					x.clear();
				}
		}

int menu()
{
    while (true)
    {
        cout << "MENU" << endl
             << "1.- Listar" << endl
             << "2.- Iniciar Simulacion" << endl
             << "3.- Salir" << endl;
        cout << "Ingrese una opcion: ";
        int opcion = 0;
        cin >> opcion;
        if (opcion >= 1 && opcion <= 3)
        {
            return opcion;
        }
        else
        {

            cout << "La opcion elegida no es valida, ingrese un valor entre 1 y 3" << endl;
        }
    } //end del while
    return 0;
}

void listar(vector<Soldado*>& e1,vector<Soldado*>& e2){
	ifstream doc("./prueba.txt");
	string line="";
	string tipo,nombre,p_vida,p_fuerza, velocidad, fuerza_extra, blindaje, camuflaje;
	int p_vida2,p_fuerza2, velocidad2, fuerza_extra2, blindaje2, camuflaje2;
	Soporte* sop;
	Asalto* asa;
	stringstream convert;
	
	cout<<"Equipo# 1:"<<endl;
	while(doc.get()!='&'){
		doc.unget();
		getline(doc,tipo,'/');
		cout<<"Tipo: "<<tipo<<endl;
		getline(doc,nombre,'/');
		cout<<"Nombre: "<<nombre<<endl;
		getline(doc,p_vida,'/');
		cout<<"Puntos de Vida: "<<p_vida<<endl;
		convert << p_vida;
		convert >> p_vida2;
		convert.str("");
		convert.clear();
		getline(doc,p_fuerza,'/');
		cout<<"Puntos de Fuerza: "<<p_fuerza<<endl;
		convert << p_fuerza;
		convert >> p_fuerza2;
		convert.str("");
		convert.clear();
		if(tipo=="Asalto"){
			getline(doc,velocidad,'/');
			cout<<"Velocidad: "<<velocidad<<endl;
			convert << velocidad;
			convert >> velocidad2;
			convert.str("");
			convert.clear();
			getline(doc,fuerza_extra,'/');
			cout<<"Fuerza Extra: "<<fuerza_extra<<endl;
			cout<<endl;
			convert << fuerza_extra;
			convert >> fuerza_extra2;
			convert.str("");
			convert.clear();
			asa=new Asalto(nombre, p_vida2, p_fuerza2, velocidad2, fuerza_extra2);
			e1.push_back(asa);
			
		}
		else{
			getline(doc,blindaje,'/');
			cout<<"Blindaje: "<<blindaje<<endl;
			convert << blindaje;
			convert >> blindaje2;
			convert.str("");
			convert.clear();
			getline(doc,camuflaje,'/');
			cout<<"Camuflaje: "<<camuflaje<<endl;
			cout<<endl;
			convert << camuflaje;
			convert >> camuflaje2;
			convert.str("");
			convert.clear();
			sop=new Soporte(nombre, p_vida2, p_fuerza2, blindaje2, camuflaje2);
			e1.push_back(sop);
		}
	}
	cout<<endl;
	cout<<endl;
	cout<<endl;
	
	cout<<"Equipo# 2:"<<endl;
	doc.get();
	while(!doc.eof()){
		getline(doc,tipo,'/');
		cout<<"Tipo: "<<tipo<<endl;
		getline(doc,nombre,'/');
		cout<<"Nombre: "<<nombre<<endl;
		getline(doc,p_vida,'/');
		cout<<"Puntos de Vida: "<<p_vida<<endl;
		convert << p_vida;
		convert >> p_vida2;
		convert.str("");
		convert.clear();
		getline(doc,p_fuerza,'/');
		cout<<"Puntos de Fuerza: "<<p_fuerza<<endl;
		convert << p_fuerza;
		convert >> p_fuerza2;
		convert.str("");
		convert.clear();
		if(tipo=="Asalto"){
			getline(doc,velocidad,'/');
			cout<<"Velocidad: "<<velocidad<<endl;
			convert << velocidad;
			convert >> velocidad2;
			convert.str("");
			convert.clear();
			getline(doc,fuerza_extra,'/');
			cout<<"Fuerza Extra: "<<fuerza_extra<<endl;
			cout<<endl;
			convert << fuerza_extra;
			convert >> fuerza_extra2;
			convert.str("");
			convert.clear();
			asa=new Asalto(nombre, p_vida2, p_fuerza2, velocidad2, fuerza_extra2);
			e2.push_back(asa);
			
		}
		else{
			getline(doc,blindaje,'/');
			cout<<"Blindaje: "<<blindaje<<endl;
			convert << blindaje;
			convert >> blindaje2;
			convert.str("");
			convert.clear();
			getline(doc,camuflaje,'/');
			cout<<"Camuflaje: "<<camuflaje<<endl;
			cout<<endl;
			convert << camuflaje;
			convert >> camuflaje2;
			convert.str("");
			convert.clear();
			sop=new Soporte(nombre, p_vida2, p_fuerza2, blindaje2, camuflaje2);
			e2.push_back(sop);
		}
	}
	doc.close();
	
	/*for(int i=0; i<e1.size(); i++){
		cout<<e1.at(i)->getNombre()<<endl;
	}
	cout<<endl;
	cout<<"2"<<endl;
	e2.erase(e2.begin()+(e2.size()-1));
	for(int i=0; i<e2.size(); i++){
		cout<<i<<endl;
		cout<<e2.at(i)->getNombre()<<endl;
	}*/
	
	//cont=0;
}

string token(string cadena, string divisor, int pos){
       if(cadena.size()>0){
         char oracion[cadena.size()]; 
         for (int i=0;i<=cadena.size();i++)
         {
               oracion[i]=cadena[i];
         }                    
         char *ptrtoken; 
         int num=1;
         const char* d=divisor.c_str();
         ptrtoken = strtok(oracion , d);             
         while(ptrtoken){
             if(num==pos){ 
                return ptrtoken;                    
             }                 
             ptrtoken = strtok(NULL, d);
             num++;
         }
         return "";
       }else{
             return "";
       }
}
