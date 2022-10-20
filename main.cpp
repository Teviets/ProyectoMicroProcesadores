/**
 * Universidad del Valle de Guatemala
 * Proyecto 2
 * Programa realizado el 10/10/2022
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
#include <vector>

using namespace std;     // Usar estandar de c++ para flujos de IN y OUT

// Variables Globales
int numThreads;
int opcion, opcionMJ, opcionME, opcionEq1;

/**
 * Los arrays de dos dimensiones están construídos de la siguiente manera:
 * En la primera dimensión se encuentran los arrays cada uno de los equipos.
 * En el segundo array se encuentran la informacion de cada equipo:
 * [0] Nombre del equipo, [1] Limite salarial, [2] Ingresos, [3] Presupuesto 
 */

string arrayEquipos [4][4]=
        {
                {"Real Madrid","683000000","769000000","722000000", },
                {"Fc Barcelona","656000000 ","631000000","275000000"},
                {"Atletico de Madrid","341000000","540000000","87000000"},
                {"Sevilla FC","199000000","242000000","22000000"}
        };

/**
 * Los arrays de dos dimensiones están construídos de la siguiente manera:
 * En la primera dimensión se encuentran los arrays cada uno de los jugadores por equipo.
 * En el segundo array se encuentran la informacion de cada jugador:
 * [0] Nombre del jugador, [1] Valor de mercado, [2] Salario anual
 */

