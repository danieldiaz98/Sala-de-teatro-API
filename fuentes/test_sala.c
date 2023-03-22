// test_sala.c
// ===============
// Batería de pruebas de la biblioteca "sala.h/sala.c"
//
#include <assert.h>
#include <stdio.h>
#include "../cabeceras/sala.h"
#define DebeSerCierto(x)	assert(x)
#define DebeSerFalso(x)		assert(!(x))

void INICIO_TEST (const char* titulo_test)
{
  printf("********** batería de pruebas para %s: ", titulo_test); 
 	// fflush fuerza que se imprima el mensaje anterior
	// sin necesidad de utilizar un salto de línea
	fflush(stdout);
}

void FIN_TEST (const char* titulo_test)
{
  printf ("********** hecho\n");
}


void test_ReservaBasica()
{
	int mi_asiento;
	#define CAPACIDAD_CUYAS 500
	#define ID_1 1500

	INICIO_TEST("Reserva básica");
	crea_sala(CAPACIDAD_CUYAS);
	DebeSerCierto(capacidad()==CAPACIDAD_CUYAS);
	DebeSerCierto((mi_asiento=reserva_asiento(ID_1))>=0);
	DebeSerCierto((asientos_libres()+asientos_ocupados())==CAPACIDAD_CUYAS);
	DebeSerCierto(estado_asiento(mi_asiento)>0);
	DebeSerCierto(libera_asiento(mi_asiento)==ID_1);
	DebeSerCierto((asientos_libres()+asientos_ocupados())==CAPACIDAD_CUYAS);
	elimina_sala();
	FIN_TEST("Reserva básica");
}

void mis_pruebas() {

	int x = 7;
	crea_sala(x);
	DebeSerCierto(capacidad() == x);
	
	int id = 5;
    	int id2 = 6;
    	int id3 = 7;
    	int id4 = 8;
	int id5 = 6;
	
	int asiento1=reserva_asiento(id);
	int asiento2=reserva_asiento(id2);
	int asiento3=reserva_asiento(id3);
	int asiento4=reserva_asiento(id4);
	int asiento5=reserva_asiento(id5);
	
	DebeSerCierto(asiento1 == 0);
	DebeSerCierto(asiento2 == 1);
	DebeSerCierto(asiento3 == 2);
	DebeSerCierto(asiento4 == 3);
	DebeSerCierto(asiento5 == -1);
	
	int asientoLiberado=libera_asiento(0);
	DebeSerCierto(asientoLiberado == id);
	
	DebeSerCierto(asientos_ocupados() == 3);
	DebeSerCierto(asientos_libres() == 4);
	
	DebeSerCierto(estado_asiento(2) == 7);
}

void ejecuta_tests ()
{
	test_ReservaBasica();
	// Añadir nuevos tests 
	mis_pruebas();
}

void main()
{
	puts("Iniciando tests...");
	
	ejecuta_tests();
	
	puts("Batería de test completa.");
}

