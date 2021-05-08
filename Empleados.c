#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "empleados.h"
#include "sectores.h"
#include "utn_inputs.h"
#include "informes.h"
#include "datawarehouse.h"


void inicializarEmpleados(eEmpleado dotacion[], int tam){
    for (int x = 0; x < tam; x++){
        dotacion[x].isEmpty = 1;
    }
}

void mostrarEmpleado (eEmpleado emp, eSector sectores[], int tamsec){
    char nombreSector[20];
    buscarSector(emp.idSector, sectores, tamsec, nombreSector);
    printf("\n  %d    %10s%10s    %d       %c    %9.2f   %02d/%02d/%02d",
           emp.legajo,
           nombreSector,
           emp.nombre,
           emp.edad,
           toupper(emp.sexo),
           emp.sueldo,
           emp.fechaIngreso.dia,
           emp.fechaIngreso.mes,
           emp.fechaIngreso.anio
    );
}

void mostrarEmpleados (eEmpleado lista[], int tam, eSector sectores[], int tamsec){
        int flag = 0;
        printf("N° Legajo ||  Sector  || Nombre || Edad || Sexo || Sueldo || Fecha\n");
        for (int y = 0; y < tam; y++){
            if (!lista[y].isEmpty){
                flag = 1;
                mostrarEmpleado(lista[y], sectores, tamsec);
                printf("\n");
            }
        }
        if (!flag){
            printf("\nNo hay empleados que mostrar!\n");
        }
        printf("\n");
}

int buscarLibre(eEmpleado lista[], int tam){
    int index = -1;
    if (lista != NULL && tam > 0){
        for (int x = 0; x < tam; x++){
            if (lista[x].isEmpty){
                index = x;
            }
        }
    }
    return index;
}

int buscarEmpleado(eEmpleado lista[], int tam, int legajo){
    int indice = -1;
    for (int x = 0; x < tam; x++){
        if (lista[x].legajo == legajo && lista[x].isEmpty == 0){
            indice = x;
            break;
        }
    }
    return indice;
}

int ingresarEmpleado(eEmpleado nomina[], int tam, int *pId, eSector sector[], int tamsec){
    int allRight = 0;
    int indice;
    eEmpleado nuevoEmpleado; //esto es un auxiliar de seguridad que toma todos los datos

    if (nomina != NULL && tam > 0 && pId != NULL){
        indice =  buscarLibre(nomina, tam);
        if (indice >= 0){
                nuevoEmpleado.legajo = *pId;
                fflush(stdin);

                printf("\nIngreso de sector:\n");
                mostrarSectores(sector, tamsec);
                printf("\n\nSeleccione uno: ");
                while(obtenerSector(sector, tamsec, &nuevoEmpleado.idSector) < 0){
                   printf("\nError!Ingrese sector real!\n");
                }

                printf("Ingrese nombre\n");
                fflush(stdin);
                while(obtenerNombre(nuevoEmpleado.nombre) < 0){
                    printf("\nError!Ingrese nombre correcto\n");
                }

                printf("Ingrese edad\n");
                while (obtenerMayorDeEdad(&nuevoEmpleado.edad) < 0){
                    printf("\nError! Ingrese edad correcta!");
                }

                fflush(stdin);
                printf("Ingrese sexo (m/f)\n");
                while(obtenerSexo(&nuevoEmpleado.sexo) < 0){
                    printf("\nError! Ingrese sexo correcta!");
                }

                fflush(stdin);
                printf("Ingrese sueldo\n");
                while (obtenerSueldo(&nuevoEmpleado.sueldo) < 0){
                        printf("Error! Ingrese sueldo valido\n");
                }

                fflush(stdin);
                printf("Ingrese la fecha de ingreso (dd/mm/2021)\n");
                while  (obtenerFecha(&nuevoEmpleado.fechaIngreso.dia, &nuevoEmpleado.fechaIngreso.mes, &nuevoEmpleado.fechaIngreso.anio) < 0){
                    printf("\nError! Ingrese fecha valida (dd/mm/2021)\n");
                }

                system("cls");

                nuevoEmpleado.isEmpty = 0;

                nomina[indice] = nuevoEmpleado;

                printf("\nA %s se le ha asignado el legajo N %d\n", nomina[indice].nombre, nomina[indice].legajo);

                (*pId)++;

                allRight = 1;

        } else {
            printf("No hay lugar libre!\n");
            allRight = 0;
        }
    }
    return allRight;
}