string arrayBarcelona [16][3]=
        {
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

string arrayRealMadrid [16][3]=
        {
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

string arrayAtleticoMadrid [16][3]=
        {
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

string arraySevilla [15][3]=
        {
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
	cout << "\n1. Edicion de equipos\n";
	cout << "2. Edicion de jugadores\n";
	cout << "3. Salir\n";
}

/**
* Impresion menu Jugadores
*/
void impresionMenuJugadores() {
	cout << "\n1. Ingresar Jugadores nuevos\n";
	cout << "2. Mover Jugador existente\n";
	cout << "3. Ver todos los jugadores\n";
	cout << "4. Jugadores por equipo\n";
	cout << "5. Regresar\n";
}

/**
* Impresion Menu equipos 
*/
void impresionMenuEquipos(){
	cout << "\n1. Ver equipos disponibles\n";
	cout << "2. Cambiar limite salarial\n";
	cout << "3. Verificacion de limite salarial restante\n";
	cout << "4. Cambiar presupuesto de fichaje\n";
	cout << "5. Regresar\n";
}
/**
*  Esta funcion no retorna nada solo imprime todos los equipos disponibles
*/
void mostrarEquipos(){
    cout << ".- " << arrayEquipos[0][0] << "\n";
    cout << ".- " << arrayEquipos[1][0] << "\n";
    cout << ".- " << arrayEquipos[2][0] << "\n";
    cout << ".- " << arrayEquipos[3][0] << "\n";
}

/**
*  Esta funcion imprime los equipos a escoger
*/
void Escoger_equipo(){
	
    cout << "Ingrese el equipo al que desea editar:      "<< "\n";
    cout << "1. Fc Barcelona"<< "\n";        
	cout << "2. Real Madrid FC"<< "\n";
    cout << "3. Atletico de Madrid "<< "\n";
    cout << "4. Sevilla FC"<< "\n"; 

                
}

/**
*  Esta funcion imprime cada uno de los jugadores por equipo, con todos los datos reelevantes sobre cada jugador
*/
void mostrarJugadoresXEquipo(void args){
	cout << "-----------------Fc Barcelona----------------\n";
	for (int jg = 0; jg<16; jg++){
		cout << jg << ".- " << arrayBarcelona[jg][0] << "\n  -Valor de Mercado: €" << arrayBarcelona[jg][1] << "\n  -Salario anual: €" << arrayBarcelona[jg][2] << "\n";
	}

        cout << "-----------------Real Madrid FC----------------\n";
	for (int jg = 0; jg<16; jg++){
		cout << jg << ".- " << arrayRealMadrid[jg][0] << "\n  -Valor de Mercado: €" << arrayRealMadrid[jg][1] << "\n  -Salario anual: €" << arrayRealMadrid[jg][2] << "\n";
	}

        cout << "-----------------Atletico de Madrid----------------\n";
        for (int jg = 0; jg<16; jg++){
                cout << jg << ".- " << arrayAtleticoMadrid[jg][0] << "\n  -Valor de Mercado: €" << arrayAtleticoMadrid[jg][1] << "\n  -Salario anual: €" << arrayAtleticoMadrid[jg][2] << "\n";
        }

        cout << "-----------------Sevilla FC----------------\n";
        for (int jg = 0; jg<15; jg++){
                cout << jg << ".- " << arraySevilla[jg][0] << "\n  -Valor de Mercado: €" << arraySevilla[jg][1] << "\n  -Salario anual: €" << arraySevilla[jg][2] << "\n";
        }
}

/**
*  Esta funcion imprime todos los jugadores en la base de datos
*/
void todosdNuestroPlayes(void args){
	for (int jg = 0; jg<16; jg++){
		cout << "- " << arrayBarcelona[jg][0] << "\n  -Valor de Mercado: €" << arrayBarcelona[jg][1] << "\n  -Salario anual: €" << arrayBarcelona[jg][2] << "\n";
	}
	for (int jg = 0; jg<16; jg++){
		cout << "- " << arrayRealMadrid[jg][0] << "\n  -Valor de Mercado: €" << arrayRealMadrid[jg][1] << "\n  -Salario anual: €" << arrayRealMadrid[jg][2] << "\n";
	}
	for (int jg = 0; jg<16; jg++){
		cout <<"- " << arrayAtleticoMadrid[jg][0] << "\n  -Valor de Mercado: €" << arrayAtleticoMadrid[jg][1] << "\n  -Salario anual: €" << arrayAtleticoMadrid[jg][2] << "\n";
	}
	for (int jg = 0; jg<15; jg++){
		cout << "- " << arraySevilla[jg][0] << "\n  -Valor de Mercado: €" << arraySevilla[jg][1] << "\n  -Salario anual: €" << arraySevilla[jg][2] << "\n";
	}
}

// Lo hago yo
/**
*  Esta funcion calcula lo restante del limite salarial de cada equipo
*/
void Limite_Restante (){
	

}


/**
*  Esta funcion reasigna el limite salarial en base a cada equipo
*/
void Limite_Salarial(){
    string New_Limit;
    cout << "Ingrese el nuevo limite Salarial que desea colocar:  ";
    cin >> New_Limit; 
        
    switch ((int)opcionEq1){
		case 1:   // Barcelona
            arrayEquipos[0][1] = New_Limit;
            break;
		case 2:  //Real madrid 
            arrayEquipos[1][1] = New_Limit;
			break;
		case 3: // Atletico de Madrid
            arrayEquipos[2][1] = New_Limit;
            break;
		case 4:  //Sevilla
            arrayEquipos[3][1] = New_Limit;
            break;
	}
}

void nuevoPresupuesto(){
    string New_PresupuestoFCB;
    string New_PresupuestoRM;
    string New_PresupuestoATL;
    string New_PresupuestoSEV;
    Escoger_equipo();
    cin >> opcionEq1;

    switch ((int)opcionEq1){
	    case 1: // Barcelona
            cout << "Ingrese el nuevo presupuesto que desea colocar: ";
            cin >> New_PresupuestoFCB;
            if (New_PresupuestoFCB <= arrayEquipos[1][2]){
                    arrayEquipos[1][3] = New_PresupuestoFCB;
                    cout << "Nuevo presupuesto agregado\n";
            }
            else{
                    cout << "El presupesto no puede ser mayor a los ingresos\n";
            }          
	    	break;
	    
	    case 2:  //Real madrid 
            cout << "Ingrese el nuevo presupuesto que desea colocar: ";
            cin >> New_PresupuestoRM;
            
            if (New_PresupuestoRM <= arrayEquipos[0][2]){
                    arrayEquipos[0][3] = New_PresupuestoRM;
                    cout << "Nuevo presupuesto agregado\n";
            }
            else{
                    cout << "El presupesto no puede ser mayor a los ingresos\n";
            }
                    
            break;

        case 3: // Atletico de Madrid 
            cout << "Ingrese el nuevo presupuesto que desea colocar: ";
            cin >> New_PresupuestoATL;

            if (New_PresupuestoATL <= arrayEquipos[2][2]){
                    arrayEquipos[2][3] = New_PresupuestoATL;
                    cout << "Nuevo presupuesto agregado\n";
            }
            else{
                    cout << "El presupesto no puede ser mayor a los ingresos\n";
            }    
            
    		break;

        case 4:  //Sevilla
            cout << "Ingrese el nuevo presupuesto que desea colocar: ";
            cin >> New_PresupuestoSEV;
           
            if (New_PresupuestoSEV <= arrayEquipos[3][2]){
                    arrayEquipos[3][3] = New_PresupuestoSEV;
                    cout << "Nuevo presupuesto agregado\n";
            }
            else{
                    cout << "El presupesto no puede ser mayor a los ingresos\n";
            }      
                
        	break;
    } 
}


/**
*  En esta funcion se realiza el manejo del menu de equipo
*/
void manejoEquipos(){
        bool flagME = true;
        long i;
	while(flagME){
		impresionMenuEquipos();
		cin >> opcionME;
		
		switch ((int)opcionME){
			case 1:
                mostrarEquipos();
				break;
			case 2:
                Escoger_equipo();
                cin >> opcionEq1;
                Limite_Salarial();
                break;

			case 3:// Yo
				break;
			case 4:
				nuevoPresupuesto();
				break;
            case 5:
                flagME = false;
				break;
		}
	}
}

/**
*  En esta funcion se realiza el manejo de 
*/
void manejoJugadores(){
        bool flagMJ = true;
        long i;
	while (flagMJ){
		impresionMenuJugadores();
		cin >> opcionMJ;
		
		switch ((int)opcionMJ){
			case 1:// Yo
				break;
			case 2: // Yo
				break;
			case 3:
				pthread_t tid;
                pthread_attr_t attr;
                pthread_attr_init(&attr);
                pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

                void *exit_value;

                pthread_create(&tid, &attr, todosdNuestroPlayes, (void*)i);
                pthread_join(tid, &exit_value);
                
                pthread_attr_destroy(&attr);
				break;
			case 4:
				pthread_t tid2;
                pthread_attr_t attr2;
                pthread_attr_init(&attr2);
                pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

                void *exit_value2;

                pthread_create(&tid2, &attr2, mostrarJugadoresXEquipo, (void*)i);
                pthread_join(tid2, &exit_value2);
                
                pthread_attr_destroy(&attr2);
				break;
                        case 5:
                                flagMJ = false;
				break;
		}
	}
}


int main(int nNumberofArgs, char* pszArgs[]) {
	
	bool flag = true;
	// Ciclo para manejo general del programa
	while (flag){
		// Se imprime el primer menu
		impresionMenuInicial();
		cin >> opcion;
		
		switch ((int)opcion){
			case 1:
				manejoEquipos();
				break;
			case 2:
				manejoJugadores();
				break;
			case 3:
				flag = false;
				break;
		}
	}

        /*
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

	
        */
       cout << endl;
}
