#include <stdlib.h>
#include <iostream>
#include <string.h>

class Jugador{
    private:
        char nombre[25];
        int salario;
        int valor_de_mercado;
    
    public:
        Jugador(int _salario,int _valor_de_mercado,char _nombre[25]){
		    for(int i = 0;i<sizeof(_nombre);i++){
		    	nombre[i] = _nombre[i];
			}
		    salario = _salario;
		    valor_de_mercado = _valor_de_mercado;
		}	            
        
        char* getNombre(){
			return nombre;
		}
        int getSalario(){
			return salario;
		}
        int getValorMercado(){
			return valor_de_mercado;
		}
};


