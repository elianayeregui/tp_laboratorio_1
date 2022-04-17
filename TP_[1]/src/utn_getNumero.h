/*
 * utn_getNumero.h
 *
 *  Created on: 11 abr. 2022
 *      Author: Intel
 */

#ifndef UTN_GETNUMERO_H_
#define UTN_GETNUMERO_H_

/**
 * Esta funcion retorna un numero int, solicitado al usuario, según los parámetros indicados
 * @fn int utn_getNumero_Int(int*, char*, char*, int, int, int)
 * @brief
 *
 * @param pResultado
 * @param mensaje
 * @param mensajeError
 * @param minimo
 * @param maximo
 * @param reintentos
 * @return retorna 0 si la función es correcta, y -1 si hubo algún error
 */
int utn_getNumero_Int(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);


/**
 * Esta funcion retorna un numero float, solicitado al usuario, según los parámetros indicados
 * @fn float utn_get_Float(float*, char*, char*, float, float, int)
 * @brief
 *
 * @param pResultado
 * @param mensaje
 * @param mensajeError
 * @param minimo
 * @param maximo
 * @param reintentos
 * @return retorna 0 si la función es correcta, y -1 si hubo algún error
 */
float utn_get_Float(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);


#endif /* UTN_GETNUMERO_H_ */
