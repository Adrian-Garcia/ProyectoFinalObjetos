#include <iostream>
#include <string>

using namespace std;

//Clase Fecha 
class Fecha {
private:
	//Conformada por dia mes y anio
	int iDia, iMes, iAnio;

public:
	//Constructor default
	Fecha() {
		iDia = 0;
		iMes = 0;
		iAnio = 0;
	}

	//Constructor
	Fecha (int iDia, int iMes, int iAnio) {
		this->iDia = iDia;
		this->iMes = iMes;
		this->iAnio = iAnio;
	}

	//Metodo que obtiene el dia de la clase  
	int getDia() {
		return iDia;
	}

	//Metodo que obtiene el mes
	int getMes() {
		return iMes;
	}

	//Metodo que obtiene el Anio
	int getAnio () {
		return iAnio;
	}

	//Metodo que modifica la Fecha
	void setFecha(int iDD, int iMM, int iAA) {
		iDia = iDD;
		iMes = iMM;
		iAnio = iAA;
	}

	//Metodo que suma los dias que se proporcionen a la fecha
	Fecha operator + (int iAdd) {

		int iDia = this->iDia;
		int iMes = this->iMes;
		int iAnio = this->iAnio;

		int iD, iM, iA;

		//Si el mes tiene 31 dias
		if (iMes==1 || iMes==3 || iMes==5 || iMes==7 || iMes==8 || iMes==10 || iMes==12) {
			if ((iDia+iAdd) <= 31) {
				
				iD = iDia+iAdd;
				iM = iMes;
				iA = iAnio;
			}

			else if ((iDia+iAdd)>31 && iMes<12) {				
				
				iD = iDia+iAdd;
				iM = iMes+1;
				iA = iAnio;
			}

			else {
					
				iD = iDia+iAdd-31;
				iM = iMes+1;
				iA = iAnio+1;
			}
		}

		//Si el mes tiene 30 dias
		else if (iMes==4 || iMes==6 || iMes==9 || iMes==11) {
			
			//Si la suma de los dias no da mas de 30
			if ((iDia+iAdd) <= 30) {
				
				iD = iDia+iAdd;
				iM = iMes;
				iA = iAnio;
			}

			//Si la suma de los dias da mas de 30
			else  {

				iD = iDia+iAdd-31;
				iM = iMes+1;
				iA = iAnio;
			}
		}

		//Si el mes tiene 28 dias
		else {
			if (esBisiesto() == true) {

				//Si la suma de los dias no da mas de 29
				if ((iDia+iAdd) <= 29) {

					iD = iDia+iAdd;
					iM = iMes;
					iA = iAnio;
				}

				else {
				
					iD = iDia;
					iM = iMes+1;
					iA = iAnio;
				}
			}

			else {

				//Si la suma de los dias no da mas de 28
				if ((iDia+iAdd) <= 28) {

					iD = iDia+iAdd;
					iM = iMes;
					iA = iAnio;
				}

				else {
					
					iD = iDia+iAdd-28;
					iM = iMes+1;
					iA = iAnio;
				}
			}
		}

		Fecha Retorno(iD, iM, iA);
		return Retorno;
	} 

	//Metodo que regresa si una fecha es MAYOR que otra
	friend bool operator > (Fecha F1, Fecha F2) {
		
		//Comparamos el Anio
		if (F1.getAnio()>F2.getAnio()) {
			return true;
		}

		//Comparamos el Mes
		else if (F1.getMes()>F2.getMes() && F1.getAnio()==F2.getAnio()) {
			return true;
		}

		//Comparamos el Dia
		else if (F1.getDia()>F2.getDia() && F1.getMes()==F2.getMes() && F1.getAnio()==F2.getAnio()) {
			return true;
		}

		//Si ninguna es verdadera, entonces es falso
		else {
			return false;
		}
	}

	//Metodo que regresa si una fecha es MENOR que otra
	friend bool operator < (Fecha F1, Fecha F2) {
		
		//Comparamos el Anio
		if (F1.getAnio()<F2.getAnio()) {
			return true;
		}

		//Comparamos el Mes
		else if (F1.getMes()<F2.getMes() && F1.getAnio()==F2.getAnio()) {
			return true;
		}

		//Comparamos el Dia
		else if (F1.getDia()<F2.getDia() && F1.getMes()==F2.getMes() && F1.getAnio()==F2.getAnio()) {
			return true;
		}

		//Si ninguna es verdadera, entonces es falso
		else {
			return false;
		}
	}

