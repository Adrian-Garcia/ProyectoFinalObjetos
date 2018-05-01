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
	ifstream ArchivoReservaciones;	//Archivo de Reservaciones

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
	Fecha fechaFin();

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
	ArchivoMaterial.open("Material.txt");
	ArchivoReservaciones.open("Reserva.txt");

 //------------------------Duda-----------------------------------------
 //Como almacenamos datos de clases hijas en arreglo de clase Materieles

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

 //---------------------------Duda---------------------------------------------
 //Tenemos que usar el operador >> para obtener los datos de fecha?
 //Podemos obtener dia, mes y ano de manera separada?
	
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
		cout << "Opcion: ";

		do {	//Valiadmos que el usuario ingrese una opcion correcta
			
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

// Falta fecha inicio y fecha fin de reservacion

			//Consultar la lista de reservaciones
			case 'b' :

				//Desplegamos la lista de Reservaciones en la pantalla
				for (i=0; i<iNumRese; i++) {
					Reservaciones[i].muestraReserva();	
				}

				cout << endl;	//Terminamos linea por estetica 
			break;	

// Falta fecha inicio y fecha fin de reservacion

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
			case 'd' : 

				//Pedimos la fecha 
				cout << "Inserta una fecha en formato DD/MM/AAAA: ";
				cin >> iDD;
				cin >> iMM;
				cin >> iAA;
	
				//Nuevo objeto fecha
				Fecha fechaReserva(iDD, iMM, iAA);

				//Buscamos en todas las reservaciones
				for(i=0; i<iNumRese; i++) {

					//Si una reservacion es igual a la fecha dada
					if (Reservaciones[i].getFechaReserva() == fechaReserva) {

						//La desplegamos
						Reservaciones[i].muestraReserva();
					}
				} 

				cout << endl;	//Terminamos linea por estetica
			break;
				
			//Hacer una reservacion
			case 'e' : 

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
					for (i=0; i<iNumRese; i++) {

						//Si un material es igual al ID del material dado
						if (Materiales[i]->getIdMaterial() == iIdMaterial) {
							
							//Validamos que el material exista
							Valida = true;
							
							break;	//Terminamos la busqueda
						}
					}

					//Si no se encontro el ID, despliega este mensaje
					if (Valida == false) {
						cout << endl << "Inserta un ID correcto\n\n";
					}
				} while (Valida == false);

				//Lo convertimos a verdadero para verificar que no haya mas fechas
				Valida = true;

				do {	//Validamos que el material prestado este disponible

					//Preguntamos al usuario una fecha
					cout << "Inserta la fecha de tu reservacion en formato DD/MM/AAAA";
					cin >> iDD;
					cin >> iMM;
					cin >> iAA;

					//Definimos fechas de inicio y fin de reservacion
					fecha.setFecha(iDD, iMM, iAA);
					fechaFin = fecha+Materiales[i]->diasPrestamo();

					//Buscamos entre todas las Reservaciones
					for (j=0; j<iNumRese; j++) {
						
						//Si encontramos nuestro ID
						if (Reservaciones[j].getIdMaterial() == iIdMaterial) {
							
							fecha ReseStart = Reservaciones[j].getFecha();
							fecha ReseEnd = ReseStart+Materiales[i]->diasPrestamo();

							//Revisaremos que no se empalmen fechas	
							if ((fecha>ReseStart&&fecha<ReseEnd)||(fechaFin>ReseStart&&fechaFin<ReseEnd)) {
								Valida = false;
							}
						}
					}
				} while(Valida == false);

				//Asignamos los valores a las nuevas reservaciones
				Reservaciones[iNumRese].setIdMaterial(iIdMaterial);
				Reservaciones[iNumRese].setIdCliente(iIdCliente);
				Reservaciones[iNumRese].setFecha(fecha);

				//Aumentamos la cantidad de reservaciones
				iNumRese++;

				cout << endl;	//Terminamos linea por estetica
			break;
				
			//Terminar	
			case 'f' : 

				//Informamos al usuario que el programa ha terminado
				cout << "Programa Terminado \n";

				//Cerramos ambos archivos
				ArchivoMaterial.close();
				ArchivoReservaciones.close();

				//Terminamos programa
				return 0;
				
				cout << endl;	//Terminamos linea por estetica
			break;					
		} 
	} while (Opcion != 'f');

	//Terminamos programa
	return 0;
}
