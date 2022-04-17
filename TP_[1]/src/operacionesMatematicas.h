/*
 * operacionesMatematicas.h
 *
 *  Created on: 12 abr. 2022
 *      Author: Intel
 */

#ifndef OPERACIONESMATEMATICAS_H_
#define OPERACIONESMATEMATICAS_H_

/**
 * Esta funci�n realiza la suma de dos variables
 * @fn int operacionesMatematicasSuma(float, float, float*)
 * @brief
 *
 * @param a
 * @param b
 * @param resultadoSuma
 * @return retorna 0 si la funci�n es correcta, y -1 si hubo alg�n error
 */
int operacionesMatematicasSuma(float a, float b, float*resultadoSuma);


/**
 * Esta funci�n realiza la resta de dos variables
 * @fn int operacionesMatematicasResta(float, float, float*)
 * @brief
 *
 * @param a
 * @param b
 * @param resultadoResta
 * @return retorna 0 si la funci�n es correcta, y -1 si hubo alg�n error
 */
int operacionesMatematicasResta(float a, float b, float*resultadoResta);


/**
 * Esta funci�n realiza la multiplicaci�n de dos variables
 * @fn int operacionesMatematicasMultiplicacion(float, float, float*)
 * @brief
 *
 * @param a
 * @param b
 * @param resultadoMultiplicacion
 * @return retorna 0 si la funci�n es correcta, y -1 si hubo alg�n error
 */
int operacionesMatematicasMultiplicacion(float a, float b, float*resultadoMultiplicacion);


/**
 * Esta funci�n realiza la divisi�n de dos variables, no permite dividir por 0
 * @fn int operacionesMatematicasDivision(float, float, float*)
 * @brief
 *
 * @param a
 * @param b
 * @param resultadoDivision
 * @return retorna 0 si la funci�n es correcta, y -1 si hubo alg�n error
 */
int operacionesMatematicasDivision(float a, float b, float*resultadoDivision);


/**
 * Esta funci�n realiza el porcentaje de un n�mero
 * @fn int operacionesMatematicasPorcentaje(float, float, float*)
 * @brief
 *
 * @param a
 * @param b
 * @param resultadoPorcentaje
 * @return retorna 0 si la funci�n es correcta, y -1 si hubo alg�n error
 */
int operacionesMatematicasPorcentaje(float a, float b, float*resultadoPorcentaje);


/**
 * Esta funci�n realiza el pasaje de peso a bitcoin
 * @fn int operacionesMatematicasBitcoin(float, float*)
 * @brief
 *
 * @param peso
 * @param resultadoBitcoin
 * @return retorna 0 si la funci�n es correcta, y -1 si hubo alg�n error
 */
int operacionesMatematicasBitcoin(float peso, float*resultadoBitcoin);


#endif /* OPERACIONESMATEMATICAS_H_ */
