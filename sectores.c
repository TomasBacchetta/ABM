#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Empleados.h"
#include "sectores.h"
#include "utn_inputs.h"
#include "informes.h"
#include "almuerzo.h"

void mostrarSectores(eSector sector[], int tam){
    printf("\nLista de sectores:\n");
    printf("\nID ||  Descripcion\n");
    for (int x = 0; x < tam; x++){
       mostrarSector(sector[x]);
    }
    printf("\n");
}

void mostrarSector(eSector sector){
    printf("\n%d    %s", sector.id, sector.descripcion);
}

void buscarSector(int idSector, eSector sector[], int tam, char * nombreSector){
    for (int x = 0; x < tam; x++){
        if (sector[x].id == idSector){
            strcpy(nombreSector,sector[x].descripcion);
        }
    }
}
