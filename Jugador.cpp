#include <string.h>

class Jugador{
	private:
		string nombre;
		int salario;
		int valor_de_mercado;
	
	public:
		Jugador(int _salario,int _valor_de_mercado, string nombre);
		string getNombre();
		int getSalario();
		int getValorDeMercado();
};

Jugador::	Jugador(int _salario, int _valor_de_mercado, string _nombre){
	nombre = _nombre;
	salario = _salario;
	valor_de_mercado = _valor_de_mercado;
}

Jugador::getNombre(){
	return nombre;
}

Jugador::getSalario(){
	return salario;
}

Jugador::getValorDeMercado(){
	return valor_de_mercado
}
