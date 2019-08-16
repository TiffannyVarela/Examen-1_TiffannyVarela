
#include "Soldado.cpp"

#ifndef ASALTO_CPP 
#define ASALTO_CPP

class Asalto : public Soldado{
	protected:
		int velocidad, fuerza_extra;
		
	public:
		Asalto():Soldado(){
		}
		
		Asalto(string nombre, int p_vida, int p_fuerza,int velocidad, int fuerza_extra): Soldado(nombre, p_vida, p_fuerza){
			this->velocidad=velocidad;
			this->fuerza_extra=fuerza_extra;
		}
		
		int Ataque(string tipo){
			int ataque=0;
			if(tipo=="Asalto"){
				ataque=p_fuerza*10;
			}
			else{
				ataque=p_fuerza*(10+(velocidad*2));
			}
			return ataque;
		}
		
		void Defensa(int x, string tipo){
			if(tipo=="Asalto"){
				p_vida=p_vida-x;
			}
			else{
				p_vida=p_vida-(x/fuerza_extra);
			}
		}
		
};

#endif
