#include "censista.h"
#include "localidades.h"
//#include "direccion.h"
#ifndef ZONA_H_
#define ZONA_H_

typedef struct{
	int idZona; // PK
	int idCensista; // FK
	char calles[4][50];
	int idLocalidad; // FK
	int estadoZona; // PENDIENTE/FINALIZADO
	int isEmpty;
}Zona;
int inicializarZona(Zona* listaZona, int len);
int incrementarIdZona();
int buscarIndexPorIsEmptyZona(Zona* listaZona, int len);
int buscarEspacioLibreZona(Zona* listaZona, int len);
int cargarZona(Zona* listaZona, int lenZona, Censista* listaCensistas, int lenCensista, Localidad* localidades, int lenLocalidades);
int imprimirZona(Zona* listaZona, int lenZona, Localidad* localidades, int lenLocalidades, Censista* listaCensistas, int lenCensista);
int buscarZonaPorId(Zona* listaZona, int len,int id);
int asignarZona(Zona* listaZona, int lenZona, Censista* listaCensistas, int lenCensista, Localidad* localidades, int lenLocalidades);


#endif /* ZONA_H_ */
