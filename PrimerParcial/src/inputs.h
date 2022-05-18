#ifndef INPUTS_H_
#define INPUTS_H_
// PEDIR UN CARACTER
/// @brief Funcion para pedir un caracter
///
/// @pre
/// @post
/// @param unCaracter char*
/// @param mensaje char*
/// @param mensajeError char*
/// @param minimo char
/// @param maximo char
/// @param reintentos int
/// @return retorna 0 en caso de EXITO y -1 en caso de ERROR
int utn_getUnCaracter(char* unCaracter, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);
// PEDIR STRING

/// @brief Funciona para pedir un string validado
///
/// @pre
/// @post
/// @param cadena[] char
/// @param len int
/// @param mensaje[] char
/// @param mensajeError[] char
/// @param reintentos int
/// @return
int utn_getString(char cadena[], int len, char mensaje[], char mensajeError[], int reintentos);
/// @brief Funcion para validar que la cadena que se ingresa no desborde el tamaño de la variable a escribir
///
/// @pre
/// @post
/// @param cadena[] char
/// @param len int
/// @return retorna 0 en caso de EXITO y -1 en caso de ERROR
int utn_myGets(char cadena[], int len);
// OBTENER NUMERO ENTEROS (NEGATIVOS Y POSITIVOS)

/// @brief  Funciona para pedir un numero entero validado
///
/// @pre
/// @post
/// @param pNumeroIngresado int*
/// @param mensaje char*
/// @param mensajeError char*
/// @param minimo int
/// @param maximo int
/// @param reintentos int
/// @return retorna 0 en caso de EXITO y -1 en caso de ERROR
int utn_getNumeroEntero(int* pNumeroIngresado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
/// @brief Funcion que evalua si la cadena contiene numeros
///
/// @pre
/// @post
/// @param caden[] char
/// @return retorna 1 en caso de ser numerica la cadena; retorna 0 si no hay numeros y -1 en caso de ERROR
int utn_validarSiEsNumerico(char cadena[]);
/// @brief Funcion que evalua si la cadena contiene letras
///
/// @pre
/// @post
/// @param cadena[] char
/// @return retorna 1 en caso de que hayan solo letras en la cadena; retorna 0 si no hay letras y -1 en caso de ERROR
int utn_validarSiSonLetras(char cadena[]);
// OBTENER NUMERO FLOTANTES (NEGATIVOS Y POSITIVOS)
/// @brief  Funcion para pedir un numero flotante validado
///
/// @pre
/// @post
/// @param pNumeroIngresado float*
/// @param mensaje char*
/// @param mensajeError char*
/// @param minimo int
/// @param maximo int
/// @param reintentos int
/// @return retorna 0 en caso de EXITO y -1 en caso de ERROR
int utn_getNumeroFlotante(float* pNumeroIngresado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
/// @brief Funcion que evalua si la cadena son letras
///
/// @pre
/// @post
/// @param cadena[] char
/// @return retorna 0 en caso de EXITO y -1 en caso de ERROR
int utn_validarSiSonLetrasFlotantes(char cadena[]);
/// @brief Funcion que evalua si se ingreso un numero flotante en la cadena
///
/// @pre
/// @post
/// @param cadena[] char
/// @return retorna 1 en caso de EXITO y -1 en caso de ERROR
int utn_validarSiEsNumericoFlotante(char cadena[]);
// OBTENER NOMBRES
/// @brief Funcion que valida un nombre valido
///
/// @pre
/// @post
/// @param cadena[] char
/// @param len int
/// @param mensaje[] char
/// @param mensajeError[] char
/// @param reintentos int
/// @return retorna 0 en caso de EXITO y -1 en caso de ERROR
int utn_getNombre(char cadena[], int len, char mensaje[], char mensajeError[], int reintentos);

/// @brief Funcion que valida si la cadena es un nombre compuesto o no
///
/// @pre
/// @post
/// @param cadena[] char
/// @return retorna 1 si el nombre es VALIDO y -1 si no lo es
int utn_validarSiEsUnNombreCompuesto(char cadena[]);
/// @brief Funcion para validar si la cadena tiene numeros
///
/// @pre
/// @post
/// @param cadena[] char
/// @return Retorna 0 si TIENE NUMERO LA CADENA; -1 si hubo un error y 1 si la cadena no tiene numeros
int utn_validarSiEsNumericoEnCadena(char cadena[]);
/// @brief Funcion que formatea un nombre de forma correcta (inicial en mayuscula y el resto en minusculas)
///
/// @pre
/// @post
/// @param cadena[] char
/// @param len int
/// @return retorna 1 en caso de EXITO y -1 en caso de ERROR
int utn_formatearNombre(char cadena[], int len);
int utn_getFecha(char cadena[], int len, char mensaje[], char mensajeError[], int reintentos);
int utn_validarFecha(char cadena[], int len);

#endif /* INPUTS_H_ */
