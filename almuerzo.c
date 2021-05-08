#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "empleados.h"
#include "sectores.h"
#include "informes.h"
#include "comida.h"
#include "almuerzo.h"
#include "utn_inputs.h"
#include "datawarehouse.h"


void altaAlmuerzo(eEmpleado lista[], int tamEmp, eSector sectores[], int tamsec, eComida comidas[], int tamCom, eAlmuerzo almuerzos[], int tamAlmu, int * idAlmuerzo){
    int legajo;
    int indice;
    int idComida;
    eAlmuerzo auxAlmuerzo;

    fflush(stdin);
    mostrarEmpleados(lista, tamEmp, sectores, tamsec);
    printf("\nIngrese el legajo del empleado para establecer almuerzo\n");
    scanf("%d", &legajo);
    while(buscarEmpleado(lista, tamEmp, legajo) < 0){
        printf("\nError! No existe el empleado. Ingrese legajo correcto: \n");
        scanf("%d", &legajo);
    }
    indice = buscarLibreAlmuerzo(almuerzos, tamAlmu);
    if (indice == -1){
    printf("\nNo hay almuerzos libres!\n");
    } else {
        system("cls");
        auxAlmuerzo.legajo = legajo;
        mostrarComidas(comidas, tamCom);
        printf("\n");
        printf("\nSeleccione una comida: \n");
        scanf("%d", &idComida);
        auxAlmuerzo.idComida = idComida;
        fflush(stdin);
        printf("Ingrese la fecha de almuerzo (dd/mm/2021)\n");
        while (obtenerFecha(&auxAlmuerzo.fechaAlmuerzo.dia, &auxAlmuerzo.fechaAlmuerzo.mes, &auxAlmuerzo.fechaAlmuerzo.anio) < 0){
            printf("\nError! Ingrese fecha valida (dd/mm/2021)\n");
        }
        auxAlmuerzo.isEmpty = 0;

        almuerzos[indice] = auxAlmuerzo;

        printf("\n\nCarga de almuerzo exitosa\n");
    }


//muestra empleados y pide legajo,+
//despues muestra las comidas, se fija si hay lugar,+
//si no encuentra lugar dice que no hay lugar, si encuentra lugar+
//muestra comidas y pide id+
//pide fecha+
//guarda todo en un auxiliar+
//una vez valido copia auxiliar en almuerzo en posicion indice de array de almuerzo+
}
int buscarLibreAlmuerzo(eAlmuerzo almuerzo[], int tam){
    int index = -1;
    if (almuerzo != NULL && tam > 0){
        for (int x = 0; x < tam; x++){
            if (almuerzo[x].isEmpty){
                index = x;
            }
        }
    }
    return index;
}


void inicializarAlmuerzos(eAlmuerzo almuerzos[], int tam){
    for (int x = 0; x < tam; x++){
        almuerzos[x].isEmpty = 1;
    }
}

void mostrarAlmuerzo(eAlmuerzo almuerzo, eComida comidas[], int tamCom, eEmpleado lista[], int tam){
    int idComida = almuerzo.idComida;
    char nombreComida[20];
    char nombreEmpleado[20];
    buscarComida(comidas, tamCom, nombreComida, idComida);
    buscarNombreEmpleado(lista, tam, almuerzo.legajo, nombreEmpleado);
    printf("%d       %s   %s   %02d/%02d/%d", almuerzo.legajo, nombreEmpleado, nombreComida,
           almuerzo.fechaAlmuerzo.dia,
           almuerzo.fechaAlmuerzo.mes,
           almuerzo.fechaAlmuerzo.anio);
}


void mostrarAlmuerzos(eAlmuerzo almuerzos[], int tamAlmu, eComida comidas[], int tamCom, eEmpleado lista[], int tam){
    int flag = 0;
    printf("Legajo  ||  Nombre  || Comida ||  Fecha");
    printf("\n");
    for (int x = 0; x < tamAlmu; x++){
        if (!almuerzos[x].isEmpty){
            flag = 1;
            mostrarAlmuerzo(almuerzos[x], comidas, tamCom, lista, tam);
            printf("\n");
        }
    }
    if (!flag){
        printf("\nNo hay almuerzos que mostrar!");
        printf("\n");
    }
}



void mostrarAlmuerzoEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamsec, eAlmuerzo almuerzos[], int tamAlmu, eComida comidas[], int tamCom){
    int flag = 0;
    int legajo;
    mostrarEmpleados(lista, tam, sectores, tamsec);
    printf("\nIngrese el legajo del empleado: \n");
    scanf("%d", &legajo);
    system("cls");
    printf("Legajo  ||  Nombre  || Comida ||  Fecha");
    printf("\n");
    for (int x = 0; x < tamAlmu; x++){
        if (almuerzos[x].legajo == legajo && !almuerzos[x].isEmpty){
            flag = 1;
            mostrarAlmuerzo(almuerzos[x], comidas, tamCom, lista, tam);
            printf("\n");
        }
    }
    if (!flag){
        printf("\nNo hay almuerzos que mostrar!");
    }
}

void totalGastoAlmuerzo (eEmpleado lista[], int tam, eSector sectores[], int tamsec, eAlmuerzo almuerzos[], int tamAlmu, eComida comidas[], int tamCom){
    int flag = 0;
    int legajo;
    float totalGastos = 0;
    mostrarEmpleados(lista, tam, sectores, tamsec);
    printf("\nIngrese el legajo del empleado: \n");
    scanf("%d", &legajo);
    system("cls");
    for (int x = 0; x < tamAlmu; x++){
        if (almuerzos[x].legajo == legajo && !almuerzos[x].isEmpty){
            flag = 1;
            for (int y = 0; y < tamCom; y++){
                if (almuerzos[x].idComida == comidas[y].idComida){
                    totalGastos += comidas[y].precio;
                }
            }
        }
    }
    printf("El total de gastos en comida del empleado es de: $%.2f\n", totalGastos);
    if (!flag){
        printf("\nEl empleado no tiene almuerzos!\n");
    }
}

