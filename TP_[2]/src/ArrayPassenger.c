/*
 * passenger.c
 *
 *  Created on: 10 may. 2022
 *      Author: Intel
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "utn_get.h"

#define TRUE 0
#define FALSE 1

//ID AUTOINCREMENTAL
static int ePassenger_ObtenerID(void);
static int ePassenger_ObtenerID(void)
{
	static int passenger_idIncremental = 0;
	return passenger_idIncremental ++;
}


int initPassengers(ePassenger* list, int len)
{
	int i;
	int retorno=-1;
		if(list != NULL && len > 0)
		{
			for(i=0; i<len; i++)
			{
				list[i].isEmpty = TRUE;
				retorno=0;
			}
		}
		return retorno;
}


int ePassenger_getEmptyIndex(ePassenger array[], int len)
{
	int retorno = -1;
	int i;

	if(array != NULL && len > 0)
	{
		for(i=0; i<len; i++)
				{
					if(array[i].isEmpty == TRUE)
					{
						retorno = i;
						break;
					}
				}
	}
	return retorno;
}

int addPassenger(ePassenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[])
{
	int retorno = 0;
	ePassenger auxPassenger;

	int index = ePassenger_getEmptyIndex(list, len);

	if(index != -1)
	{
		auxPassenger = ePassenger_cargaDatos();
		auxPassenger.id = ePassenger_ObtenerID();
		auxPassenger.isEmpty = FALSE;

		list[index] = auxPassenger;

		retorno = 1;
	}

	return retorno;
}

ePassenger ePassenger_cargaDatos(void)
{
	ePassenger auxiliar;
	int opcionTypePassenger;
	int opcionStatusFlight;


		utn_get_String(auxiliar.name, MAX_CHAR_NAME, "Ingrese su nombre: \n", "Error, ingrese un nombre válido: \n", 5);
		utn_get_String(auxiliar.lastName, MAX_CHAR_NAME, "Ingrese su apellido: \n", "Error, ingrese un apellido válido: \n", 5);
		utn_get_Float(&auxiliar.price,"Ingrese el precio: \n", "Error, ingrese un precio válido: \n", 0, 1000000000, 5);
		utn_get_String(auxiliar.flycode, MAX_CHAR_NAME, "Ingrese el código de vuelo: \n", "ingrese un código de vuelo válido: \n", 6);
		utn_get_Int(&opcionTypePassenger, "\nIngrese un tipo de pasajero: \n1)PRIMERA CLASE \n2)TURISTA \n3)EJECUTIVO", "Ingrese una opcion correcta", 1, 3, 2);
		switch(opcionTypePassenger)
		{
			case 1:
				auxiliar.typePassenger =1;
				break;
			case 2:
				auxiliar.typePassenger =2;
				break;
			case 3:
				auxiliar.typePassenger =3;
				break;
		}

		utn_get_Int(&opcionStatusFlight, "\nIngrese un estado de vuelo: \n1)ACTIVO \n2)CANCELADO \n3)EN ESPERA", "Ingrese una opcion correcta", 1, 3, 2);
		switch(opcionStatusFlight)
				{
					case 1:
						auxiliar.statusFlight =1;
						break;
					case 2:
						auxiliar.statusFlight =2;
						break;
					case 3:
						auxiliar.statusFlight =3;
						break;
				}

	return auxiliar;
}


int findPassengerById(ePassenger* list, int len,int id)
{
	int retorno = -1;
	int i;

		if (list != NULL && len > 0)
		{
			for (i = 0; i < len; i++)
			{
				if (list[i].id == id && list[i].isEmpty == FALSE)
				{
					retorno = i;
					break;
				}
			}
		}

		return retorno;
}

int removePassenger(ePassenger* list, int len, int id)
{
	int retorno = 0;
	int index;
	int flag = 0;

		if (printPassenger(list, len))
		{
			flag = 1;
		}
		if (flag)
		{
			utn_get_Int(&id, "Ingrese ID a dar de baja", "Ingrese un ID correcto", 1, 8, 3);

			while (findPassengerById(list, len, id) == -1)
			{
				puts("NO EXISTE ID.");
				utn_get_Int(&id, "Ingrese ID a dar de baja", "Ingrese un ID correcto", 1, 8, 3);
			}
			index = findPassengerById(list, len, id);

			list[index].isEmpty = BAJA;
			retorno = 1;
		}
		return retorno;
}


int printPassenger(ePassenger* list, int length)
{
	int i;
	int retorno = 0;
	int cantidad = 0;

	puts("\n\t> LISTADO PASAJEROS");
	printf("%s%s%f%s%s%s\n\n", "ID", "TIPO", "PRECIO", "NOMBRE", "APELLIDO", "CODIGO DE VUELO");

	if (list != NULL && length > 0)
	{
		for (i = 0; i < length; i++)
		{
			if (list[i].isEmpty == FALSE)
			{
				ePassenger_MostrarUno(list[i]);
				cantidad++;
			}
		}
	}
	if (cantidad > 0)
	{
		retorno = 1;
	}

	return retorno;
}

void ePassenger_MostrarUno(ePassenger Passenger)
{
	printf("%d", Passenger.id);
	printf("%f", Passenger.price);
	printf("%s\n", Passenger.name);
	printf("%s\n", Passenger.lastName);

	if (Passenger.typePassenger == 1)
		{
			printf("%5s", "PRIMERA CLASE");
		}
		else
		{
			if (Passenger.typePassenger == 2)
			{
				printf("%5s", "TURISTA");
			}
			else
			{
				printf("%5s", "EJECUTIVO");
			}
		}

	if (Passenger.statusFlight == 1)
			{
				printf("%5s", "ACTIVO");
			}
			else
			{
				if (Passenger.typePassenger == 2)
				{
					printf("%5s", "CANCELADO");
				}
				else
				{
					printf("%5s", "EN ESPERA");
				}
			}
	printf("%s\n", Passenger.flycode);
}

int ePantalla_Modificacion(ePassenger list[], int len)
{
	int retorno = 0;
	int id;
	int index;
	int flag = 0;
	ePassenger auxiliar;

	if (printPassenger(list, len))
	{
		flag = 1;
	}

	if (flag)
	{
		utn_get_Int(&id, "Ingrese ID a dar de baja", "Ingrese un ID correcto", 1, 8, 3);

		while (findPassengerById(list,len,id) == -1)
		{
			puts("NO EXISTE ID.");

			utn_get_Int(&id, "Ingrese ID a dar de baja", "Ingrese un ID correcto", 1, 8, 3);
		}

		index = findPassengerById(list,len,id);

		auxiliar = ePassenger_ModificarUno(list[index]);

		list[index] = auxiliar;

		retorno = 1;
	}

	return retorno;
}

ePassenger ePassenger_ModificarUno(ePassenger Passenger)
{
	int opcion;

	do
	{
		utn_get_Int(&opcion, "\nIngrese una opcion a modificar: \n1)Nombre \n2)Apellido \n3)Precio \n4)Codigo de vuelo \n5)Tipo de pasajero \n6)Salir", "Ingrese una opcion correcta", 1, 6, 2);
			switch(opcion)
			{
				case 1:
					utn_get_String(Passenger.name, MAX_CHAR_NAME, "Ingrese su nombre: \n", "Error, ingrese un nombre válido: \n", 5);
					break;
				case 2:
					utn_get_String(Passenger.lastName, MAX_CHAR_NAME, "Ingrese su apellido: \n", "Error, ingrese un apellido válido: \n", 5);
					break;
				case 3:
					utn_get_Float(&Passenger.price,"Ingrese el precio: \n", "Error, ingrese un precio válido: \n", 0, 1000000000, 5);
					break;
				case 4:
					utn_get_String(Passenger.flycode, MAX_CHAR_FLYCODE, "Ingrese el código de vuelo: \n", "Error, ingrese un código de vuelo válido: \n", 5);
					break;
				case 5:
					utn_get_Int(&opcion, "\nIngrese un tipo de pasajero: \n1)Primera Clase \n2)Turista \n3)Ejecutivo", "Ingrese una opcion correcta", 1, 3, 2);
						switch(opcion)
						{
							case 1:
								Passenger.typePassenger =1;
								break;
							case 2:
								Passenger.typePassenger =2;
								break;
							case 3:
								Passenger.typePassenger =3;
								break;
						}
						break;
				case 6:
					break;
			}
	}while(opcion!=6);

	return Passenger;
}


int sortPassengers(ePassenger* list, int len, int order)
{
	int retorno = 0;
	int i;
	int j;
	ePassenger aux;

	/**
	 CASE -1 -> APELLIDO ALFABETICAMENTE
	 CASE  1 -> TIPO
	**/

	if (list != NULL && len > 0)
	{
		switch (order)
		{
		case -1:
			for (i = 0; i < len - 1; i++)
			{
				for (j = i + 1; j < len; j++)
				{
					if (list[i].isEmpty == FALSE && list[j].isEmpty == FALSE)
					{
						if (strncmp(list[i].lastName, list[i+1].lastName, MAX_CHAR_NAME) >0)
						{
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
					}
				}
			}
			retorno = 1;
			break;
		case 1:
			for (i = 0; i < len - 1; i++)
						{
							for (j = i + 1; j < len; j++)
							{
								if (list[i].isEmpty == FALSE && list[j].isEmpty == FALSE)
								{
									if (list[i].typePassenger > list[i+1].typePassenger)
									{
										aux = list[i];
										list[i] = list[j];
										list[j] = aux;
									}
								}
							}
						}
			retorno = 1;
			break;
		default:
			retorno = 0;
			break;
		}
	}
	return retorno;
}