int menu(){
    int opcion;
    fflush(stdin);
    printf("\t\t***Menu principal***");
    printf("\n1. ALTAS");
    printf("\n2. MODIFICAR");
    printf("\n3. BAJA");
    printf("\n4. LISTAR EMPLEADOS");
    printf("\n5. ORDENAR EMPLEADOS");//CAMBIAR ORDENAR EMPLEADOS
    printf("\n6. INFORMES");//CAMBIAR POR "INFORMES" Y AGREGAR SUBMENU
    printf("\n7. COMIDAS");
    printf("\n8. ALTA DE ALMUERZO");
    printf("\n9. MOSTRAR ALMUERZOS");
    printf("\n10. Mostrar almuerzos por empleado");
    printf("\n11. Gasto de almuerzo por empleado");
    printf("\n12. Salir");
    printf("\nSeleccione una opcion: ");
    scanf("%d", &opcion);
    system("cls");
    return opcion;
}

int hayEmpleado(eEmpleado lista[], int tam){
    int allRight = 0;
    if (lista != NULL && tam > 0){
       for (int x = 0; x < tam; x++){
            if (lista[x].isEmpty == 0){
                allRight = 1;
                break;
            }
        }
    }
    return allRight;
}

int bajaEmpleado(eEmpleado lista[], int tam, eSector sector[], int tamsec){
    int allRight = 0;
    int legajo;
    char respuesta;
    int indice;
    if (lista != NULL && tam > 0){

        if (!hayEmpleado(lista, tam)){
            printf("\nNo hay empleados cargados en sistema.\n");
        } else {
            printf("\nIngrese el legajo del cliente a eliminar\n");
            scanf("%d", &legajo);
            indice = buscarEmpleado(lista, tam, legajo);
            if (indice == -1){
            printf("\nNo existe empleado con ese N de legajo\n");
            } else {
                printf("\n");
                printf("N° Legajo || Sector || Nombre || Edad || Sexo || Sueldo|| Fecha\n");
                mostrarEmpleado(lista[indice], sector, tamsec);
                printf("\nRealmente quiere dar de baja el empleado? (s/n)\n");
                fflush(stdin);
                scanf("%c", &respuesta);

                if (respuesta == 's'){
                    lista[indice].isEmpty = 1;
                    //ELIMINAR ALMUERZO TAMBIEN
                    allRight = 1;
                }
            }
        }
    }
    return allRight;
}

int obtenerSector(eSector sector[], int tamsec, int * idSector){
    int allRight = -1;
    char buffer[64];

    if (idSector != NULL && sector != NULL && tamsec > 0){
        if (fixedGets(buffer, sizeof(buffer)) == 0 && esEntero(buffer)){
            *idSector = atoi(buffer);
            if (*idSector >= sector[0].id && *idSector <= sector[tamsec-1].id){
                allRight = 0;
            }
        }
    }
    return allRight;
}

