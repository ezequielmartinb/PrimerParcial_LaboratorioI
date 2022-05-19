/*
 * informes.h
 *
 *  Created on: 19 may. 2022
 *      Author: Ezequiel
 */

#ifndef INFORMES_H_
#define INFORMES_H_

int cantidadCensistasActivosConZonaPendiente(Censista* listaCensistas, int lenCensista, Zona* listaZona, int lenZona, int* contadorCensistasActivosConZonaPendiente);
int mostrarCensistasPorLocalidad(Censista* listaCensistas, int lenCensista, Zona* listaZona, int lenZona, Localidad* listaLocalidades, int lenLocalidades, char localidad[]);
int localidadConMasCasasAusentes(Zona* listaZona, int lenZona, Localidad* listaLocalidades, int lenLocalidades, CargaDatos* listaCargarDatos, int lenCargarDatos, int* cantidadMaximaAusentes, char* localidadMaximaAusentes);

#endif /* INFORMES_H_ */
