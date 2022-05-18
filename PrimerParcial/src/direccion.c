#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"
//#include "censista.h"
//#include "fechaNacimiento.h"
#include "direccion.h"
// OBTENER DIRECCION
int utn_getDireccion(char cadena[], int len, char mensaje[], char mensajeError[], int reintentos)
{
	int retorno=-1;
	char auxiliar[256];

	if(cadena!=NULL && len>0 && mensaje!=NULL && mensajeError!=NULL && reintentos>0)
	{
		while(reintentos>0)
		{
			printf("%s", mensaje);
			if(utn_myGets(auxiliar, 256)==0 && utn_validarSiEsUnaDireccion(auxiliar)==1 && utn_validarSiEsNumericoEnCadena(auxiliar)==1 && utn_formatearNombre(auxiliar,256)==1)
			{
				retorno=0;
				strncpy(cadena, auxiliar, len);
				//printf("El nombre se copio con exito\n");
				break;
			}
			else
			{
				retorno=-1;
				//printf("No se pudo copiar el nombre\n");
			}
			printf("%s. ", mensajeError);
			printf("Cantidad de reintentos: %d\n", reintentos);
			reintentos--;
		}
	}

	return retorno;
}
int utn_validarSiEsUnaDireccion(char cadena[])
{
	int retorno=1;
	int contadorEspacios=0;
	int i=0;
	if(cadena!=NULL)
	{
		while(cadena[i]!='\0')
		{
			if(cadena[i]==' ')
			{
				contadorEspacios++;
				//printf("LA CANTIDAD DE ESPACIOS ES: %d\n", contadorEspacios);
			}
			if(((cadena[i]<'A' || cadena[i]>'Z') || (cadena[i]<'a' && cadena[i]>'z')) && contadorEspacios>=4)
			{
				retorno=-1;
				break;
			}
			i++;
		}
	}
	return retorno;
}
