#include <stdio.h>
#include <stdlib.h>

int* sala;
int cap;
int ocupados;
void crea_sala(int capacidad) {
  if (capacidad <= 0) {
    printf("La capacidad de la sala no puede ser menor o igual que 0");
  } else {
    sala = malloc(sizeof(int)*capacidad);
    int i = 0;
    cap = capacidad;
    ocupados=0;
    while (i < capacidad) {
      sala[i] = -1;
      i++;
    }
  }
}

int capacidad () {
  return (cap);
}

void elimina_sala () {
  cap = -1;
  ocupados = -1;
  free(sala);
}

//Metodo auxiliar para ver si el cliente ya tiene asignado un asiento
int check_id (int id) {
  int i = 0;
  int flag = 0;
  while (i < capacidad()) {
    if (sala[i] == id) {
      flag = 1;
    }
    i++;
  }
  return flag;
}

int reserva_asiento (int id) {
  int i = 0;
  int checker = check_id(id);
  if (checker == 1) {
    return -1;
  } else {
    while (i < capacidad()) {
      if (sala[i] == -1) {
        sala[i] = id;
        ocupados++;
        return i;
      }
      i++;
    }
  
  }
  
  return -1;

}

int asientos_ocupados () {
  return ocupados;
}


int asientos_libres () {
  return capacidad() - asientos_ocupados();
}

int libera_asiento (int asiento) {

  int flag = 0;
  if (asiento < 0) {
    return -1;
  } else if (asiento > capacidad()) {
    return -1;
  } else if (sala[asiento] != -1){
    ocupados = ocupados -1;
    flag = sala[asiento];
    return flag;
  }

}

int estado_asiento(int asiento) {

  if (asiento < 0) {
    printf("\nEl numero de asiento introducido no puede ser negativo\n");
    return -1;
  } else if (asiento > capacidad()) {
    printf("\n El numero de asiento introducido excede la capacidad de la sala\n");
    return -1;
  } else if (sala[asiento] == -1) {
    printf("\nEl asiento esta libre\n");
    return 0;
  } else {
    return sala[asiento];
  }

}
