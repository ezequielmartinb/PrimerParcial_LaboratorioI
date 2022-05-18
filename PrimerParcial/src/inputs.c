#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"
// PEDIR UN CARACTER
int utn_getUnCaracter(char* unCaracter, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
{
	char auxiliarChar;
	int retorno=-1;

	if(unCaracter!=NULL && maximo>minimo && reintentos>=0)
	{
		while(reintentos>0)
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%c", &auxiliarChar);
			if(auxiliarChar==minimo || auxiliarChar==maximo)
			{
				*unCaracter=auxiliarChar;
				retorno=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				printf("CANTIDAD DE REINTENTOS: %d\n", reintentos);
			}
			reintentos--;
		}
	}
	return retorno;
}
// PEDIR STRING
int utn_getString(char cadena[], int len, char mensaje[], char mensajeError[], int reintentos)
{
	int retorno;
	char auxiliar[256];

	if(cadena!=NULL && len>0 && mensaje!=NULL && reintentos>0)
	{
		while(reintentos>0)
		{
			printf("%s", mensaje);
			if(utn_myGets(auxiliar, 256)==0)
			{
				retorno=0;
				strcpy(cadena, auxiliar);
				//printf("La cadena se copio con exito\n");
				break;
			}
			else
			{
				retorno=-1;
				//printf("No se pudo copiar la cadena\n");
			}
			printf("%s. ", mensajeError);
			printf("Cantidad de reintentos: %d\n", reintentos);
			reintentos--;
		}


	}
	return retorno;
}
int utn_myGets(char cadena[], int len)
{
	int retorno=-1;
	char auxiliarCadena[256]; // Esto se va a modificar cuando veamos memoria dinamica. Se le asignara un malloc

	if(cadena!=NULL && len>0)
	{
		fflush(stdin);
		if(fgets(auxiliarCadena,256,stdin)!=NULL && auxiliarCadena[strlen(auxiliarCadena)-1]=='\n')
		{
			auxiliarCadena[strlen(auxiliarCadena)-1]='\0';
			if(strlen(auxiliarCadena)<=len)
			{
				strcpy(cadena, auxiliarCadena);
				retorno=0;
			}
		}
	}
	return retorno;
}
// OBTENER NUMEROS ENTEROS
int utn_getNumeroEntero(int* pNumeroIngresado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno=-1;
	char auxiliarNumeroIngresado[256];
	int auxiliarNumeroEnteroIngresado;

	if(pNumeroIngresado!=NULL && mensaje!=NULL && mensajeError!=NULL && maximo>minimo && reintentos>0)
	{
		while(reintentos>0)
		{
			printf("%s", mensaje);
			if(utn_myGets(auxiliarNumeroIngresado, 256)==0 && utn_validarSiSonLetras(auxiliarNumeroIngresado)==0 && utn_validarSiEsNumerico(auxiliarNumeroIngresado)==1)
			{
				auxiliarNumeroEnteroIngresado=atoi(auxiliarNumeroIngresado);
				if(auxiliarNumeroEnteroIngresado>=minimo && auxiliarNumeroEnteroIngresado<=maximo)
				{
					*pNumeroIngresado=auxiliarNumeroEnteroIngresado;
					retorno=0;
					break;
				}
			}

			printf("%s", mensajeError);
			printf("Cantidad de reintentos: %d\n", reintentos);
			reintentos--;
		}
	}

	return retorno;
}
int utn_validarSiEsNumerico(char cadena[])
{
	int retorno=-1;
	int i=0;

	if(cadena!=NULL)
	{
		retorno=1;
		if(cadena[0]=='-')
		{
			i=1;
		}
		while(cadena[i]!='\0')
		{
			if(cadena[i]<'0' || cadena[i]>'9')
			{
				retorno=0;
				break;
			}
			i++;
		}
	}

	return retorno;
}
int utn_validarSiSonLetras(char cadena[])
{
	int retorno=-1;
	int i=0;
	if(cadena!=NULL)
	{
		retorno=1;
		while(cadena[i]!='\0')
		{
			if((cadena[i]<'A' || cadena[i]>'Z') && (cadena[i]<'a' || cadena[i]>'z'))
			{
				retorno=0;
				break;
			}
			i++;
		}
	}
	return retorno;
}
// OBTENER NUMEROS FLOTANTES (POSITIVOS Y NEGATIVOS)
int utn_getNumeroFlotante(float* pNumeroIngresado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno=-1;
	char auxiliarNumeroIngresado[256];
	float auxiliarNumeroEnteroIngresado;

	if(pNumeroIngresado!=NULL && mensaje!=NULL && mensajeError!=NULL && maximo>minimo && reintentos>0)
	{
		while(reintentos>0)
		{
			printf("%s", mensaje);
			if(utn_myGets(auxiliarNumeroIngresado, 256) == 0 && utn_validarSiSonLetrasFlotantes(auxiliarNumeroIngresado)==0 && utn_validarSiEsNumericoFlotante(auxiliarNumeroIngresado)==1)
			{
				auxiliarNumeroEnteroIngresado=atof(auxiliarNumeroIngresado);
				if(auxiliarNumeroEnteroIngresado>=minimo && auxiliarNumeroEnteroIngresado<=maximo)
				{
					*pNumeroIngresado=auxiliarNumeroEnteroIngresado;
					retorno=0;
					break;
				}
			}

			printf("%s", mensajeError);
			printf("Cantidad de reintentos: %d\n", reintentos);
			reintentos--;
		}
	}

	return retorno;
}
int utn_validarSiSonLetrasFlotantes(char cadena[])
{
	int retorno=-1;
	int i=0;
	int contadorPuntos=0;
	if(cadena!=NULL)
	{
		retorno=0;
		while(cadena[i]!='\0')
		{
			if(cadena[i]=='.')
			{
				contadorPuntos++;
			}
			if((cadena[i]>='A' && cadena[i]<='Z') || (cadena[i]>='a' && cadena[i]<='z') || contadorPuntos>1)
			{
				retorno=1;
				break;
			}
			i++;
		}
	}
	return retorno;
}
int utn_validarSiEsNumericoFlotante(char cadena[])
{
	int retorno=-1;
	int i=0;

	if(cadena!=NULL)
	{
		retorno=0;
		if(cadena[0]=='-')
		{
			i=1;
		}
		while(cadena[i]!='\0')
		{
			if((cadena[i]>='0' && cadena[i]<='9') || cadena[i]=='.')
			{
				retorno=1;
				break;
			}
			i++;
		}
	}

	return retorno;
}
// OBTENER UN NOMBRE
int utn_getNombre(char cadena[], int len, char mensaje[], char mensajeError[], int reintentos)
{
	int retorno=-1;
	char auxiliar[256];

	if(cadena!=NULL && len>0 && mensaje!=NULL && mensajeError!=NULL && reintentos>0)
	{
		while(reintentos>0)
		{
			printf("%s", mensaje);
			if(utn_myGets(auxiliar, 256)==0 && utn_validarSiEsUnNombreCompuesto(auxiliar)==1 && utn_validarSiEsNumericoEnCadena(auxiliar)==1 && utn_formatearNombre(auxiliar,256)==1)
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
int utn_validarSiEsUnNombreCompuesto(char cadena[])
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
			if(((cadena[i]<'A' || cadena[i]>'Z') || (cadena[i]<'a' && cadena[i]>'z')) && contadorEspacios>=2)
			{
				retorno=-1;
				break;
			}
			i++;
		}
	}
	return retorno;
}
int utn_validarSiEsNumericoEnCadena(char cadena[])
{
	int retorno=-1;
	int i=0;

	if(cadena!=NULL)
	{
		retorno=1;
		while(cadena[i]!='\0')
		{
			if(cadena[i]>='0' && cadena[i]<='9')
			{
				retorno=0;
				break;
			}
			i++;
		}
	}

	return retorno;
}
int utn_formatearNombre(char cadena[], int len)
{
	int retorno=-1;

	if(cadena!=NULL)
	{
		strlwr(cadena);
		for(int i=0;i<len;i++)
		{
			cadena[0]=toupper(cadena[0]);
			if(cadena[i]==' ')
			{
				cadena[i+1]=toupper(cadena[i+1]);
			}
			retorno=1;
		}
	}

	return retorno;

}
