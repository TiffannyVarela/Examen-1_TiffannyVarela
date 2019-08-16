#include "Soldado.cpp"

#ifndef SOPORTE_CPP 
#define SOPORTE_CPP


class Soporte : public Soldado{
	protected:
		int blindaje,camuflaje;
		
	public:
		Soporte():Soldado(){
		}
		
		Soporte(string nombre, int p_vida, int p_fuerza,int blindaje, int camuflaje): Soldado(nombre, p_vida, p_fuerza){
			this->blindaje=blindaje;
			this->camuflaje=camuflaje;
		}
		
		int Ataque(string tipo){
			int ataque;
			if(tipo=="Asalto"){
				ataque = p_fuerza*(15+camuflaje);
			}
			else{
				ataque = p_fuerza*10;
			}
			return ataque;
		}
		
		void Defensa(int x, string tipo){
			if(tipo=="Asalto"){
				p_vida=p_vida-(x/(blindaje*2));
			}
			else{
				p_vida=p_vida-x;
			}
		}
		
		int getBlindaje(){
			return this->blindaje=blindaje;
		}
		
		int getCamuflaje(){
			return this->camuflaje=camuflaje;
		}
		
};

#endif
