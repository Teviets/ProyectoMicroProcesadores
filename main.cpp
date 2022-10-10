/**
 * Universidad del Valle de Guatemala
 * Laboratorio 4 parte 2
 * Programa realizado el 06/09/2022
 * Integrantes:
 * Diego Valdez - 21328
 * Manuel Rodas - 21509
 * Sebastian Estrada - 21405
 * Sebastán Solorzano - 21826
 */

// imports
#include <cstdio>
#include <cstdlib>       //librerias para poder usar funciones especificas
#include <iostream>
#include <cmath>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

using namespace std;     // Usar estandar de c++ para flujos de IN y OUT

// Variables Globales
int numThreads;
int opcion, opcionMJ, opcionME;

/**
 * Los arrays de dos dimensiones están construídos de la siguiente manera:
 * En la primera dimensión se encuentran los arrays cada uno de los equipos.
 * En el segundo array se encuentran la informacion de cada equipo:
 * [0] Nombre del equipo, [1] Presupuesto, [2] Limite Salarial
 */

string arrayEquipos [4][3]= {
	{"Barcelona","0","0"},
	{"Real Madrid","0","0"},
	{"Atletico de Madrid","0","0"},
	{"Sevilla","0","0"},
};

/**
 * Los arrays de dos dimensiones están construídos de la siguiente manera:
 * En la primera dimensión se encuentran los arrays cada uno de los jugadores por equipo.
 * En el segundo array se encuentran la informacion de cada jugador:
 * [0] Nombre del jugador, [1] Valor de mercado, [2] Salario anual
 */

string arrayBarcelona [16][3]= {
	{"Marc-Andre Ter Stegen","30000000","7000000"},
	{"Ronald Araujo","60000000","7500000"},
	{"Jules Kounde","60000000","6000000"},
	{"Andreas Christensen","35000000","6000000"},
	{"Eric Garcia","18000000","3076320"},
	{"Marcos Alonso","12000000","3000000"},
	{"Alejandro Balde","8000000","211120"},
	{"Sergio Busquet","9000000","11500000"},
	{"Pedri Gonzales","90000000","4500000"},
	{"Pablo Gavi","70000000","132700"},
	{"Frenkie de Jong","60000000","7000000"},
	{"Franck Kessie","45000000","6500000"},
	{"Ansu Fati","60000000","6000000"},
	{"Ousmane Dembele","50000000","7000000"},
	{"Raphinha","50000000","6000000"},
	{"Robert Lewandowski","45000000","9000000"}
};

string arrayRealMadrid [16][3]= {
	{"Thibaut Courtois","60000000","30000000"},
	{"Eder Militao","60000000","9000000"},
	{"David Alaba","55000000","21000000"},
	{"Antonio Rudiger","40000000","18000000"},
	{"Ferlan Mendy","40000000","9000000"},
	{"Daniel Carvajal","18000000","9000000"},
	{"Nacho Fernandez","7000000","7000000"},
	{"Federico Valverde","8000000","4000000"},
	{"Eduardo Camavinga","55000000","1000000"},
	{"Toni Kroos","20000000","18000000"},
	{"Luka Modric","10000000","16000000"},
	{"Vinicius Junior","120000000","20000000"},
	{"Eden Hazard","12000000","30000000"},
	{"Rodrygo","70000000","7000000"},
	{"Marco Asensio","35000000","7000000"},
	{"Karim Benzema","30000000","16000000"}
};

string arrayAtleticoMadrid [16][3]= {
	{"Jan Oblack","40000000","15000000"},
	{"Jose Maria Gimenez","45000000","5000000"},
	{"Mario Hermoso","18000000","8000000"},
	{"Felipe","6000000","7000000"},
	{"Stefan Savic","14000000","4000000"},
	{"Axel Witsel","5000000","9000000"},
	{"Marcos Llorente","40000000","5000000"},
	{"Rodrigo de Paul","35000000","2000000"},
	{"Koke","20000000","15000000"},
	{"Saul Ñiguez","20000000","11000000"},
	{"Thomas Lemar","35000000","6000000"},
	{"Yannick Carrasco","40000000","8000000"},
	{"Angel Correa","40000000","5000000"},
	{"Joao Felix","70000000","9000000"},
	{"Antoine Griezmann","35000000","21000000"},
	{"Alvaro Morata","25000000","10000000"}
};

string arraySevilla [15][3]= {
	{"Bono","18000000","2000000"},
	{"Marcos Acuna","18000000","3000000"},
	{"Gonzalo Montiel","14000000","1000000"},
	{"Jesus Navas","3000000","4000000"},
	{"Fernando","4000000","5000000"},
	{"Joan Jordan","18000000","2000000"},
	{"Oliver Torres","8000000","2000000"},
	{"Ivan Rakitic","7000000","6000000"},
	{"Thomas Delaney","7000000","3000000"},
	{"Papu Gomez","6000000","6000000"},
	{"Tecatito","18000000","2000000"},
	{"Erik Lamela","160000000","3000000"},
	{"Suso","10000000","2000000"},
	{"Youssef En-Nesyri","20000000","3000000"},
	{"Rafa Mir","16000000","2000000"}
};

/**
* Impresion para escoger manejo de equipos o jugadores
*/
void impresionMenuInicial(){
	cout << "1. Edicion de equipos\n";
	cout << "2. Edicion de jugadores\n";
	cout << "3. Salir\n";
}

/**
* Impresion menu Jugadores
*/
void impresionMenuJugadores() {
	cout << "1. Ingresar un Jugador nuevo\n";
	cout << "2. Mover Jugador existente\n";
	cout << "3. Ver todos los jugadores\n";
	cout << "4. Jugadores por equipo\n";
	cout << "5. Regresar\n";
}
/**
* Impresion Menu equipos 
*/
void impresionMenuEquipos(){
	cout << "1. Ver equipos disponibles\n";
	cout << "2. Cambiar limite salarial\n";
	cout << "3. Verificacion de limite salarial restante\n";
	cout << "4. Cambiar presupuesto de fichaje\n";
	cout << "5. Regresar\n";
}

void manejoEquipos(){
	while(0 < opcionME < 5){
		impresionMenuEquipos();
		cin >> opcionME;
		
		switch (opcionME){
			
		}
	}
}

void manejoJugadores(){
	while (0 < opcionMJ < 5){
		impresionMenuJugadores();
		cin >> opcionMJ;
	}
}


int main(int nNumberofArgs, char* pszArgs[]) {
	
	// Ciclo para manejo general del programa
	while (0 < opcion < 3){
		// Se imprime el primer menu
		impresionMenuInicial();
		cin >> opcion;
		
		switch (opcion){
			case 1:
				
				break;
			case 2:
				break;
		}
	}

	
	
	
	

	string nameEquipo;
	string nameJugador;
	int presupuesto;
	int salarioJugador;
	int salario;
	int valJugador;
	int limSalarial;

	cout << "Ingrese el nombre del jugador: ";
	cin >> nameJugador;

	cout << "Ingrese el salario del jugador: ";
	cin >> salarioJugador;

	cout << "Ingrese el nuevo presupuesto: ";
	cin >> presupuesto;

	cout << "Ingrese el nuevo salario del jugador: ";
	cin >> salario;

	cout << "Ingrese el nombre del equipo: ";
	cin >> nameEquipo;

	cout << endl;

}
