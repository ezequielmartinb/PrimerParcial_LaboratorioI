#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "zona.h"
//#include "censista.h"
//#include "localidades.h"
#include "direccion.h"
#include "inputs.h"

#define VACIO 1
#define CARGADO 0

#define ACTIVO 1
#define INACTIVO 2
#define LIBERADO 3

#define PENDIENTE 0
#define FINALIZADO 1

int inicializarZona(Zona* listaZona, int len)
{
	int retorno=-1;

	if(listaZona!=NULL && len>0)
	{
		for (int i=0; i<len; i++)
		{
			retorno=0;
			listaZona[i].isEmpty=VACIO;
		}
	}
	return retorno;
}
int incrementarIdZona()
{
	static int IdZona=4000;

	IdZona++;

	return IdZona;
}
int buscarIndexPorIsEmptyZona(Zona* listaZona, int len)
{
	int retorno = -1;

		if(listaZona!=NULL && len>0)
		{
			for(int i = 0; i < len; i++)
			{
				if(listaZona[i].isEmpty==1)
				{
					retorno = i;
					break;
				}
			}
		}

	return retorno;
}
int cargarZona(Zona* listaZona, int lenZona, Censista* listaCensistas, int lenCensista, Localidad* localidades, int lenLocalidades)
{
	int retorno=-1;
	int indexLibre;

	if(listaZona!=NULL && lenZona>0)
	{
		indexLibre=buscarEspacioLibreZona(listaZona, lenZona);
		if(indexLibre!=-1)
		{
			listaZona[indexLibre].idZona=incrementarIdZona();
			for(int i=0;i<4;i++)
			{
				if(utn_getDireccion(listaZona[indexLibre].calles[i], 50, "Ingrese las cuatro calles: ", "ERROR. CALLE INVALIDA", 3)==-1)
				{
					printf("Las calles NO fue cargadas con exito");
				}
			}
			if(imprimirLocalidades(localidades, lenLocalidades)==0)
			{
				if(utn_getNumeroEntero(&listaZona[indexLibre].idLocalidad, "Ingrese localidad: ", "ERROR. LOCALIDAD INVALIDA", 1, 8, 3)==-1)
				{
					printf("La localidad NO fue cargada con exito");
				}
			}

			listaZona[indexLibre].estadoZona=PENDIENTE;
			listaZona[indexLibre].isEmpty=CARGADO;
			retorno=0;
		}
	}

	return retorno;
}
int imprimirZona(Zona* listaZona, int lenZona, Localidad* localidades, int lenLocalidades, Censista* listaCensistas, int lenCensista)
{
	int retorno=-1;
	char auxiliarEstadoZona[50];

	if(listaZona!=NULL && lenZona>0 && listaCensistas!=NULL && lenCensista>0 &&localidades!=NULL && lenLocalidades>0)
	{

			for(int i=0;i<lenZona;i++)
			{
				for(int j=0;j<lenCensista;j++)
				{
					for(int k=0;k<lenLocalidades;k++)
					{
						switch(listaZona[i].estadoZona)
						{
							case PENDIENTE:
								strcpy(auxiliarEstadoZona, "Pendiente");
								break;
							case FINALIZADO:
								strcpy(auxiliarEstadoZona, "Finalizado");
								break;
						}

						if(listaZona[i].isEmpty==CARGADO && listaCensistas[j].estadoCensista==ACTIVO && listaZona[i].idLocalidad==localidades[k].idLocalidades && listaZona[i].idCensista==listaCensistas[j].idCensista)
						{
							printf("%-5d %-15s %-15s %s-%s-%-s-%-s %15s %15s\n", listaZona[i].idZona, localidades[i].localidades, auxiliarEstadoZona,
									listaZona[i].calles[0], listaZona[i].calles[1], listaZona[i].calles[2],listaZona[i].calles[3], listaCensistas[j].apellido, listaCensistas[j].nombre);
						}
						else
						{
							printf("%-5d %-15s %-15s %s-%s-%-s-%-s \n", listaZona[i].idZona, localidades[i].localidades, auxiliarEstadoZona,
																listaZona[i].calles[0], listaZona[i].calles[1], listaZona[i].calles[2],listaZona[i].calles[3]);
						}
					}
				}


			retorno=0;
		}

	}

	return retorno;
}
int buscarEspacioLibreZona(Zona* listaZona, int len)
{
	int retorno=-1;
	if (listaZona!=NULL && len>0)
	{
		for (int i=0; i<len; i++)
		{
			if (listaZona[i].isEmpty==VACIO)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}
int buscarZonaPorId(Zona* listaZona, int len,int id)
{
	int retorno=-1;
	if (listaZona!=NULL && len>0 && id>0)
	{
		for (int i=0; i<len; i++)
		{
			if (listaZona[i].idZona==id && listaZona[i].isEmpty==CARGADO)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}
int asignarZona(Zona* listaZona, int lenZona, Censista* listaCensistas, int lenCensista, Localidad* localidades, int lenLocalidades)
{
	int retorno=-1;
	int idCensista;
	int idZona;
	int indexCensista;
	int indexZona;

	if(listaZona!=NULL && lenZona>0 && listaCensistas!=NULL && lenCensista>0 && localidades!=NULL && lenLocalidades>0)
	{
		imprimirCensista(listaCensistas, lenCensista);
		if(utn_getNumeroEntero(&idCensista, "Ingrese el ID del Censista a asignar una zona: ", "ERROR. ID INVALIDO", 1001, 1005, 3)==0)
		{
			indexCensista=buscarCensistaPorId(listaCensistas, lenCensista, idCensista);
			imprimirZona(listaZona, lenZona, localidades, lenLocalidades, listaCensistas, lenCensista);
			if(utn_getNumeroEntero(&idZona, "Ingrese el ID de la zona a asignar al Censista: ", "ERROR. ID INVALIDO", 4001, 4005, 3)==0)
			{
				indexZona=buscarZonaPorId(listaZona, lenZona, idZona);
				listaCensistas[indexCensista].idZona=listaZona[indexZona].idZona;
				listaCensistas[indexCensista].estadoCensista=ACTIVO;
				listaZona[indexZona].idCensista=listaCensistas[indexCensista].idCensista;
				retorno=0;
			}
		}

	}

	return retorno;
}
