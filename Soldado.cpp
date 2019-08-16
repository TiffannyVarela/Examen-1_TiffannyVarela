#include <string.h>
#include <iostream>
#include <typeinfo>
using namespace std;


#ifndef SOLDADO_CPP
#define SOLDADO_CPP

class Soldado{
	protected:
		string nombre;
		int p_vida, p_fuerza;
		
	public:
		Soldado(){
		}
		
		Soldado(string nombre, int p_vida, int p_fuerza){
			this->nombre=nombre;
			this->p_vida=p_vida;
			this->p_fuerza=p_fuerza;
		}
		
		int getP_vida(){
			return this->p_vida=p_vida;
		}
		
		int getP_fuerza(){
			return this->p_vida=p_fuerza;
		}
			
			
		string getNombre(){
			return this->nombre.assign(nombre);
		}
		
		void setP_vida(int p_vida){
			this->p_vida=p_vida;
		}
		
			
		virtual int Ataque(string)=0;
		virtual void Defensa(int, string)=0;
	
};

#endif