	//Metodo que regresa si una fecha es MAYOR O IGUAL que otra
	friend bool operator >= (Fecha F1, Fecha F2) {
		
		//Comparamos el Anio
		if (F1.getAnio()>=F2.getAnio()) {
			return true;
		}

		//Comparamos el Mes
		else if (F1.getMes()>=F2.getMes() && F1.getAnio()==F2.getAnio()) {
			return true;
		}

		//Comparamos el Dia
		else if (F1.getDia()>=F2.getDia() && F1.getMes()==F2.getMes() && F1.getAnio()==F2.getAnio()) {
			return true;
		}

		//Si ninguna es verdadera, entonces es falso
		else {
			return false;
		}
	}

	//Metodo que regresa si una fecha es MENOR O IGUAL que otra
	friend bool operator <= (Fecha F1, Fecha F2) {
		
		//Comparamos el Anio
		if (F1.getAnio()<=F2.getAnio()) {
			return true;
		}

		//Comparamos el Mes
		else if (F1.getMes()<=F2.getMes() && F1.getAnio()==F2.getAnio()) {
			return true;
		}

		//Comparamos el Dia
		else if (F1.getDia()<=F2.getDia() && F1.getMes()==F2.getMes() && F1.getAnio()==F2.getAnio()) {
			return true;
		}

		//Si ninguna es verdadera, entonces es falso
		else {
			return false;
		}
	}

	//Metodo que regresa si una fecha es IGUAL que otra
	friend bool operator == (Fecha F1, Fecha F2) {
		
		//Comparamos cada termino
		if (F1.getDia()==F2.getDia() && F1.getMes()==F2.getMes() && F1.getAnio()==F2.getAnio()) {
			return true;
		}

		//Si uno es diferente, entonces es falso
		else {
			return false;
		}
	}

	//Output
	friend ostream operator << (ostream o, Fecha F1) {
		
		//Esto debe ser un void? Como imprimir en pantalla?
		o << F1.getDia() << " " << F1.getMes() << " " << F1.getAnio();
		
		//https://es.wikibooks.org/wiki/Programaci%C3%B3n_en_C%2B%2B/Sobrecarga_de_Operadores#Sobrecarga_del_operador_%3C%3C_(_iostream_)
	}

	//Input
	friend istream operator >> (istream i, Fecha F1) {
		int iDd;
		int iMm;
		int iAa;
	
		//Obtenemos los datos de mes dia y anio
		i >> iDd >> iMm >> iAa;
		
		//Cambiamos la fecha
		F1.setFecha(iDd, iMm, iAa);
		
		//https://es.wikibooks.org/wiki/Programaci%C3%B3n_en_C%2B%2B/Sobrecarga_de_Operadores#Sobrecarga_del_operador_%3C%3C_(_iostream_)
	} 

	//Regresa el nombre del mes en formato de tres letras
	string nombreMes() {
		switch (iMes) {

			case 1:
				return "Ene";
			break;

			case 2:
				return "Feb";
			break;	

			case 3:
				return "Mar";
			break;
				
			case 4:
				return "Abr";
			break;
				
			case 5:
				return "May";
			break;
				
			case 6:
				return "Jun";
			break;

			case 7:
				return "Jul";
			break;

			case 8:
				return "Ago";
			break;
				
			case 9:
				return "Sep";
			break;
				
			case 10:
				return "Oct";
			break;
				
			case 11:
				return "Nov";
			break;
				
			case 12:
				return "Dic";
			break;											
		}
	}

	//Validacion de si el anio es bisiesto o no
	bool esBisiesto() {
	//Usaremos 2016 como el anio bisiesto de comparacion 
		

		int iCounter = 2016;
		
		//Si el anio a verificar es mayor que 2016 sumaremos anios
		if (iAnio > 2016) {

			//Sumaremos 4 al contador hasta que sea menor que el anio			
			do {
				iCounter += 4;
			} while (iCounter <= iAnio);

			//Si el contador termina siendo igual que el anio, es bisiesto
			if (iCounter == iAnio) {
				return true;
			}

			//Si no, no es bisiesto
			else {
				return false;
			}
		}

		//Si el anio a verificar es menor que 2016 restaremos anios
		else if (iAnio < 2016) {

			//Restaremos 4 al contador hasta que sea mayor que el anio
			do {
				iCounter -= 4;
			} while(iCounter >= iAnio);

			//Si el contador termina siendo igual que el anio, es bisiesto
			if (iCounter == iAnio) {
				return true;
			}

			//Si no, no es bisiesto
			else {
				return false;
			}
		}

		//Regresamos verdadero si es 2016
		else {
			return true;
		}
	}

	//Desplega la fecha
	void muestraFecha() {
		cout << iDia << " " << nombreMes() << " " <<iAnio;
	}
};
