/*
 * passenger.h
 *
 *  Created on: 10 may. 2022
 *      Author: Intel
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR_NAME 51
#define MAX_CHAR_FLYCODE 10
#define TRUE 0
#define FALSE 1
#define BAJA -1

struct
{
	int id;
	char name[MAX_CHAR_NAME];
	char lastName[MAX_CHAR_NAME];
	float price;
	char flycode[MAX_CHAR_FLYCODE];
	int typePassenger;
	int isEmpty;
	int statusFlight;
}typedef ePassenger;


//CABECERAS

/** \brief To indicate that all position in the array are empty, this function put the flag (isEmpty) in TRUE in all position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initPassengers(ePassenger* list, int len);

/** \brief add in a existing list of passengers the values received as parameters in the first empty position
* \param list epassenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/
int addPassenger(ePassenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[]);


/** \brief obtiene un lugar libre en el array
* \param ePassenger
* \param len
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/
int ePassenger_getEmptyIndex(ePassenger array[], int len);


/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list ePassenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or NULL pointer received or passenger not found]
*
*/
int findPassengerById(ePassenger* list, int len,int id);


/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list ePassenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a passenger] - (0) if Ok
*
*/
int removePassenger(ePassenger* list, int len, int id);

/** \brief print the content of ePassengers array
*
* \param list ePassenger*
* \param length int
* \return int
*
*/
int printPassenger(ePassenger* list, int length);

/** \brief Sort the elements in the array of ePassenger, the argument order indicate UP or DOWN order
*
* \param list ePassenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengersByCode(ePassenger* list, int len, int order);

ePassenger ePassenger_cargaDatos(void);

void ePassenger_MostrarUno(ePassenger Passenger);

int ePantalla_Modificacion(ePassenger list[], int len);

ePassenger ePassenger_ModificarUno(ePassenger Passenger);

int sortPassengers(ePassenger* list, int len, int order);

int promedioPrecios(ePassenger* list, int len, float* promedio, float* cantPrecioExcedido);

int cargaForzada(ePassenger* list, int len);

#endif /* ARRAYPASSENGER_H_ */
