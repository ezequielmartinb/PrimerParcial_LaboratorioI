#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"
#include "censista.h"
#include "localidades.h"
#include "zona.h"
#include "cargarDatos.h"

#define VACIO 1
#define CARGADO 0

#define ACTIVO 1
#define INACTIVO 2
#define LIBERADO 3

#define PENDIENTE 0
#define FINALIZADO 1
//a. Informar cantidad de censistas en estado Activo con zona Pendiente.

int cantidadCensistasActivosConZonaPendiente(Censista* listaCensistas, int lenCensista, Zona* listaZona, int lenZona, int* contadorCensistasActivosConZonaPendiente)
{
	int retorno=-1;
	int auxiliarContador=0;

	if(listaCensistas!=NULL && listaZona!=NULL && lenZona>0 && lenCensista>0)
	{
		for(int i=0;i<lenCensista;i++)
		{
			for(int j=0;j<lenZona;j++)
			{
				if(listaCensistas[i].idCensista==listaZona[j].idCensista)
				{
					if(listaCensistas[i].estadoCensista==ACTIVO && listaZona[j].estadoZona==PENDIENTE)
					{
						auxiliarContador++;
						*contadorCensistasActivosConZonaPendiente=auxiliarContador;
						retorno=0;
					}
				}

			}
		}
	}

	return retorno;
}
//b. Mostrar el listado de censistas de Avellaneda, Lanús, Lomas de Zamora o Banfield ordenados alfabéticamente por apellido y nombre.

int mostrarCensistasPorLocalidad(Censista* listaCensistas, int lenCensista, Zona* listaZona, int lenZona, Localidad* listaLocalidades, int lenLocalidades, char localidad[])
{
	int retorno;
	int estaOrdenado;
	Censista auxiliarCensistas;

	if(listaZona!=NULL && listaCensistas!=NULL && listaLocalidades!=NULL && lenZona>0 && lenLocalidades>0 && lenCensista>0)
	{
		for(int i=0;i<lenCensista;i++)
		{
			for(int j=0;j<lenZona;j++)
			{
				for(int k=0;k<lenLocalidades;k++)
				{
					if(listaCensistas[i].idZona==listaZona[j].idZona && listaZona[j].idLocalidad==listaLocalidades[k].idLocalidades && listaLocalidades[k].localidades==localidad)
					{
						do
						{
							estaOrdenado=1;
							lenCensista--;
							for(i=0;i<lenCensista;i++)
							{
								if(strcmp(listaCensistas[i].apellido, listaCensistas[i+1].apellido)>0 && strcmp(listaCensistas[i].apellido, listaCensistas[i+1].apellido))
								{
									auxiliarCensistas=listaCensistas[i];
									listaCensistas[i]=listaCensistas[i+1];
									listaCensistas[i+1]=auxiliarCensistas;
									estaOrdenado=0;
								}
							}
						}while(estaOrdenado==0);
						retorno=0;
					}
				}
			}
		}
	}


	return retorno;
}


//c. Informar nombre de localidad con más casas ausentes.

int localidadConMasCasasAusentes(Zona* listaZona, int lenZona, Localidad* listaLocalidades, int lenLocalidades, CargaDatos* listaCargarDatos, int lenCargarDatos, int* cantidadMaximaAusentes, char* localidadMaximaAusentes)
{
	int retorno=-1;
	int banderaDelPrimero=0;
	int auxiliarCantidadMaximaAusentes=0;

	if(listaZona!=NULL && listaLocalidades!=NULL && lenZona>0 && lenLocalidades>0)
	{
		for(int i=0;i<lenZona;i++)
		{
			for(int j=0;j<lenLocalidades;j++)
			{
				for(int k=0;k<lenCargarDatos;k++)
				{
					if(listaZona[i].idLocalidad==listaLocalidades[j].idLocalidades)
					{
						if(listaCargarDatos[k].cantidadCensadosAusentes>auxiliarCantidadMaximaAusentes || banderaDelPrimero==0)
						{
							auxiliarCantidadMaximaAusentes=listaCargarDatos[k].cantidadCensadosAusentes;
							*cantidadMaximaAusentes=auxiliarCantidadMaximaAusentes;
							localidadMaximaAusentes=listaLocalidades[j].localidades;
							banderaDelPrimero=1;
						}
						retorno=0;
					}
				}

			}
		}

	}



	return retorno;
}
