#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn_inputs.h"
#include "empleados.h"
#include "sectores.h"
#include "informes.h"

int sectorMasRico(eEmpleado lista[], int tam, eSector sectores[], int tamsec){
    int allRight = 0;
    float sueldosTotales[tamsec];
    float auxFloat;
    int mayor;

    for (int x = 0; x < tamsec; x++){
       for (int y = 0; y < tam; y++){
            if (lista[y].idSector == sectores[x].id && lista[y].isEmpty == 0){//busca un empleado con el sector del indice y se fija que no este vacio
                auxFloat += lista[y].sueldo;
            }
        }
        sueldosTotales[x] = auxFloat;
        auxFloat = 0;
    }

    for (int z = 0; z < tamsec; z++){
        if (z == 0){
            mayor = sueldosTotales[z];
        } else {
            if (sueldosTotales[z] >= mayor){
                mayor = sueldosTotales[z];
            }
        }
    }


    printf("\nEl sector con sueldos mas altos es:");

for (int s = 0; s < tamsec; s++){
    if (sueldosTotales[s] == mayor){
        printf("\n%s", sectores[s].descripcion);
    }
}






    return allRight;
}
void totalSueldos(eEmpleado lista[], int tam, eSector sectores[], int tamsec){
    float acumuladorSector = 0;
    float acumuladorTotal = 0;
    for (int x = 0; x < tamsec; x++){
       printf("\nEl acumulado de sueldos del sector de %s ", sectores[x].descripcion);
        for (int y = 0; y < tam; y++){
            if (lista[y].idSector == sectores[x].id && lista[y].isEmpty == 0){
                acumuladorSector = acumuladorSector + lista[y].sueldo;
            }
        }
        printf("%.2f\n", acumuladorSector);
        acumuladorTotal = acumuladorTotal + acumuladorSector;
        acumuladorSector = 0;
        }
        printf("\nEl total de sueldos a pagar de toda la empresa es de %.2f\n", acumuladorTotal);
}

void menuInformes(eEmpleado dotacion[], int tam, eSector sectores[], int tamsec){
    int subOpcion;
    system("cls");
    printf("\n////Menu Informes///\n");
    printf("\n1. Mostrar cantidad de empleados de un sector");
    printf("\n2. Mostrar total de sueldos");
    printf("\n3. Aumentar sueldos");
    printf("\n4. Sector que mas cobra");
    printf("\n5. Volver");
    do{
    printf("\n\nSeleccione una opción:");
    scanf("%d", &subOpcion);

           switch(subOpcion){
        case 1:
            empleadosSector(dotacion, tam, sectores, tamsec);
            break;
        case 2:
            totalSueldos(dotacion, tam, sectores, tamsec);
            break;
        case 3:
            actualizarSueldosXSector(dotacion, tam, sectores, tamsec);
            break;
        case 4:
            sectorMasRico(dotacion, tam, sectores, tamsec);
            break;
        case 5:
            menu();
            break;
        default:
            printf("\nOpcion Invalida!");
        }
    }while (subOpcion != 1 && subOpcion != 2 && subOpcion != 3 && subOpcion != 4);

}

void empleadosSector(eEmpleado lista[], int tam, eSector sectores[], int tamsec){
    int idSector;
    int cantEmpleados = 0;
    char nombreSector[20];
    mostrarSectores(sectores, tamsec);
    printf("\n\nSeleccione uno: ");
    fflush(stdin);
    while(obtenerSector(sectores, tamsec, &idSector) < 0){
        printf("\nError!Ingrese sector real!\n");
    }

    for (int x = 0; x < tam; x++){
        if (lista[x].idSector == idSector && lista[x].isEmpty == 0){
            cantEmpleados++;
        }
    }
    buscarSector(idSector, sectores, tamsec, nombreSector);
    printf("\nLa cantidad de empleados en el sector %s es de %d\n", nombreSector, cantEmpleados);

}

void actualizarSueldosXSector(eEmpleado lista[], int tam, eSector sectores[], int tamsec){
    int idSector;
    int porcentaje;
    mostrarSectores(sectores, tamsec);
    printf("\n\nSeleccione uno: ");
    fflush(stdin);
    while(obtenerSector(sectores, tamsec, &idSector) < 0){
        printf("\nError!Ingrese sector real!\n");
    }
    printf("\nIngrese un porcentaje\n");
    while (obtenerPorcentaje(&porcentaje) < 0){
        printf("\nError! Ingrese porcentaje correcto!");
    }

    for (int x = 0; x < tam; x++){
        if (lista[x].idSector == idSector && lista[x].isEmpty == 0){
            lista[x].sueldo = lista[x].sueldo + (lista[x].sueldo * porcentaje/100);
        }

    }

    printf("\nModificiacion finalizada con exito\n");


}







