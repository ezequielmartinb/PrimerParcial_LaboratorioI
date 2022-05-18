#ifndef FECHANACIMIENTO_H_
#define FECHANACIMIENTO_H_

typedef struct{

	int dia;
	int mes;
	int anio;
	int edad;

}Fecha;
int utn_getFechaInt(int* dia, int* mes, int* anio);
int utn_getFechaString(char cadena[], int len, char mensaje[], char mensajeError[], int reintentos);
int utn_validarFecha(char cadena[], int len);
#endif /* FECHANACIMIENTO_H_ */
