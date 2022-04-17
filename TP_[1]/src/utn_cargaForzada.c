/*
 * utn_cargaForzada.c
 *
 *  Created on: 14 abr. 2022
 *      Author: Intel
 */

#include <stdio.h>
#include <stdlib.h>
#include "operacionesMatematicas.h"

void utn_cargaForzada ()
{
	float CFlatam=159339;
	float CFdebitoLatam;
	float CFrDebitoLatam;
	float CFcreditoLatam;
	float CFrCreditoLatam;
	float CFlatamBitcoin;
	float CFkilometros=7090;
	float CFlatamPesoUnitario;
	float CFaerolineas=162965;
	float CFdebitoAerolineas;
	float CFrDebitoAerolineas;
	float CFcreditoAerolineas;
	float CFrCreditoAerolineas;
	float CFaerolineasBitcoin;
	float CFaerolineasPesoUnitario;
	float CFdiferencia;

	operacionesMatematicasPorcentaje(CFlatam, 10, &CFdebitoLatam);
	operacionesMatematicasResta(CFlatam, CFdebitoLatam, &CFrDebitoLatam);
	operacionesMatematicasPorcentaje(CFlatam, 25, &CFcreditoLatam);
	operacionesMatematicasSuma(CFlatam, CFcreditoLatam, &CFrCreditoLatam);
	operacionesMatematicasBitcoin(CFlatam, &CFlatamBitcoin);
	operacionesMatematicasDivision(CFlatam, CFkilometros, &CFlatamPesoUnitario);
	operacionesMatematicasPorcentaje(CFaerolineas, 10, &CFdebitoAerolineas);
	operacionesMatematicasResta(CFaerolineas, CFdebitoLatam, &CFrDebitoAerolineas);
	operacionesMatematicasPorcentaje(CFaerolineas, 25, &CFcreditoAerolineas);
	operacionesMatematicasSuma(CFaerolineas, CFcreditoLatam, &CFrCreditoAerolineas);
	operacionesMatematicasBitcoin(CFaerolineas, &CFaerolineasBitcoin);
	operacionesMatematicasDivision(CFaerolineas, CFkilometros, &CFaerolineasPesoUnitario);
	operacionesMatematicasResta(CFlatam, CFaerolineas, &CFdiferencia);

	printf("KMs Ingresados: %.2f km \n\nPrecio Aerolineas: $ %.2f \na) Precio con tarjeta de debito: $ %.2f \nb) Precio con tarjeta de credito: $ %.2f \nc) Precio pagando con bitcoin: %f BTC \nd) Mostrar precio unitario: $ %.2f \n\nPrecio Latam: $ %.2f \na) Precio con tarjeta de debito: $ %.2f \nb) Precio con tarjeta de credito: $ %.2f \nc) Precio pagando con bitcoin: %f BTC \nd) Mostrar precio unitario: $ %.2f \n\nLa diferencia de precio es: $ %.2f\n\n", CFkilometros, CFaerolineas, CFrDebitoAerolineas, CFrCreditoAerolineas, CFaerolineasBitcoin, CFaerolineasPesoUnitario, CFlatam, CFrDebitoLatam, CFrCreditoLatam, CFlatamBitcoin, CFlatamPesoUnitario, CFdiferencia);
}
