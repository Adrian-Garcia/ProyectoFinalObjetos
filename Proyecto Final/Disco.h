#include "Material.h"

//Clase Disco, hija de Material
class Disco : public Material {
	private:
		//Duracion del disco
		int iDuracion;

	public:
		//Constructor Default
		Disco() : Material() {
			iDuracion = 0;
		}

		//Constructor. Hereda ID y TItulo de la clase material
		Disco(int iIdMaterial, string sTitulo, int iDuracion):Material(iIdMaterial, sTitulo) {
			this->iDuracion = iDuracion;
		}

		//Metodo que obtiene la duracion del Disco
		int getDuracion() {
			return iDuracion;
		}

		//Metodo que modifica la duracion
		void setDuracion(int iNewDuration) {
			iDuracion = iNewDuration;
		}
	
		//Metodo que muestra las caracteristicas del disco
		void muestra() {
			cout << "Disco" << endl;
			cout << "ID: " << iIdMaterial << endl;
			cout << "TItulo: " << sTitulo << endl;
			cout << "Duracion: " << iDuracion << endl;
		}

		//Regresa el numero de dias que puede ser prestado
		int diasPrestamo () {
			return 3;
		}
};
