#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "empleados.h"
#include "sectores.h"
#include "informes.h"
#include "comida.h"
#include "almuerzo.h"
#include "datawarehouse.h"

void hardcodearEmpleados(eEmpleado lista[], int tam, int * proxId){
     char hNombres[10][20] = {"Johnny", "Jorge", "popopo", "Paula", "Pedro", "Carlos", "Anna", "Alex", "Ramon", "Quico"};

     char hSexos[10] = {'m','m','m','f','m','m','f','m','m','m'};

     int hEdades[10] = {23,40,21,32,35,39,63,19,40,31};

     float hSueldos[10] = {3000, 2000, 7000, 5500, 3200, 5000, 4800, 5000, 6100, 5000};

     eFecha hFecha[10] = {{11,11,1111},{11,11,1111},{11,11,1111},{11,11,1111},{11,11,1111},{11,11,1111},{11,11,1111},{11,11,1111},{11,11,1111},{11,11,1111}};

     int hIdSector[10] = {500, 501, 504, 503, 501, 500, 500, 501, 502, 502};

    for (int x = 0; x < tam; x++){
        lista[x].legajo = *proxId;
        (*proxId)++;
        strcpy(lista[x].nombre, hNombres[x]);
        lista[x].sexo = hSexos[x];
        lista[x].edad = hEdades[x];
        lista[x].idSector = hIdSector[x];
        lista[x].sueldo = hSueldos[x];
        lista[x].isEmpty = 0;
        lista[x].fechaIngreso = hFecha[x];

    }
}

void hardcodearAlmuerzos(eAlmuerzo almuerzos[], int tamAlmu , int * proxIdAlmu){
    int hLegajo[10] = {20000, 20009, 20007, 20005, 20006, 20000, 20005, 20009, 20001, 20007};

    int hIdComida[10] = {1000, 1003, 1001, 1004, 1002, 1002, 1003, 1000, 1002, 1004};

    eFecha hFechaAlmuerzo[10] = {

    {2,3,2021},
    {21,5,2021},
    {10,4,2021},
    {2,3,2021},
    {21,11,2021},
    {10,8,2021},
    {2,3,2021},
    {21,5,2021},
    {10,8,2021},
    {7,3,2021},

    };

    for (int x = 0; x < tamAlmu; x++){
        almuerzos[x].idAlmuerzo = *proxIdAlmu;
        (*proxIdAlmu)++;
        almuerzos[x].legajo = hLegajo[x];
        almuerzos[x].idComida = hIdComida[x];
        almuerzos[x].fechaAlmuerzo = hFechaAlmuerzo[x];
        almuerzos[x].isEmpty = 0;
    }
}
