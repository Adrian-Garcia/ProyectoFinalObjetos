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
		Software (int iIdMaterial, string sTitulo, string sSistemaOperativo):Material(iIdMaterial, sTitulo) {
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
			cout << "Software" << endl;
			cout << "ID: " << iIdMaterial << endl;
			cout << "Titulo: " << sTitulo << endl;
			cout << "Sistema Operativo: " << sSistemaOperativo << endl;
		}

		//Regresa el numero de dias que puede ser prestado
		int diasPrestamo() {
			return 1;
		}

};
