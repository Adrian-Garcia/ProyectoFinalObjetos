#include "Libro.h"
#include "Disco.h"
#include "Software.h"
#include "Fecha.h"
#include "Reserva.h"
#include <fstream>

int main() {

	//Para almacenar materiales y reservas 
	Material *Materiales[20];
	Reserva Reservaciones[50];

	//Declaramos los atchivos
	ifstream ArchivoMaterial;		//Archivo de Materiales
	ifstream ArchivoReservaciones;	//Archivo de Reservaciones

	//Datos de clase Material
	int iIdMaterial;	//Tambien se usa en reservaciones
	string sTitulo;

	//Datos de clase Libro
	int iNumPag;
	string sAutor;

	//Datos de clase Disco
	int iDuracion;

	//Datos de clase Software
	string sSistemaOperativo;

	//Tipo de Material
	char cTipo;

	//Fecha de la reservacion
	Fecha fecha();

	//Datos de la clase reservacion
	int iIdCliente;

	//Cantidad de Materiales y de Reservaciones
	int iNumMate=0;
	int iNumRese=0;

	//Contador
	int i=0;

	//Accion que el usuario desea realizar en el menu
	char Opcion;	

	//Opcion de 
	int iOpcion;

	//Abrimos los archivos
	ArchivoMaterial.open("Material.txt");
	ArchivoReservaciones.open("Reserva.txt");

//------------------------Duda---------------------------------------
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

				//Modificamos los datos
				Materiales[iNumMate].setIdMaterial(iIdMaterial);
				Materiales[iNumMate].setTitulo(sTitulo);
				Materiales[iNumMate].setNumPag(iNumPag);
				Materiales[iNumMate].setAutor(sAutor);
				
			break;

			case 'D':	//Tipo Disco

				//Obtenemos Duracion
				ArchivoMaterial >> iDuracion;

				//Modificamos los datos
				Materiales[iNumMate].setIdMaterial(iIdMaterial);
				Materiales[iNumMate].setTitulo(sTitulo);
				Mateirales[iNumMate].setDuracion(iDuracion);

			break;

			case 'S':	//Tipo Software

				//Obtenemos nombre del Sistema Operativo
				ArchivoMaterial >> sSistemaOperativo;

				//Modificamos los datos
				Materiales[iNumMate].setIdMaterial(iIdMaterial);
				Materiales[iNumMate].setTitulo(sTitulo);			
				Materiales[iNumMate].setSistemaOperativo(sSistemaOperativo);
			
			break;
		}
		iNumMate++;	//Aumentamos 1 al contador
	}

 //---------------------------Duda---------------------------------------------
 //Tenemos que usar el operador >> para obtener los datos de fecha?
 //Podemos obtener dia, mes y ano de manera separada?
	while (ArchivoReservaciones >> Fecha) {
		
		//Obtenemos ID de Material y de Cliente
		ArchivoReservaciones >> iIdMaterial;
		ArchivoReservaciones >> iIdCliente;

		//Modificamos los datos
		Reservaciones[iNumRese].setFecha(Fecha);
		Reservaciones[iNumRese].setIdMaterial(iIdMaterial);
		Reservaciones[iNumRese].setIdCliente(iIdCliente);

		iNumRese++;	//Aumentamos 1 al contador
	}

	do { //Se repite mientras el usuario no de a f

		cout << "MENU" << endl;
		cout << "a) Consultar la lista de Materiales \n";
		cout << "b) Consultar la lista de reservaciones \n"
		cout << "c) Consultar las reservaciones de un material \n";
		cout << "d) Consular las reservaciones de una fecha \n";
		cout << "e) Hacer una reservacion \n";
		cout << "f) Terminar \n";
		cout << "Opcion: ";

		cin >> Opcion;
		cout << "\n\n";

		switch (Opcion) {

			//Consultar la lista de Materiales
			case 'a' :
 //----------------------Duda----------------------------------------------------
 //Como le hacemos para saber si desplegamos una clase Disco, Libro o Software
				//Desplegamos la lista de Materiales en la pantalla
				for (i=0; i<iNumMate; i++) {

				}

				cout << endl;	//Terminamos linea por estetica
			break;

			//Consultar la lista de reservaciones
			case 'b' :

				//Desplegamos la lista de Reservaciones en la pantalla
				for (i=0; i<iNumRese; i++) {

					//Obtenemos datos de Reservaciones
					fecha = Reservaciones[i].getFecha();
					iIdMaterial = Reservaciones[i].getIdMaterial();
					iIdCliente = Reservaciones[i].getIdCliente();

					//Desplegamos las fechas
					fecha.muestraFecha();
					cout << iIdMaterial << " " << iIdMaterial << " " << iIdCliente << endl;
				}

				cout << endl;	//Terminamos linea por estetica 
			break;	

 //---------------------Incompleto-------------------------------------------------
 //Falta que diga fecha de inicio y fin de la reservacion
			//Consultar las reservaciones de un material
			case 'c' : 

				cout << "Inserta el ID de un Material: ";
				cin >> iOpcion;

				for (i=0; i<iNumRese; i++) {
					if (Reservaciones[i].getIdMaterial == iOpcion) {
						
						//Obtenemos datos de Reservaciones
						fecha = Reservaciones[i].getFecha();
						iIdMaterial = Reservaciones[i].getIdMaterial();
						iIdCliente = Reservaciones[i].getIdCliente();

						//Desplegamos las fechas
						fecha.muestraFecha();
						cout << iIdMaterial << " " << iIdMaterial << " " << iIdCliente << endl;
					}
				}

				cout << endl;	//Terminamos linea por estetica
			break;	
		
			//Consultar las reservaciones de una fecha
			case 'd' : 
				cout << endl;	//Terminamos linea por estetica
			break;
				
			//Hacer una reservacion
			case 'e' : 
				cout << endl;	//Terminamos linea por estetica
			break;
				
			//Terminar	
			case 'f' : 

				cout << "Programa Terminado \n";

				//Cerramos ambos archivos
				ArchivoMaterial.close();
				ArchivoReservaciones.close();
				
				cout << endl;	//Terminamos linea por estetica
			break;					
		} 

		if (Opcion > 'f') {
			cout << "Por favor introduce una opcion valida \n\n"
		}

	} while (Opcion != 'f');

	return 0;
}