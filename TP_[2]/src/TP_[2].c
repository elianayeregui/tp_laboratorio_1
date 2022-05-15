/*
 ============================================================================
 Name        : TP_[2].c
 Author      : Eliana Yeregui - 1 H
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "utn_get.h"


#define MAX_PASSENGER 1000
#define TRUE 0
#define FALSE 1


int main(void) {
	setbuf(stdout, NULL);

	ePassenger arrayPassenger[MAX_PASSENGER];
	ePassenger auxiliar;
	ePassenger index;
	ePassenger list;
	int flag=FALSE;
	float promedio;
	float cantPrecioExcedido;

	//INICIALIZO PANTALLAS
	initPassengers(arrayPassenger, MAX_PASSENGER);

	int opcion;
	int informe;

	do
	{
		puts("\t*********************");
		puts("\t* AEROLINEAS *");
		puts("\t*********************");
		utn_get_Int(&opcion, "\nIngrese una opcion: \n1)Dar de Alta \n2)Modificar un dato \n3)Dar de Baja \n4)Informar \n5)Alta forzada \n6)Salir", "Ingrese una opcion correcta", 1, 6, 2);

		switch(opcion)
			{
				case 1:
					if(addPassenger(arrayPassenger, MAX_PASSENGER, auxiliar.id, auxiliar.name,auxiliar.lastName,auxiliar.price,auxiliar.typePassenger, auxiliar.flycode) == 1)
					{
						printf("Los datos fueron cargados correctamente");
						flag=TRUE;
					}
					break;
				case 2:
					if(flag==FALSE)
					{
						printf("Error. No hay datos");
					}
					else
					{
						if(ePantalla_Modificacion(arrayPassenger, MAX_PASSENGER) == 1)
						{
							printf("Los datos fueron modificados correctamente");
						}
					}
					break;
				case 3:
					if(flag==FALSE)
					{
						printf("Error. No hay datos");
					}
					else
					{
						if(removePassenger(arrayPassenger, MAX_PASSENGER, auxiliar.id) == 1)
						{
							printf("Los datos fueron dados de baja correctamente");
						}
					}
					break;
				case 4:
					if(flag==FALSE)
					{
						printf("Error. No hay datos");
					}
					else
					{
						utn_get_Int(&opcion, "\nIngrese una opcion: \n1)Listado de pasajeros ordenado alfabeticamente por apellido y tipo \n2)Precio total, promedio y cantidades \n3)Listado de pasajeros por código de vuelos y ACTIVOS \n4)Salir", "Ingrese una opcion correcta", 1, 4, 2);
						switch(informe)
						{
						case 1:
							if(sortPassengers(arrayPassenger, MAX_PASSENGER, -1)==1)
							{
								printf("%s", list);
							}
							if(sortPassengers(arrayPassenger, MAX_PASSENGER, 1)==1)
							{
								printf("%s", list);
							}
							break;
						case 2:
							if(promedioPrecios(arrayPassenger, MAX_PASSENGER, &promedio, &cantPrecioExcedido)==0)
							{
								printf("%f, El promedio de precios es: ", promedio);
								printf("%f, La cantidad de pasajeros que excede el precio promedio es: ", cantPrecioExcedido);
							}
							break;
						case 3:
							if(auxiliar.statusFlight == 1)
							{
								if(sortPassengers(arrayPassenger, MAX_PASSENGER, -1)==1)
								{
									printPassenger(arrayPassenger, MAX_PASSENGER);
								}
							}
							break;
						case 4:
							break;
						}
					}
					break;
				case 5:
					if(cargaForzada(arrayPassenger, MAX_PASSENGER)==0)
					{
						printf("%s", list);
					}
					break;
				case 6:
					break;
			  	  	}
		}while(opcion!=6);

	return EXIT_SUCCESS;
}
