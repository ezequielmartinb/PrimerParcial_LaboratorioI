#ifndef DIRECCION_H_
#define DIRECCION_H_
typedef struct{

	char direccion[50];
	int altura;

}Direccion;
int utn_getDireccion(char cadena[], int len, char mensaje[], char mensajeError[], int reintentos);
int utn_validarSiEsUnaDireccion(char cadena[]);


#endif /* DIRECCION_H_ */
