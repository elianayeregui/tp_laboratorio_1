/*
 * utn_get.c
 *
 *  Created on: 10 may. 2022
 *      Author: Intel
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_get.h"

//STATICS
static int esNumerica(char* cadena);
static int getInt(int* pResultado);
static int myGets(char* cadena, int size);
static int getFloat(float* pResultado);
static int esFloat (char* cadena);
static int getString(char* cadena, int size);
static int getNombre(char* pResultado, int size);
static int esNombre(char* cadena,int size);


/**
 *
 * \brief verifica si la cadena es numerica
 *
 * \param pResultado puntero al espacio de memoria donde se va a guardar el resultado
 * \return retorna 0 si la función es correcta, y -1 si hubo algún error
 */
static int getInt(int* pResultado)
{
	int retorno = -1;
	char bufferGI[4096];

	if(pResultado != NULL)
	{
		if(myGets(bufferGI, sizeof(bufferGI))==0 && esNumerica (bufferGI))
		{
			retorno=0;
			*pResultado = atoi(bufferGI);
		}
	}
	return retorno;
}

/**
 *
 * \brief lee stdin hasta encontrar un '\n' o hasta copiar el maximo de size -1
 *
 * \param pResultado puntero al espacio de memoria donde se va a guardar la cadena obtenida
 * \return retorna 0 si la función es correcta, y -1 si hubo algún error
 */
static int myGets(char* cadena, int size)
{
	if (cadena != NULL && size >0 && fgets (cadena,size,stdin)==cadena)
	{
		fflush (stdin);
		if (cadena[ strlen (cadena)-1] == '\n' )
		{
			cadena[ strlen (cadena)-1] = '\0' ;
		}
		return 0;
	}
	return -1;
}

/**
 *
 * \brief verifica si la cadena ingresada es numerica
 *
 * \param cadena cadena de caracteres a analizar
 * \return retorna 1 si es numerica y 0 si no lo es
 */

static int esNumerica(char* cadena)
{
	int retorno = 1;
	int i=0;

	if(cadena != NULL && strlen(cadena)>0)
	{
		while (cadena[i] != '\0')
			{
				if (cadena [i] > '9' || cadena [i] < '0')
				{
					retorno=0;
					break;
				}
				i++;
			}
	}
	return retorno;
}

static int getFloat(float* pResultado)
{
	int retorno = -1;
	char bufferGF[4096];

	if(myGets(bufferGF, sizeof(bufferGF))==0 && esFloat (bufferGF) == 1)
	{
		retorno=0;
		*pResultado = atof(bufferGF);
	}
	return retorno;
}

static int esFloat (char* cadena)
{
	int retorno = 1;
	int i=0;
	int contador=0;

	if(cadena != NULL && strlen(cadena)>0)
	{
		for(i=0; cadena[i] != '\0'; i++)
		{
			if (cadena [i] > '9' || cadena [i] < '0')
			{
				if (cadena [i] == '.')
				{
					contador++;
					if(contador>1)
					{
						retorno=0;
						break;
					}
					else
					{
						if(i==0)
						{
							if (cadena [i] != '+' && cadena [i] != '-')
							{
								retorno=0;
								break;
							}
							else
							{
								retorno=0;
								break;
							}
						}
					}
				}
			}
		}
	}
	return retorno;
}

static int getString(char* cadena, int size)
{
	int retorno=-1;
	char bufferString[4096];

	if(cadena != NULL && size > 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= size)
			{
				strncpy(cadena,bufferString,size);
				retorno=0;
			}
		}
	}
	return retorno;
}

static int getNombre(char* pResultado, int size)
{
    int retorno=-1;
    char bufferGN[4096];

    if(pResultado != NULL)
    {
    	if(getString(bufferGN,sizeof(bufferGN))==0 && esNombre(bufferGN,sizeof(bufferGN)) && strnlen(bufferGN,sizeof(bufferGN))<size)
    	{
    		strncpy(pResultado,bufferGN,size);
			retorno = 0;
		}
    }
    return retorno;
}

static int esNombre(char* cadena,int size)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && size > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < size; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) &&
					(cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

//GET
int utn_get_Int(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			if(getInt (&bufferInt) == 0 && bufferInt>=minimo && bufferInt<=maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
			reintentos--;
			printf("%s", mensajeError);
		}while(reintentos>=0);
	}
	return retorno;
}

int utn_get_Float(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno = -1;
	float bufferFloat;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			if(getFloat (&bufferFloat) == 0 && bufferFloat>=minimo && bufferFloat<=maximo)
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
			reintentos--;
			printf("%s", mensajeError);
		}while(reintentos>=0);
	}
	return retorno;
}

int utn_get_String(char* pResultado, int size,char* mensaje, char* mensajeError, int reintentos)
{
	int retorno = -1;
	char bufferString[4096];
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			if(getNombre(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < size )
			{
				strncpy(pResultado,bufferString,size);
				retorno = 0;
				break;
			}
			reintentos--;
			printf("%s",mensajeError);
		}
		while(reintentos>=0);
	}
	return retorno;
}
