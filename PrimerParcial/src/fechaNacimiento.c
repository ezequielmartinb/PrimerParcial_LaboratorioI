#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"
//#include "censista.h"
#include "fechaNacimiento.h"
// OBTENER FECHA COMO STRING
int utn_getFechaString(char cadena[], int len, char mensaje[], char mensajeError[], int reintentos)
{
	int retorno;
	char auxiliar[256];

	if(cadena!=NULL && len>0 && mensaje!=NULL && reintentos>0)
	{
		while(reintentos>0)
		{
			printf("%s", mensaje);
			if(utn_myGets(auxiliar, 256)==0 && utn_validarFecha(auxiliar, 256)==0/*ACA VAN LAS VALIDACIONES DE LA FECHA*/)
			{
				retorno=0;
				strcpy(cadena, auxiliar);
				break;
			}
			else
			{
				retorno=-1;

			}
			printf("%s. ", mensajeError);
			printf("Cantidad de reintentos: %d\n", reintentos);
			reintentos--;
		}


	}
	return retorno;
}
int utn_validarFecha(char cadena[], int len)
{
	int retorno=0;// PARTO DE LA BASE DE QUE LA CADENA QUE RECIBO ES UNA FECHA
	int i=0;

	if(cadena!=NULL)
	{
		while(cadena[i]!='\0')
		{
			if(cadena[2]!='/' && cadena[5]!='/' && strlen(cadena)!=10)
			{
				retorno=-1;// INDICO QUE NO ES UNA FECHA PORQUE FALTAN LOS /
				break;
			}
			if(cadena[0]>'3' || (cadena[0]=='3' && cadena[1]>'1') || cadena[3]>'1' || (cadena[3]=='1' && cadena[4]>'2') || cadena[6]>'2'
			|| (cadena[6]=='2' && cadena[8]>'2') || (cadena[6]=='2' && cadena[8]=='2' && cadena[9]>'2')
			|| (cadena[6]=='1' && cadena[7]=='9' && cadena[8]=='2' && cadena[9]<'4')
			|| (cadena[6]=='1' && cadena[7]=='9' && cadena[8]<'2') || (cadena[6]=='1' && cadena[7]<'9')
			|| (cadena[0]=='0' && cadena[1]=='0') || (cadena[3]=='0' && cadena[4]=='0') || (cadena[6]=='0' && cadena[7]=='0'))
			{
				retorno=-2; // INDICO QUE HUBO UN ERROR EN LA CARGA DE NUMEROS:
						    // NO EXISTE UN DIA MAYOR A 31;
						    // NO EXISTE UN MES MAYOR A 12;
							// NO EXISTE UN AÑO MAYOR A 2022 NI MENOR A 1923
			}
			if( (cadena[3]=='0' && cadena[4]=='2' && (cadena[0]=='2' && cadena[1]>'8')) ||
				(cadena[3]=='0' && cadena[4]=='4' && (cadena[0]=='3' && cadena[1]>'0')) ||
				(cadena[3]=='0' && cadena[4]=='6' && (cadena[0]=='3' && cadena[1]>'0')) ||
				(cadena[3]=='0' && cadena[4]=='9' && (cadena[0]=='3' && cadena[1]>'0')) ||
				(cadena[3]=='1' && cadena[4]=='1' && (cadena[0]=='3' && cadena[1]>'0')))
			{
				retorno=-3; // INDICO QUE EN FEBRERO NO PUEDE HABER UN DIA MAYOR A 28
							// Y QUE EN ABRIL, JUNIO, SEPTIEMBRE Y NOVIEMBRE NO PUEDE HABER UN DIA MAYOR A 30
			}
			i++;
		}
	}

	return retorno;
}
// OBTENER FECHA COMO INT
int utn_getFechaInt(int* dia, int* mes, int* anio)
{
	int retorno;
    if(dia!=NULL && mes!=NULL && anio!=NULL)
    {
    	if(utn_getNumeroEntero(mes, "Ingrese el MES de nacimiento: ", "ERROR. MES INVALIDO. ", 1, 12, 3)==-1)
		{
			printf("El mes NO fue ingresado de forma valida\n");
		}
    	if(*mes==2)
    	{
    		if(utn_getNumeroEntero(dia, "Ingrese el DIA de nacimiento: ", "ERROR. DIA INVALIDO. ", 1, 28, 3)==-1)
			{
				printf("El dia NO fue ingresado de forma valida\n");
			}
    	}
    	else
    	{
    		if((*mes==4 || *mes==6 || *mes==9 || *mes==11))
			{
				if(utn_getNumeroEntero(dia, "Ingrese el DIA de nacimiento: ", "ERROR. DIA INVALIDO. ", 1, 30, 3)==-1)
				{
					printf("El dia NO fue ingresado de forma valida\n");
				}
			}
    		else
    		{
    			if(utn_getNumeroEntero(dia, "Ingrese el DIA de nacimiento: ", "ERROR. DIA INVALIDO. ", 1, 31, 3)==-1)
				{
					printf("El dia NO fue ingresado de forma valida\n");
				}
    		}
    	}

    	if(utn_getNumeroEntero(anio, "Ingrese el ANIO de nacimiento: ", "ERROR. ANIO INVALIDO. ", 1923, 2004, 3)==-1)
		{
			printf("El anio NO fue ingresado de forma valida\n");
		}
    	retorno=0;
    }
    return retorno;
}
