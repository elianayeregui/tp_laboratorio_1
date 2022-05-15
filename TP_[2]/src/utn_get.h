/*
 * utn_get.h
 *
 *  Created on: 10 may. 2022
 *      Author: Intel
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef UTN_GET_H_
#define UTN_GET_H_

/**
 *
 *\brief Esta funcion retorna un numero int, solicitado al usuario, según los parámetros indicados
 *
 * \param pResultado
 * \param mensaje
 * \param mensajeError
 * \param minimo
 * \param maximo
 * \param reintentos
 * \return retorna 0 si la función es correcta, y -1 si hubo algún error
 */
int utn_get_Int(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);


/**
 *
 * \brief Esta funcion retorna un numero float, solicitado al usuario, según los parámetros indicados
 *
 * \param pResultado
 * \param mensaje
 * \param mensajeError
 * \param minimo
 * \param maximo
 * \param reintentos
 * \return retorna 0 si la función es correcta, y -1 si hubo algún error
 */
int utn_get_Float(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

/**
 * \brief Esta funcion retorna un string, solicitado al usuario.
 * \param pResultado
 * \param longitud
 * \param mensaje
 * \param mensajeError
 * \param reintentos
 * \return retorna 0 si la función es correcta, y -1 si hubo algún error
 *
 */
int utn_get_String(char* pResultado, int size, char* mensaje, char* mensajeError, int reintentos);

#endif /* UTN_GET_H_ */
