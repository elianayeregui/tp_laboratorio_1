/*
 * operacionesMatematicas.h
 *
 *  Created on: 12 abr. 2022
 *      Author: Intel
 */

#ifndef OPERACIONESMATEMATICAS_H_
#define OPERACIONESMATEMATICAS_H_

/**
 * Esta función realiza la suma de dos variables
 * @fn int operacionesMatematicasSuma(float, float, float*)
 * @brief
 *
 * @param a
 * @param b
 * @param resultadoSuma
 * @return retorna 0 si la función es correcta, y -1 si hubo algún error
 */
int operacionesMatematicasSuma(float a, float b, float*resultadoSuma);


/**
 * Esta función realiza la resta de dos variables
 * @fn int operacionesMatematicasResta(float, float, float*)
 * @brief
 *
 * @param a
 * @param b
 * @param resultadoResta
 * @return retorna 0 si la función es correcta, y -1 si hubo algún error
 */
int operacionesMatematicasResta(float a, float b, float*resultadoResta);


/**
 * Esta función realiza la multiplicación de dos variables
 * @fn int operacionesMatematicasMultiplicacion(float, float, float*)
 * @brief
 *
 * @param a
 * @param b
 * @param resultadoMultiplicacion
 * @return retorna 0 si la función es correcta, y -1 si hubo algún error
 */
int operacionesMatematicasMultiplicacion(float a, float b, float*resultadoMultiplicacion);


/**
 * Esta función realiza la división de dos variables, no permite dividir por 0
 * @fn int operacionesMatematicasDivision(float, float, float*)
 * @brief
 *
 * @param a
 * @param b
 * @param resultadoDivision
 * @return retorna 0 si la función es correcta, y -1 si hubo algún error
 */
int operacionesMatematicasDivision(float a, float b, float*resultadoDivision);


/**
 * Esta función realiza el porcentaje de un número
 * @fn int operacionesMatematicasPorcentaje(float, float, float*)
 * @brief
 *
 * @param a
 * @param b
 * @param resultadoPorcentaje
 * @return retorna 0 si la función es correcta, y -1 si hubo algún error
 */
int operacionesMatematicasPorcentaje(float a, float b, float*resultadoPorcentaje);


/**
 * Esta función realiza el pasaje de peso a bitcoin
 * @fn int operacionesMatematicasBitcoin(float, float*)
 * @brief
 *
 * @param peso
 * @param resultadoBitcoin
 * @return retorna 0 si la función es correcta, y -1 si hubo algún error
 */
int operacionesMatematicasBitcoin(float peso, float*resultadoBitcoin);


#endif /* OPERACIONESMATEMATICAS_H_ */
