#ifndef LOCALIDADES_H_
#define LOCALIDADES_H_

typedef struct
{
	int idLocalidades;
	char localidades[50];

}Localidad;
int imprimirLocalidades(Localidad* localidades, int len);
#endif /* LOCALIDADES_H_ */

