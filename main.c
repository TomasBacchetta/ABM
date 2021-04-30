#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Empleados.h"
#include "sectores.h"
#define TAM 20
#define TAMSEC 5 //son 5 sectores


void mostrarSector(eSector sector);
void mostrarSectores(eSector sector[], int tam);
void buscarSector(int legajo, eSector sector[], int tam, char * nombreSector);
int main()
{
    eSector sectores[TAMSEC] ={
        {500, "Sistemas"},
        {501, "RRHH"},
        {502, "Cobranzas"},
        {503, "Legales"},
        {504, "Ventas"}
    };
    eEmpleado dotacion[TAM];
    char respuesta = 'n';
    int proximoId = 20000;
    inicializarEmpleados(dotacion, TAM);

    do{
        switch(menu()){
        case 1://ALTAS
            if (ingresarEmpleado(dotacion, TAM, &proximoId, sectores, TAMSEC)){
                printf("\nAlta exitosa\n\n");
            } else {
                printf("\nHubo un problema al dar el alta.\n\n");
            }

            break;
        case 2://MODIFICAR
            printf("\nAqui puede modificar los datos del empleado\n");

            break;
        case 3://BAJA
            if(bajaEmpleado(dotacion, TAM, sectores, TAMSEC)){
                printf("\nBaja exitosa\n\n");
            } else {
                printf("\nHubo un problema al dar de baja\n\n");
            }
            break;
        case 4://LISTAR EMPLEADOS
            mostrarEmpleados (dotacion, TAM, sectores, TAMSEC);
            break;
        case 5://ORDENAR EMPLEADOS
            break;
        case 6://INFORMES
            mostrarSectores(sectores, TAMSEC);
            break;
        case 7:
            printf("Desea salir? (s/n) ");
            fflush(stdin);
            scanf("%c", &respuesta);
            break;

        default:
            printf("\nOpcion incorrecta!\n");
        }
        system("pause");
        system("cls");

    } while (respuesta == 'n');

    return 0;
}





