#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "empleados.h"
#include "sectores.h"
#include "informes.h"
#include "comida.h"


void mostrarComidas(eComida comidas[], int tam){
    printf(">>>>>Comidas<<<<<");
    printf("\nCodigo   ||   Descripcion   ||  Precio");
    for (int x = 0; x < tam; x++){
        mostrarComida(comidas[x]);
    }
    printf("\n");
    printf("\n");

}


void mostrarComida(eComida comida){
    printf("\n%5d\t      %10s      $%4.2f", comida.idComida, comida.descripcion, comida.precio);
}

void buscarComida(eComida comidas[], int tamCom, char * nombreComida, int idComida){
 for (int x = 0; x < tamCom; x++){
        if (comidas[x].idComida == idComida){
            strcpy(nombreComida, comidas[x].descripcion);
        }
    }
}
