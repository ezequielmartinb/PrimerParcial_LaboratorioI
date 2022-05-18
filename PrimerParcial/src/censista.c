#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"
#include "censista.h"
#include "direccion.h"
#include "fechaNacimiento.h"

#define VACIO 1
#define CARGADO 0

#define ACTIVO 1
#define INACTIVO 2
#define LIBERADO 3

int inicializarCensistas(Censista* listaCensista, int len)
{
	int retorno=-1;

	if(listaCensista!=NULL && len>0)
	{
		for (int i=0; i<len; i++)
		{
			retorno=0;
			listaCensista[i].isEmpty=VACIO;
			listaCensista[i].idZona=0;
		}
	}
	return retorno;
}
int incrementarIdCensista()
{
	static int IdCensista=1000;

	IdCensista++;

	return IdCensista;
}
int buscarEspacioLibre(Censista* listaCensista, int len)
{
	int retorno=-1;
	if (listaCensista!=NULL && len>0)
	{
		for (int i=0; i<len; i++)
		{
			if (listaCensista[i].isEmpty==VACIO)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}
int imprimirCensista(Censista* listaCensista, int len)
{
	int retorno=-1;
	char auxiliarEstadoCensista[50];

	if(listaCensista!=NULL && len>0)
	{
		for(int i=0;i<len;i++)
		{
			switch(listaCensista[i].estadoCensista)
			{
			case ACTIVO:
				strcpy(auxiliarEstadoCensista, "Activo");
				break;
			case INACTIVO:
				strcpy(auxiliarEstadoCensista, "Inactivo");
				break;
			case LIBERADO:
				strcpy(auxiliarEstadoCensista, "Liberado");
				break;
			}
			if(listaCensista[i].isEmpty==CARGADO)
			{
				printf("%4d %15s %-15s %d/%d/%d %15d %15s %15d %15s\n", listaCensista[i].idCensista, listaCensista[i].apellido, listaCensista[i].nombre,
						listaCensista[i].fechaNacimientoCensista.dia,listaCensista[i].fechaNacimientoCensista.mes, listaCensista[i].fechaNacimientoCensista.anio,listaCensista[i].fechaNacimientoCensista.edad,
						listaCensista[i].direccionCensista.direccion, listaCensista[i].direccionCensista.altura, auxiliarEstadoCensista);
			}
		}
		retorno=0;
	}

	return retorno;
}
int cargarCensista(Censista* listaCensista, int len)
{
	int retorno=-1;
	int indexLibre;
	int edadQueDebeIngresar;

	if(listaCensista!=NULL && len>0)
	{
		retorno=0;
		indexLibre=buscarEspacioLibre(listaCensista, len);
		if(indexLibre!=-1)
		{
			listaCensista[indexLibre].idCensista=incrementarIdCensista();
			if(utn_getNombre(listaCensista[indexLibre].nombre, 50, "Ingrese el nombre del censista: ", "ERROR. NOMBRE INVALIDO. ", 3)==-1)
			{
				printf("El nombre NO fue cargado con exito\n");
				retorno=-1;
			}
			if(utn_getNombre(listaCensista[indexLibre].apellido, 50, "Ingrese el apellido del censista: ", "ERROR. APELLIDO INVALIDO. ", 3)==-1)
			{
				printf("El apellido NO fue cargado con exito\n");
				retorno=-1;
			}
			// CARGAR FECHA NACIMIENTO
			printf("***********FECHA DE NACIMIENTO***********\n");
			if(utn_getFechaInt(&listaCensista[indexLibre].fechaNacimientoCensista.dia, &listaCensista[indexLibre].fechaNacimientoCensista.mes, &listaCensista[indexLibre].fechaNacimientoCensista.anio)==-1)
			{
				printf("La fecha NO fue cargado con exito\n");
				retorno=-1;
			}
			edadQueDebeIngresar=2022-listaCensista[indexLibre].fechaNacimientoCensista.anio;
			if(utn_getNumeroEntero(&listaCensista[indexLibre].fechaNacimientoCensista.edad, "Ingrese la edad del censista: ", "ERROR. EDAD INVALIDA. ", 18, 99, 3)==-1 || listaCensista[indexLibre].fechaNacimientoCensista.edad!=edadQueDebeIngresar)
			{
				printf("La edad NO fue cargada con exito\n");
				retorno=-1;
			}
			if(utn_getDireccion(listaCensista[indexLibre].direccionCensista.direccion, 50, "Ingrese el nombre de la direccion: ", "ERROR. DIRECCION ERRONEA. ", 3)==-1)
			{
				printf("La direccion NO fue cargada con exito\n");
				retorno=-1;
			}
			if(utn_getNumeroEntero(&listaCensista[indexLibre].direccionCensista.altura, "Ingrese la altura de la direccion: ", "ERROR. ALTURA INVALIDA", 1, 10000, 3)==-1)
			{
				printf("La altura NO fue cargada con exito\n");
				retorno=-1;
			}
			if(retorno==0)
			{
				listaCensista[indexLibre].estadoCensista=LIBERADO;
				listaCensista[indexLibre].isEmpty=CARGADO;
			}

		}
	}

	return retorno;
}
int buscarCensistaPorId(Censista* listaCensista, int len,int id)
{
	int retorno=-1;
	if (listaCensista!=NULL && len>0 && id>0)
	{
		for (int i=0; i<len; i++)
		{
			if (listaCensista[i].idCensista==id && listaCensista[i].isEmpty==CARGADO)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}
int modificarCensista(Censista* listaCensista, int len, int id)
{
	int retorno=-1;
	int index;
	int opcion;
	int opcionFecha;
	int opcionDireccion;
	char deseaSeguirModificando;

	if(listaCensista!=NULL && len>0 && id>0)
	{
		imprimirCensista(listaCensista, len);
		index=buscarCensistaPorId(listaCensista, len, id);
		if(index!=-1)
		{
			while(deseaSeguirModificando!='N')
			{
				if(utn_getNumeroEntero(&opcion, "Que desea modificar?\n \t1-NOMBRE\n\t2-APELLIDO\n\t3-FECHA DE NACIMIENTO\n\t4-EDAD\n\t5-DIRECCION\n Ingrese una opcion: ", "ERROR. OPCION INVALIDA. ", 1, 6, 3)==0)
				{
					switch(opcion)
					{
						case 1:
							if(utn_getNombre(listaCensista[index].nombre, 51, "Ingrese el NUEVO nombre del censista: ", "ERROR. NOMBRE INVALIDO. ", 3)==-1)
							{
								printf("El nombre NO fue cargado con exito\n");
								break;
							}
							break;
						case 2:
							if(utn_getNombre(listaCensista[index].apellido, 51, "Ingrese el NUEVO apellido del censista: ", "ERROR. APELLIDO INVALIDO. ", 3)==-1)
							{
								printf("El apellido NO fue cargado con exito\n");
								break;
							}
							break;
						case 3:
							if(utn_getNumeroEntero(&opcionFecha, "Que desea modificar?\n \t1-DIA\n\t2-MES\n\t3-ANIO\nIngrese una opcion: ", "ERROR. OPCION INVALIDA. ", 1, 3, 3)==0)
							{
								switch(opcionFecha)
								{
									case 1:
										if(listaCensista[index].fechaNacimientoCensista.mes==2)
										{
												if(utn_getNumeroEntero(&listaCensista[index].fechaNacimientoCensista.dia, "Ingrese el nuevo DIA: ", "ERROR. DIA ERRONEO", 1, 28, 3)==-1)
												{
													printf("El dia de la fecha de nacimiento no fue modificada con exito\n");
												}
										}
										else
										{
											if(listaCensista[index].fechaNacimientoCensista.mes==4 || listaCensista[index].fechaNacimientoCensista.mes==6 || listaCensista[index].fechaNacimientoCensista.mes==9 || listaCensista[index].fechaNacimientoCensista.mes==11)
											{
												if(utn_getNumeroEntero(&listaCensista[index].fechaNacimientoCensista.dia, "Ingrese el nuevo DIA: ", "ERROR. DIA ERRONEO", 1, 30, 3)==-1)
												{
													printf("El dia de la fecha de nacimiento no fue modificada con exito\n");
												}
											}
											else
											{
												if(utn_getNumeroEntero(&listaCensista[index].fechaNacimientoCensista.dia, "Ingrese el nuevo DIA: ", "ERROR. DIA ERRONEO", 1, 31, 3)==-1)
												{
													printf("El dia de la fecha de nacimiento no fue modificada con exito\n");
												}
											}
										}

										break;
									case 2:
										if(listaCensista[index].fechaNacimientoCensista.mes<=28)
										{
											if(utn_getNumeroEntero(&listaCensista[index].fechaNacimientoCensista.mes, "Ingrese el nuevo MES: ", "ERROR. DIA ERRONEO", 2, 2, 3)==-1)
											{
												printf("El dia de la fecha de nacimiento no fue modificada con exito\n");
											}
										}
										else
										{
											if(listaCensista[index].fechaNacimientoCensista.mes>=30)
											{
												if(utn_getNumeroEntero(&listaCensista[index].fechaNacimientoCensista.mes, "Ingrese el nuevo MES: ", "ERROR. DIA ERRONEO", 1, 12, 3)==-1)
												{
													printf("El dia de la fecha de nacimiento no fue modificada con exito\n");
												}
											}
										}
										break;
									case 3:
										if(utn_getNumeroEntero(&listaCensista[index].fechaNacimientoCensista.anio, "Ingrese el nuevo ANIO de nacimiento: ", "ERROR. ANIO INVALIDO. ", 1923, 2004, 3)==-1)
										{
											printf("El anio NO fue ingresado de forma valida\n");
										}
										break;
								}
							}
							break;
						case 4:
							if(utn_getNumeroEntero(&listaCensista[index].fechaNacimientoCensista.edad, "Ingrese la NUEVA edad del censista: ", "ERROR. EDAD INVALIDA. ", 18, 99, 3)==-1)
							{
								printf("La edad NO fue cargada con exito\n");
								break;
							}
							break;
						case 5:
							if(utn_getNumeroEntero(&opcionDireccion, "Que desea modificar de la DIRECCION?\n \t1-NOMBRE DIRECCION\n\t2-ALTURA DIRECCION\n\nIngrese una opcion: ", "ERROR. OPCION INVALIDA. ", 1, 2, 3)==0)
							{
								switch(opcionDireccion)
								{
								case 1:
									if(utn_getNombre(listaCensista[index].direccionCensista.direccion, 50, "Ingrese el NUEVO nombre de la direccion del censista: ", "ERROR. DIRECCION INVALIDA. ", 3)==-1)
									{
										printf("La direccion NO fue cargada con exito\n");
										break;
									}
									break;
								case 2:
									if(utn_getNumeroEntero(&listaCensista[index].direccionCensista.altura, "Ingrese la altura de la direccion: ", "ERROR. ALTURA INVALIDA", 1, 10000, 3)==-1)
									{
										printf("La altura NO fue cargada con exito\n");
										break;
									}
									break;
								}
							}
							break;
					}
				}

				if(utn_getUnCaracter(&deseaSeguirModificando, "Desea realizar alguna otra modificacion? Y/N ", "ERROR. INGRESE UNA OPCION VALIDA. ", 'N', 'Y', 3)==-1)
				{
					printf("ERROR.\n");
				}

			}
			retorno=0;
		}
	}

	return retorno;
}
int existeCensistaPorId(Censista* listaCensista, int len, int id)
{
	int retorno=-1;

		if(listaCensista!=NULL && len>0)
		{
			for(int i=0; i<len; i++)
			{
				if(listaCensista[i].isEmpty==0 && listaCensista[i].idCensista==id)
				{
					retorno=0;
					break;
				}
			}
		}
	return retorno;
}
int bajaCensista(Censista* listaCensista, int len, int id)
{
	int retorno=-1;
	int index;
	char estaSeguro;
	if (listaCensista!=NULL && len>0)
	{
		imprimirCensista(listaCensista, len);
		if(utn_getNumeroEntero(&id, "Ingrese el ID que desea dar de baja: ", "ERROR. ID INVALIDO", 1001, 1005, 3)==0)
		{
			index=buscarCensistaPorId(listaCensista, len, id);
			if(index!=-1 && listaCensista[index].idZona==0)
			{
				printf("%4d %15s %-15s %d/%d/%d %15d %15s %15d\n", listaCensista[index].idCensista, listaCensista[index].apellido, listaCensista[index].nombre,
						listaCensista[index].fechaNacimientoCensista.dia,listaCensista[index].fechaNacimientoCensista.mes, listaCensista[index].fechaNacimientoCensista.anio,listaCensista[index].fechaNacimientoCensista.edad, listaCensista[index].direccionCensista.direccion, listaCensista[index].direccionCensista.altura);
				if(utn_getUnCaracter(&estaSeguro, "Está seguro que desea eliminar este Censista? Y/N ", "ERROR. INGRESE UNA OPCION VALIDA. ", 'N', 'Y', 3)==0 && estaSeguro=='Y')
				{
					listaCensista[index].isEmpty=VACIO;
					listaCensista[index].estadoCensista=INACTIVO;
					retorno = 0;
				}
			}
		}

	}
	return retorno;
}