int sortPassengersByCode(ePassenger* list, int len, int order)
{
	int retorno = 0;
	int i;
	int j;
	ePassenger auxiliar;

		/**
		 -1 -> MENOR A MAYOR (ASCENDENTE)
		  1 -> MAYOR A MENOR (DESCENDENTE)
		 */

	if (list != NULL && len > 0)
	{
		switch (order)
		{
			case -1:
				for (i = 0; i < len - 1; i++)
				{
					for (j = i + 1; j < len; j++)
					{
						if (list[i].isEmpty == FALSE && list[j].isEmpty == FALSE)
						{
							if (list[i].flycode > list[j].flycode)
							{
								auxiliar = list[i];
								list[i] = list[j];
								list[j] = auxiliar;
							}
						}
					}
				}
				retorno = 1;
				break;
			case 1:
				for (i = 0; i < len - 1; i++)
				{
					for (j = i + 1; j < len; j++)
					{
						if (list[i].isEmpty == FALSE && list[j].isEmpty == FALSE)
						{
							if (list[i].flycode < list[j].flycode)
							{
								auxiliar = list[i];
								list[i] = list[j];
								list[j] = auxiliar;
							}
						}
					}
				}
				retorno = 1;
				break;
			default:
				retorno = 0;
				break;
			}
	}
	return retorno;
}


