#include "fechaNacimiento.h"
#include "direccion.h"
#ifndef CENSISTA_H_
#define CENSISTA_H_


typedef struct{
	int idCensista;// PK
	char nombre[50];
	char apellido[50];
	Fecha fechaNacimientoCensista;
	Direccion direccionCensista;
	int estadoCensista; //	ACTIVO/INACTIVO/LIBERADO
	int idZona; // FK
	int isEmpty;

}Censista;
int inicializarCensistas(Censista* listaCensista, int len);
int incrementarIdCensista();
int buscarEspacioLibre(Censista* listaCensista, int len);
int imprimirCensista(Censista* listaCensista, int lenCensista);
int cargarCensista(Censista* listaCensista, int lenCensista);
int buscarCensistaPorId(Censista* listaCensista, int len,int id);
int modificarCensista(Censista* listaCensista, int len, int id);
int existeCensistaPorId(Censista* listaCensista, int len, int id);
int bajaCensista(Censista* listaCensista, int len, int id);
#endif /* CENSISTA_H_ */
