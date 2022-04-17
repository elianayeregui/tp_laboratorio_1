/*
 ============================================================================
 Name        : TP_[1].c
 Author      : Eliana Yeregui
 Version     : 1 H
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn_getNumero.h"
#include "operacionesMatematicas.h"
#include "utn_cargaForzada.h"

int main(void)
{
	setbuf(stdout, NULL);
	int opcion;
	int respuestaOpcion;
	float kilometros=0;
	int respuestaKM;
	int precioLatam;
	int precioAerolineas;
	float latam=0;
	float aerolineas=0;
	float rDebitoLatam;
	float debitoLatam;
	float creditoLatam;
	float rCreditoLatam;
	float latamBitcoin;
	float latamPesoUnitario;
	float debitoAerolineas;
	float rDebitoAerolineas;
	float creditoAerolineas;
	float rCreditoAerolineas;
	float aerolineasBitcoin;
	float aerolineasPesoUnitario;
	float diferencia;
	int OMdescuentoLatam;
	int OMFinalDescuentoLatam;
	int OMinteresLatam;
	int OMFinalInteresLatam;
	int OMbitcoinLatam;
	int OMUnitarioLatam;
	int OMdescuentoAerolineas;
	int OMFinalDescuentoAerolineas;
	int OMinteresAerolineas;
	int OMFinalInteresAerolineas;
	int OMbitcoinAerolineas;
	int OMUnitarioAerolineas;
	int OMDiferencia;
	int validacionFlag=0;

			do
			{
				respuestaOpcion = utn_getNumero_Int(&opcion, "Elija una de las siguientes opciones\n 1-Ingresar Kilometros:\n 2-Ingresar Precio de Vuelos:\n 3-Calcular todos los costos:\n 4-Informar Resultados\n 5-Carga forzada de datos\n 6-salir\n", "Debe ingresar una opcion valida\n", 0, 7, 3);

				if(respuestaOpcion==0)
				{
					switch (opcion)
					{
							case 1:
								respuestaKM= utn_get_Float(&kilometros, "Ingrese los kilometros\n", "El numero ingresado no es valido\n", 0, 50000, 3);
								if (respuestaKM==0)
								{
									continue;
								}
								break;
							case 2:
									precioLatam= utn_get_Float(&latam, "Ingrese el precio de Latam\n", "El precio ingresado no es valido\n", 1, 100000000000, 3);
									precioAerolineas= utn_get_Float(&aerolineas, "Ingrese el precio de Aerolineas\n", "El precio ingresado no es valido\n", 1, 100000000000, 3);
									if (precioLatam==0 && precioAerolineas==0)
									{
										continue;
									}
								break;
							case 3:
								 OMdescuentoLatam= operacionesMatematicasPorcentaje(latam, 10, &debitoLatam);
								 OMFinalDescuentoLatam= operacionesMatematicasResta(latam, debitoLatam, &rDebitoLatam);
								 OMinteresLatam= operacionesMatematicasPorcentaje(latam, 25, &creditoLatam);
								 OMFinalInteresLatam= operacionesMatematicasSuma(latam, creditoLatam, &rCreditoLatam);
								 OMbitcoinLatam= operacionesMatematicasBitcoin(latam, &latamBitcoin);
								 OMUnitarioLatam= operacionesMatematicasDivision(latam, kilometros, &latamPesoUnitario);
								 OMdescuentoAerolineas= operacionesMatematicasPorcentaje(aerolineas, 10, &debitoAerolineas);
								 OMFinalDescuentoAerolineas= operacionesMatematicasResta(aerolineas, debitoLatam, &rDebitoAerolineas);
								 OMinteresAerolineas= operacionesMatematicasPorcentaje(aerolineas, 25, &creditoAerolineas);
								 OMFinalInteresAerolineas= operacionesMatematicasSuma(aerolineas, creditoLatam, &rCreditoAerolineas);
								 OMbitcoinAerolineas= operacionesMatematicasBitcoin(aerolineas, &aerolineasBitcoin);
								 OMUnitarioAerolineas= operacionesMatematicasDivision(aerolineas, kilometros, &aerolineasPesoUnitario);
								 OMDiferencia= operacionesMatematicasResta(latam, aerolineas, &diferencia);
								if (OMdescuentoLatam==0 && OMFinalDescuentoLatam==0 && OMinteresLatam==0 && OMFinalInteresLatam==0 && OMbitcoinLatam==0 && OMUnitarioLatam==0 && OMdescuentoAerolineas==0 && OMFinalDescuentoAerolineas==0 && OMinteresAerolineas==0 && OMFinalInteresAerolineas==0 && OMbitcoinAerolineas==0 && OMUnitarioAerolineas==0 && OMDiferencia==0 && kilometros > 0 && latam > 0 && aerolineas > 0)
								{
									validacionFlag=1;
									continue;
								}
								break;
							case 4:
								if(validacionFlag==1)
								{
								printf("KMs Ingresados: %.2f km \n\nPrecio Aerolineas: $ %.2f \na) Precio con tarjeta de debito: $ %.2f \nb) Precio con tarjeta de credito: $ %.2f \nc) Precio pagando con bitcoin: %f BTC \nd) Mostrar precio unitario: $ %.2f \n\nPrecio Latam: $ %.2f \na) Precio con tarjeta de debito: $ %.2f \nb) Precio con tarjeta de credito: $ %.2f \nc) Precio pagando con bitcoin: %f BTC \nd) Mostrar precio unitario: $ %.2f \n\nLa diferencia de precio es: $ %.2f\n\n", kilometros, aerolineas, rDebitoAerolineas, rCreditoAerolineas, aerolineasBitcoin, aerolineasPesoUnitario, latam, rDebitoLatam, rCreditoLatam, latamBitcoin, latamPesoUnitario, diferencia);
								}
								break;
							case 5:
								utn_cargaForzada();
								break;
							default:
								break;
					}
				}
				else
				{
					printf("ERROR");
				}
			}while(opcion!= 6);

	return EXIT_SUCCESS;
}

