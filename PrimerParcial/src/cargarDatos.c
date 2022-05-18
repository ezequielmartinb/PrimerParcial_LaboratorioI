#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"
#include "censista.h"
#include "zona.h"
#include "localidades.h"
#include "cargarDatos.h"


#define ACTIVO 1
#define INACTIVO 2
#define LIBERADO 3

#define PENDIENTE 0
#define FINALIZADO 1

#define VACIO 1
#define CARGADO 0
/*
 * CANTIDAD CENSADOS IN SITU
 * CANTIDAD DE CENSADOS FORMULARIO DIGITAL
 * CANTIDAD DE CENSADOS AUSENTES
 *
 * ESTADO DE ZONA FINALIZADO
 * CENSISTA LIBERADO
 */
int inicializarCargarDatos(CargaDatos* listaCargarDatos, int len)
{
	int retorno=-1;

	if(listaCargarDatos!=NULL && len>0)
	{
		for (int i=0; i<len; i++)
		{
			retorno=0;
			listaCargarDatos[i].isEmpty=VACIO;
		}
	}
	return retorno;
}
int incrementarIdCargarDatos()
{
	static int idCargarDatos=3000;

	idCargarDatos++;

	return idCargarDatos;
}
int buscarEspacioLibreCargarDatos(CargaDatos* listaCargarDatos, int len)
{
	int retorno=-1;
	if (listaCargarDatos!=NULL && len>0)
	{
		for (int i=0; i<len; i++)
		{
			if (listaCargarDatos[i].isEmpty==VACIO)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}
int cargarDatos(Censista* listaCensista, int lenCensista, Zona* listaZona, int lenZona, Localidad* localidades, int lenLocalidades, CargaDatos* listaCargarDatos, int lenCargarDatos)
{
	int retorno=-1;
	int indexCensista;
	int indexZona;
	int idCensista;
	int idZona;

	if(listaCensista!=NULL && lenCensista>0 && listaZona!=NULL && lenZona>0)
	{
		for(int i=0;i<lenCargarDatos;i++)
		{
			listaCargarDatos[i].idCargaDatos=incrementarIdCargarDatos();
			imprimirCensista(listaCensista, lenCensista);

			if(utn_getNumeroEntero(&idCensista, "Ingrese el ID del Censista a cargar datos: ", "ERROR. ID INVALIDO", 1001, 1005, 3)==0)
			{
				indexCensista=buscarCensistaPorId(listaCensista, lenCensista, idCensista);
				imprimirZona(listaZona, lenZona, localidades, lenLocalidades, listaCensista, lenCensista);
				if(utn_getNumeroEntero(&idZona, "Ingrese el ID de la zona a cargar datos: ", "ERROR. ID INVALIDO", 4001, 4005, 3)==0)
				{
					indexZona=buscarZonaPorId(listaZona, lenZona, idZona);
					if(utn_getNumeroEntero(&listaCargarDatos[i].cantidadCensadosInSitu, "Ingrese la cantidad de censados in situ: ", "ERROR. CANTIDAD INVALIDA", 0, 100000, 3)==-1)
					{
						printf("Los datos de los censados con el Formulario Digital fue erronea\n");
					}
					if(utn_getNumeroEntero(&listaCargarDatos[i].cantidadCensadosFormularioDigital, "Ingrese la cantidad de censados con el Formulario Digital: ", "ERROR. CANTIDAD INVALIDA", 0, 100000, 3)==-1)
					{
						printf("Los datos de los censados con el Formulario Digital fue erronea\n");
					}
					if(utn_getNumeroEntero(&listaCargarDatos[i].cantidadCensadosAusentes, "Ingrese la cantidad de los censados ausentes: ", "ERROR. CANTIDAD INVALIDA", 0, 100000, 3)==-1)
					{
						printf("Los datos de los censados ausentes\n");
					}

					listaZona[indexZona].estadoZona=FINALIZADO;
					listaCensista[indexCensista].estadoCensista=LIBERADO;
				}
			}
		}

	}



	return retorno;
}
