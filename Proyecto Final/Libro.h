#include "Material.h"

class Libro : public Material {
	private:
		int iNumPag;
		string sAutor;

	public:
		//Constructor default
		Libro () : Material (){
			iNumPag = 0;
			sAutor = "NA";
		}

		//Constructor
		Libro (int iIdMaterial, string sTitulo, char cTipo, int iNumPag, string sAutor):Material(iIdMaterial, sTitulo, cTipo) {
			this->iNumPag = iNumPag;
			this->sAutor = sAutor;
		}

		//Regresa el numero de Paginas del libro
		int getNumPag() {
			return iNumPag;
		}

		//Regresa el autor del Libro
		string getAutor() {
			return sAutor;
		}

		//Modifica el numero de paginas del Libro
		void setNumPag(int iPageNumber) {
			iNumPag = iPageNumber;
		}

		//Modifica el autor del Libro
		void setAutor(string sNewAutor) {
			sAutor = sNewAutor;
		}

		//Muestra los datos del material prestado
		void muestra() {
			cout << "ID: " << iIdMaterial << endl;
			cout << "Titulo: " << sTitulo << endl;
			cout << "Numero de paginas: " << iNumPag << endl;
			cout << "Autor: " << sAutor << endl << endl;
		}

		//Regresa el numero de dias que puede ser prestado
		int diasPrestamo () {
			return 10;
		}
};