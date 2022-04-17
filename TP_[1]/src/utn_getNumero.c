/*
 * utn_getNumero.c
 *
 *  Created on: 11 abr. 2022
 *      Author: Intel
 */

#include <stdio.h>
#include <stdlib.h>

int utn_getNumero_Int(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno=-1;
	int buffer;

	if (pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo < maximo && reintentos > 0)
	{
		do
		{
			printf("%s", mensaje);
			scanf("%d", &buffer);
			if (buffer>minimo && buffer<maximo)
			{
				*pResultado=buffer;
				retorno=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>0);
	}
	return retorno;
}

float utn_get_Float(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno=-1;
	float bufferFloat;

	if (pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo < maximo && reintentos > 0)
	{
		do
		{
			printf("%s", mensaje);
			scanf("%f", &bufferFloat);
			if (bufferFloat>minimo && bufferFloat<maximo)
			{
				*pResultado=bufferFloat;
				retorno=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>0);
	}
	return retorno;
}