int modificarEmpleado(eEmpleado lista[], int tam, eSector sector[], int tamsec){
    int allRight = 0;
    int legajo;
    int opcion;
    char respuesta;
    int indice;
    if (lista != NULL && tam > 0){

        if (!hayEmpleado(lista, tam)){
            printf("\nNo hay empleados cargados en sistema.\n");
        } else {
            printf("\nIngrese el legajo del cliente a modificar\n");
            scanf("%d", &legajo);
            indice = buscarEmpleado(lista, tam, legajo);
            if (indice == -1){
            printf("\nNo existe empleado con ese N de legajo\n");
            } else {
                printf("\n");
                printf("N° Legajo || Sector || Nombre || Edad || Sexo || Sueldo|| Fecha\n");
                mostrarEmpleado(lista[indice], sector, tamsec);
                printf("\n\nRealmente quiere modificar los datos de empleado? (s/n)\n");
                fflush(stdin);
                scanf("%c", &respuesta);
                system("cls");
                fflush(stdin);

                if (respuesta == 's'){
                    printf("1.Modificar sector\n");
                    printf("2.Modificar nombre\n");
                    printf("3.Modificar edad\n");
                    printf("4.Modificar edad\n");
                    printf("5.Modificar sueldo\n");
                    printf("\nIngrese opcion:\n");
                    scanf("%d", &opcion);
                    fflush(stdin);
                    switch(opcion){
                        case 1:
                            printf("\nIngreso nuevo sector:\n");
                            mostrarSectores(sector, tamsec);
                            printf("\n\nSeleccione uno: ");
                            while(obtenerSector(sector, tamsec, &lista[indice].idSector) < 0){
                            printf("\nError!Ingrese sector real!\n");
                            }
                        break;
                        case 2:
                            printf("Ingrese nuevo nombre\n");
                            while(obtenerNombre(lista[indice].nombre) < 0){
                                printf("\nError!Ingrese nombre correcto\n");
                            }
                        break;
                        case 3:
                            printf("Ingrese nueva edad\n");
                            while (obtenerMayorDeEdad(&lista[indice].edad) < 0){
                                printf("\nError! Ingrese edad correcta!");
                            }
                        break;
                        case 4:
                             do{
                                printf("Ingrese nuevo sexo (m/f)\n");
                                fflush(stdin);
                                scanf("%c", &lista[indice].sexo);

                                if (tolower(lista[indice].sexo) != 'm' && tolower(lista[indice].sexo) != 'f'){
                                    printf("\nError! Ingrese sexo\n");
                                    fflush(stdin);
                                    scanf("%c", &lista[indice].sexo);
                                }

                            } while (tolower(lista[indice].sexo) != 'm' && tolower(lista[indice].sexo) != 'f');
                        break;
                        case 5:
                            printf("Ingrese nuevo sueldo\n");
                            while (obtenerSueldo(&lista[indice].sueldo) < 0){
                            printf("Error! Ingrese sueldo valido\n");
                            }
                        break;
                        default:
                            printf("\nOpcion incorrecta!\n");
                    }
                } else {
                    printf("\nModificacion exitosa\n");
                    allRight = 0;
                }
            allRight = 1;
            }
        }
    }
    return allRight;
}

int buscarNombreEmpleado(eEmpleado lista[], int tam, int legajo, char * nombreEmpleado){
    int allRight = 0;
    for (int x = 0; x < tam; x++){
        if (lista[x].legajo == legajo && lista[x].isEmpty == 0){
            strcpy(nombreEmpleado, lista[x].nombre);
            allRight = 1;
            break;
        }
    }
    return allRight;
}

int menuOrdenar(){
    int opcion;
    printf("\n1.Ordenar por legajo");
    printf("\n2. Ordenar por nombre");
    printf("\n3. Ordenar por edad");
    printf("\n4. Ordenar por sueldo");
    scanf("%d", &opcion);
    system("cls");
    return opcion;

}

int ordenarEmpleados(eEmpleado lista[], int tam, eSector sectores[], int tamsec){
    int allRight = 1;
    int opcion;
    int orden;
    eEmpleado auxEmpleado;
    opcion = menuOrdenar();
    printf("\n\nOrden ascendente(1) o descendente(2)?");
    scanf("%d", &orden);
    switch (opcion){
    case 1:
        for (int x = 0; x < tam - 1; x++){
            for (int y = x + 1; y < tam; y++){
                if ((lista[x].legajo > lista[y].legajo && orden == 1) || (lista[x].legajo < lista[y].legajo && orden == 2)){
                    auxEmpleado = lista[x];
                    lista[x] = lista[y];
                    lista[y] = auxEmpleado;
                }
            }
        }
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    }
    mostrarEmpleados(lista, tam, sectores, tamsec);
    return allRight;
}


