/*
 ============================================================================
 Name        : prueba.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "prueba1.h"

int main(void) {
	setbuf(stdout, NULL);

	   int resultado;

	   utn_getNumero(&resultado,"ingrese int: " ,"\n error ingrese int denuevlra" ,0 ,120 , 5);

	    printf("%d",resultado);

	return EXIT_SUCCESS;
}
