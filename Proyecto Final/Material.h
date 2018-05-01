#include <string>
#include <iostream> 
#ifndef Material_h
#define Material_h 

using namespace std;

class Material {
	protected:
		int iIdMaterial;	//ID del Material prestado
		string sTitulo;		//Titulo del material que se presto
		char cTipo;			//Tipo de material que se presto

	public: 

		//Contructor default
		Material () {
			iIdMaterial = 0;
			sTitulo = "NA";
			cTipo = 'N';
		}

		//Constructor 
		Material (int iIdMaterial, string sTitulo, char cTipo) {
			this->iIdMaterial = iIdMaterial;
			this->sTitulo = sTitulo;
			this->cTipo = cTipo;
		}

		//Regresa material
		int getIdMaterial() {
			return iIdMaterial;
		}

		//Regresa el titulo
		string getTitulo() {
			return sTitulo;
		}

		//Regresa el tipo de material
		char getTipo() {
			return cTipo;
		}

		//Modifica Material
		void setIdMaterial(int ID) {
			iIdMaterial = ID;
		}

		//Modifica titulo
		void setTitulo(string sTitle) {
			sTitulo = sTitle;
		}

		//Modifica tipo
		void setTipo(char cType) {
			cTipo = cType;
		}

		//Metodo abstracto muestra 
		virtual void muestra() = 0;

		//Numero de dias en las que un material se puede prestar 
		virtual	int diasPrestamo () = 0;
};

#endif