int promedioPrecios(ePassenger* list, int len, float* promedio, float* cantPrecioExcedido)
{
	int retorno= -1;
	int i;
	int contadorPassenger =0;
	float resultadoPrecio =0;
	int contadorCantPrecioExcedido=0;


	if(list != NULL && len>0)
	{
		for(i = 0; i < len; i++)
				{
					if(list[i].isEmpty == FALSE)
					{
						resultadoPrecio += list[i].price;
						contadorPassenger++;
						*promedio = resultadoPrecio / contadorPassenger;
						if(list[i].price > *promedio)
						{
							contadorCantPrecioExcedido++;
							*cantPrecioExcedido = contadorCantPrecioExcedido;
						}
					}
				}
		retorno= 0;
	}
	else
	{
		printf("\nERROR");
	}
	return retorno;
}

int cargaForzada(ePassenger* list, int len)
{
	int retorno = -1;
	if(list != NULL && len>0)
	{
		addPassenger(list, MAX_CHAR_NAME, 5000, "Juan", "Gonzalez", 25000, 1, "123WER");
		addPassenger(list, MAX_CHAR_NAME, 5001, "Jorge", "Martinez", 56000, 2, "334FHE");
		addPassenger(list, MAX_CHAR_NAME, 5002, "Julian", "Fiesta", 33000, 3, "677EYF");

		retorno=0;
	}
	return retorno;
}
