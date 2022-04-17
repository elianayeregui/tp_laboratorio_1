/*
 * operacionesmatematicas.c
 *
 *  Created on: 12 abr. 2022
 *      Author: Intel
 */
#include <stdio.h>
#include <stdlib.h>

int operacionesMatematicasSuma(float a, float b, float*resultadoSuma)
{
	int retorno= -1;
	if(resultadoSuma != NULL)
	{
		retorno= 0;
		*resultadoSuma= a + b;
	}
	else
	{
		printf("\nERROR");
	}

	return retorno;
}
int operacionesMatematicasResta(float a, float b, float*resultadoResta)
{
	int retorno= -1;
	if(resultadoResta != NULL)
	{
		retorno= 0;
		*resultadoResta= a - b;
	}
	else
	{
		printf("\nERROR");
	}

	return retorno;

}
int operacionesMatematicasMultiplicacion(float a, float b, float*resultadoMultiplicacion)
{
	int retorno= -1;
	if(resultadoMultiplicacion != NULL)
	{
		retorno= 0;
		*resultadoMultiplicacion= a*b;
	}
	else
	{
		printf("\nERROR");
	}
	return retorno;
}
int operacionesMatematicasDivision(float a, float b, float*resultadoDivision)
{
	int retorno= -1;
	if(b != 0 && resultadoDivision != NULL)
	{
		*resultadoDivision= a/b;
		retorno=0;
	}
	else
	{
		printf("\nERROR");
	}
	return retorno;
}
int operacionesMatematicasPorcentaje(float a, float b, float*resultadoPorcentaje)
{
	int retorno= -1;
	if(resultadoPorcentaje != NULL)
	{
		retorno= 0;
		*resultadoPorcentaje= (a*b)/100;
	}
	else
	{
		printf("\nERROR");
	}
	return retorno;
}
int operacionesMatematicasBitcoin(float peso, float*resultadoBitcoin)
{
	int retorno= -1;
	float bitcoin = 4606954.55;
	if(resultadoBitcoin != NULL)
	{
		retorno= 0;
		*resultadoBitcoin= peso/bitcoin;
	}
	else
	{
		printf("\nERROR");
	}
	return retorno;
}









