#include "Material.h"

class Software : public Material {
	private:
		//Conformada por el nombre del Sistema Operativo
		string sSistemaOperativo;

	public:
		//Constructor Default
		Software() : Material() {
			sSistemaOperativo = "NA";
		}

		//Constructor
		Software (int iIdMaterial, string sTitulo, char cTipo, string sSistemaOperativo):Material(iIdMaterial, sTitulo, cTipo) {
			this->iIdMaterial = iIdMaterial;
		}

		//Metodo que regresa el nombre del Sistema Operativo
		string getSistemaOperativo() {
			return sSistemaOperativo;
		}

		//Metodo que modifica el nombre del Sistema Operativo
		void setSistemaOperativo(string NuevoSistema) {
			sSistemaOperativo = NuevoSistema;
		}	

		//Metodo que muestra los datos del Sistema Operativo
		void muestra() {
			cout << "ID: " << iIdMaterial << endl;
			cout << "Titulo: " << sTitulo << endl;
			cout << "Sistema Operativo: " << sSistemaOperativo << endl << endl;
		}

		//Regresa el numero de dias que puede ser prestado
		int diasPrestamo() {
			return 1;
		}

};
