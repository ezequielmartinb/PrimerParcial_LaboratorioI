#include "localidades.h"


#ifndef CARGARDATOS_H_
#define CARGARDATOS_H_

typedef struct
{
	int idCargaDatos;
	int idCensados;
	int idZona;
	int cantidadCensadosInSitu;
	int cantidadCensadosFormularioDigital;
	int cantidadCensadosAusentes;
	int isEmpty;
}CargaDatos;
int inicializarCargarDatos(CargaDatos* listaCargarDatos, int len);
int buscarEspacioLibreCargarDatos(CargaDatos* listaCargarDatos, int len);
int cargarDatos(Censista* listaCensista, int lenCensista, Zona* listaZona, int lenZona, Localidad* localidades, int lenLocalidades, CargaDatos* listaCargarDatos, int lenCargarDatos);


//int cargarDatos(Censista* listaCensista, int lenCensista, Zona* listaZona, int lenZona, Localidad* localidades, int lenLocalidades);


#endif /* CARGARDATOS_H_ */
