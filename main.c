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

#define TAM 10
#define TAMSEC 5 //son 5 sectores
#define TAMCOM 5
#define TAMALMU 10



int main()
{
    eEmpleado dotacion[TAM];

        eSector sectores[TAMSEC] ={
        {500, "Sistemas"},
        {501, "RRHH"},
        {502, "Cobranzas"},
        {503, "Legales"},
        {504, "Ventas"}
    };

    eComida comidas[TAMCOM] ={
        {1000, "Churrasco", 100, 0},
        {1001, "Pico Dulce", 30, 0},
        {1002, "Bondiola", 90, 0},
        {1003, "Pure", 40, 0},
        {1004, "Engrudo", 2, 0}
    };

    eAlmuerzo almuerzos[TAMALMU];

    int proximoId = 20000;
    int proximoIdAlmuerzo = 100;
    inicializarEmpleados(dotacion, TAM);
    inicializarAlmuerzos(almuerzos, TAMALMU);
    hardcodearEmpleados(dotacion, TAM, &proximoId);
    hardcodearAlmuerzos(almuerzos, TAMALMU, &proximoIdAlmuerzo);

    char respuesta = 'n';



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
            modificarEmpleado(dotacion, TAM, sectores, TAMSEC);

            break;
        case 3://BAJA
            if(bajaEmpleado(dotacion, TAM, sectores, TAMSEC)){
                printf("\nBaja exitosa\n\n");
            } else {
                printf("\nNo se dio de baja\n\n");
            }
            break;
        case 4://LISTAR EMPLEADOS
            mostrarEmpleados (dotacion, TAM, sectores, TAMSEC);
            break;
        case 5://ORDENAR EMPLEADOS
            ordenarEmpleados(dotacion, TAM, sectores, TAMSEC);
            break;
        case 6://INFORMES
            menuInformes(dotacion, TAM, sectores, TAMSEC);
            break;
        case 7:
            mostrarComidas(comidas, TAMCOM);
            break;
        case 8:
            altaAlmuerzo(dotacion, TAM, sectores, TAMSEC, comidas, TAMCOM, almuerzos, TAMALMU, &proximoIdAlmuerzo);
            break;
        case 9:
            mostrarAlmuerzos(almuerzos, TAMALMU, comidas, TAMCOM, dotacion, TAM);
            break;
        case 10:
            mostrarAlmuerzoEmpleado(dotacion, TAM, sectores, TAMSEC, almuerzos, TAMALMU, comidas, TAMCOM);
            break;
        case 11:
            totalGastoAlmuerzo (dotacion, TAM, sectores, TAMSEC, almuerzos, TAMALMU, comidas, TAMCOM);
            break;
        case 12:
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





