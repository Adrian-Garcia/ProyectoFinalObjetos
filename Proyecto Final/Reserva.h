#include "Fecha.h"

//Reserva de algun material
class Reserva {
	private:
		//Conformada por
		int iIdMaterial, iIdCliente;	//El material prestado y el ID del cliente
		Fecha fechaReservacion;			//La fecha en la que se reservo el material

	public:
		//Constructor default
		Reserva () {
			iIdMaterial = 0;
			iIdCliente = 0;
		}

		//Constructor 
		Reserva (int iIdMaterial, int iIdCliente, Fecha fechaReservacion) {
			this->iIdMaterial = iIdMaterial;
			this->iIdCliente = iIdCliente;
			this->fechaReservacion = fechaReservacion;
		}

		//Metodo que obtiene el material
		int getIdMaterial() {
			return iIdMaterial;
		}

		//Metodo que obtiene el ID del cliente
		int getIdCliente() {
			return iIdCliente;
		}

		//Metodo que obtiene la fecha
		Fecha getFecha() {
			return fechaReservacion;
		}

		//Metodo que modifica el ID material
		void setIdMaterial(int iID) {
			iIdMaterial = iID;
		}

		//Metodo que modifica el ID del cliente
		void setIdCliente(int iCliente) {
			iIdCliente = iCliente;
		}

		//Metodo que modifica la fecha de reservacion
		void setFecha(Fecha nuevaFecha) {
			fechaReservacion = nuevaFecha;
		}

		//Metodo que calcula la fecha de regreso del material
		Fecha calculaFecha(int cantidadDias) {	
			Fecha fechaRegreso;
			return fechaRegreso + cantidadDias;
		}
};