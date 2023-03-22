#include <stdio.h>
#include <stdlib.h>
#include "../cabeceras/sala.h"
void main () {
    int x = 7;
    crea_sala(x);
    
    printf("\nLa capacidad de la sala es de: %d\n", capacidad());
    
    //Reserva de asientos
    int id = 5;
    int id2 = 6;
    int id3 = 7;
    int id4 = 8;
    printf("Se le ha asignado el asiento numero: %d al cliente con id: %d\n", reserva_asiento(id), id);
    printf("Se le ha asignado el asiento numero: %d al cliente con id: %d\n", reserva_asiento(id2), id2);
    printf("Se le ha asignado el asiento numero: %d al cliente con id: %d\n", reserva_asiento(id2), id2);
    printf("Se le ha asignado el asiento numero: %d al cliente con id: %d\n", reserva_asiento(id3), id3);
    printf("Se le ha asignado el asiento numero: %d al cliente con id: %d\n", reserva_asiento(id4), id4);
    //Liberar asientos
    printf("Se libera el asiento %d del cliente con id: %d\n", 2, libera_asiento(2));
    
    //Estado asiento
    printf("%d\n", estado_asiento(3));
    printf("%d\n", estado_asiento(-1));
    printf("%d\n", estado_asiento(20));
    printf("El numero de asientos ocupados es: %d\n", asientos_ocupados());
    printf("El numero de asientos libres es: %d\n", asientos_libres());
    
    elimina_sala();
}
