/*
Adrian Garcia Lopez
A01351166
	
Proyecto final
*/

#include "Libro.h"
#include "Disco.h"
#include "Software.h"
#include "Reserva.h"
#include <fstream>

int main() {

	//Para almacenar materiales y los distintos tipos
	Material *Materiales[20];

	//Para almacenar Reservaciones 
	Reserva Reservaciones[50];
	
	//Declaramos los atchivos
	ifstream ArchivoMaterial;			//Archivo de Materiales
	ifstream ArchivoReservaciones;		//Archivo de Reservaciones
	
	//Datos de clase Material
	int iIdMaterial;	//Tambien se usa en reservaciones
	string sTitulo;
	char cTipo;
	
	//Datos de clase Libro
	int iNumPag;
	string sAutor;

	//Datos de clase Disco
	int iDuracion;

	//Datos de clase Software
	string sSistemaOperativo;

	//Fecha de la reservacion y del final de esta
	Fecha fecha();

	//Datos de la clase reservacion
	int iIdCliente;

	//Dias en los que un material puede ser rentado
	int iDiasPrestamo;

	//Cantidad de Materiales y Reservaciones
	int iNumMate=0;
	int iNumRese=0;

	//Contadores
	int i=0;
	int j=0;

	//Accion que el usuario desea realizar en el menu
	char Opcion;	

	//Opcion de ID de Material
	int iOpcion;

	//Dia, Mes y Anio 
	int iDD, iMM, iAA;

	//Valida que el material y la fecha que el usuario ingere exista
	bool Valida;

	//Abrimos los archivos
	ArchivoMaterial.open("materiales.txt");
	ArchivoReservaciones.open("reserva.txt");

	//Leemos mientras haya datos en iIdMaterial
	while (ArchivoMaterial >> iIdMaterial) {
		
		//Obtenemos Titulo y Tipo de material 
		ArchivoMaterial >> sTitulo;
		ArchivoMaterial >> cTipo;

		//Los datos se obtienen dependiendo de su tipo
		switch (cTipo) {
			case 'L':	//Tipo Libro
				//Obtenemos Numero de pagina y Autor
				ArchivoMaterial >> iNumPag;
				ArchivoMaterial >> sAutor;
				
				//Creamos nuevo objeto de tipo Libro
				Materiales[iNumMate] = new Libro(iIdMaterial, sTitulo, cTipo, iNumPag, sAutor);
			break;

			case 'D':	//Tipo Disco
				//Obtenemos Duracion
				ArchivoMaterial >> iDuracion;

				//Creamos nuevo objeto de tipo Disco
				Materiales[iNumMate] = new Disco(iIdMaterial, sTitulo, cTipo, iDuracion);
			break;

			case 'S':	//Tipo Software
				//Obtenemos nombre del Sistema Operativo
				ArchivoMaterial >> sSistemaOperativo;
				
				//Creamos nuevo objeto de tipo Software
				Materiales[iNumMate] = new Software(iIdMaterial, sTitulo, cTipo, sSistemaOperativo);
			break;
		}

		iNumMate++;	//Aumentamos la cantidad de Materiales
	}
	
	while (ArchivoReservaciones >> iDD) {
		
		//Obtenemos Meses, Anios, ID de Material y de Cliente
		ArchivoReservaciones >> iMM;
		ArchivoReservaciones >> iAA;
		ArchivoReservaciones >> iIdMaterial;
		ArchivoReservaciones >> iIdCliente;

		//Modificamos los datos
		Fecha F1(iDD, iMM, iAA);
		
		Reservaciones[iNumRese].setFechaReserva(F1);
		Reservaciones[iNumRese].setIdMaterial(iIdMaterial);
		Reservaciones[iNumRese].setIdCliente(iIdCliente);

		iNumRese++;	//Aumentamos 1 al contador
	}

	do { //Se repite mientras el usuario no de a f

		cout << "MENU" << endl;
		cout << "a) Consultar la lista de Materiales \n";
		cout << "b) Consultar la lista de reservaciones \n";
		cout << "c) Consultar las reservaciones de un material \n";
		cout << "d) Consular las reservaciones de una fecha \n";
		cout << "e) Hacer una reservacion \n";
		cout << "f) Terminar \n";

		do {	//Valiadmos que el usuario ingrese una opcion correcta
			
			cout << "Opcion: ";
			cin >> Opcion;

			//Si no esta dentro de las opciones, el programa vuelve a pedirla
			if (Opcion > 'f') {
				cout << "Por favor introduce una opcion valida \n";
			}
		} while (Opcion > 'f');

		//Desplegamos doble espacio por estetica		
		cout << "\n\n";

		//Realizamos la accion que el usuario solicito
		switch (Opcion) {

			//Consultar la lista de Materiales
			case 'a' :

				//Desplegamos la lista de Materiales en la pantalla
				for (i=0; i<iNumMate; i++) {
					Materiales[i]->muestra();
				}

				cout << endl;	//Terminamos linea por estetica
			break;

			//Consultar la lista de reservaciones
			case 'b' :

				//Desplegamos la lista de Reservaciones en la pantalla
				for (i=0; i<iNumRese; i++) {
					Reservaciones[i].muestraReserva();	
				}

				cout << endl;	//Terminamos linea por estetica 
			break;	

			//Consultar las reservaciones de un material
			case 'c' : 

				cout << "Inserta el ID de un Material: ";
				cin >> iOpcion;

				//Buscamos en todas las reservaciones
				for (i=0; i<iNumRese; i++) {
					
					//Si una reservacion es igual al ID dado
					if (Reservaciones[i].getIdMaterial() == iOpcion) {
						Reservaciones[i].muestraReserva();		
					}
				}

				cout << endl;	//Terminamos linea por estetica
			break;	
		
			//Consultar las reservaciones de una fecha
			case 'd' : {
				
				//Pedimos la fecha 
				cout << "Inserta una fecha en formato DD MM AAAA: ";
				cin >> iDD;
				cin >> iMM;
				cin >> iAA;
	
				//Nuevo objeto fecha
				Fecha NuevaFecha(iDD, iMM, iAA);

				//Indice donde se encuentra el ID del material en el Arreglo Material
				int iIndex;

				//Buscamos en todas las reservaciones
				for(i=0; i<iNumRese; i++) {

					//Si una reservacion es igual a la fecha dada
					if (Reservaciones[i].getFechaReserva() == NuevaFecha ){

						//Buscamos su ID
						for (j=0; j<iNumMate; j++) {
							if (Reservaciones[i].getIdMaterial() == Materiales[j]->getIdMaterial()) {
								iIndex = j;
							}
						}

						//Si la fecha esta entre la reservacion
						if (Reservaciones[i].getFechaReserva()<=NuevaFecha && Reservaciones[i].getFechaReserva()+Materiales[iIndex]->diasPrestamo()>=NuevaFecha) {

							//Sacamos el numero de dias que se puede trestar el material
							int iAdd = Materiales[iIndex]->diasPrestamo();
							
							//La desplegamos
							Reservaciones[i].muestraReserva();
							
						}

						//Si no pedimos otra fecha
						else {
							cout << "Por favor introduce una fecha valida" << endl;
						}
					}
				} 

				cout << endl;	//Terminamos linea por estetica
			break; }
			
			//Hacer una reservacion
			case 'e' : {
				
				//Pedimos ID de cliente	
				cout << "Inserta tu ID de cliente: ";
				cin >> iIdCliente;
				
				//Asumimos que el material no se encuentra
				Valida = false;

				do {	//Validamos que el usuario inserte un ID correcto

					//Pedimos ID de material
					cout << "Inserta el ID del material: ";
					cin >> iIdMaterial;

					//Buscanos en todos los materiales
					for (i=0; i<iNumMate; i++) {

						//Si un material es igual al ID del material dado
						if (Materiales[i]->getIdMaterial() == iIdMaterial) {

							//Validamos que el material exista
							Valida = true;
						}
					}

					//Si no se encontro el ID, despliega este mensaje
					if (Valida == false) {
						cout << endl << "Inserta un ID correcto\n\n";
					}

				} while (Valida == false);

				//Asumiremos que la fecha no esta ocupada
				Valida = false;

				//Preguntamos al usuario una fecha
				cout << "Inserta la fecha de tu reservacion en formato DD MM AAAA: ";
				cin >> iDD;
				cin >> iMM;
				cin >> iAA;
				
				Fecha NewFecha(iDD, iMM, iAA);

				//Buscamos que el material no este ocupado
				for (i=0; i<iNumRese; i++) {		
					if (NewFecha == Reservaciones[i].getFechaReserva() && Reservaciones[i].getIdMaterial() == iIdMaterial) {		
						Valida = true;
					}
				}

				if (Valida == false) {
					cout << "Material reservado" << endl;
					//Asignamos valores a las reservaciones
					Reservaciones[iNumRese].setFechaReserva(NewFecha);
					Reservaciones[iNumRese].setIdMaterial(iIdMaterial);
					Reservaciones[iNumRese].setIdCliente(iIdCliente);

					//Aumentamos la cantidad de reservaciones
					iNumRese++;
				}

				//Si esta disponible lo registramos
				if (Valida == true) {
					cout << "El material no se encuentra disponible" << endl;
				}

				cout << endl;	//Terminamos linea por estetica
			break; }
				
			//Terminar	
			case 'f' : 

				//Informamos al usuario que el programa ha terminado
				cout << "Programa Terminado \n";

				//Cerramos ambos archivos
				ArchivoMaterial.close();
				ArchivoReservaciones.close();

				//Definimos nuevo archivo para poner las reservas
				ofstream NuevasReservas;
		
				//Abrimos reservas
				NuevasReservas.open("reserva.txt");
				
				//Colocamos datos en el archivo reservas 
				for (i=0; i<iNumRese; i++) {
					NuevasReservas << Reservaciones[i].getFechaReserva().getDia() << " ";
					NuevasReservas << Reservaciones[i].getFechaReserva().getMes() << " ";
					NuevasReservas << Reservaciones[i].getFechaReserva().getAnio() << " ";
					NuevasReservas << Reservaciones[i].getIdMaterial() << " ";
					NuevasReservas << Reservaciones[i].getIdCliente() << " ";
					NuevasReservas << endl;
				}

				//Cerramos archivos
				NuevasReservas.close();

				//Terminamos programa
				return 0;
				
				cout << endl;	//Terminamos linea por estetica
			break;					
		} 
	} while (Opcion != 'f');

	//Cerramos ambos archivos
	ArchivoMaterial.close();
	ArchivoReservaciones.close();

	//Terminamos programa
	return 0;
}
