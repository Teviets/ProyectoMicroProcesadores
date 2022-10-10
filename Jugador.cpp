#include <string.h>
#include <stdlib.h>
#include <iostream>

class Jugador{
    private:
        string nombre();
        int salario;
        int valor_de_mercado;
    
    public:
        Jugador(string _nombre,int _salario,int _valor_de_mercado){
		    nombre = _nombre;
		    salario = _salario;
		    valor_de_mercado = _valor_de_mercado;
		}	            
        
        string getNombre(){
			return nombre;
		}
        int getSalario(){
			return salario;
		}
        int getValorMercado(){
			return valor_de_mercado
		}
};


