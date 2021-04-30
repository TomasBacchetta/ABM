#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Empleados.h"
#include "sectores.h"

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

int buscarEmpleado(eEmpleado lista[], int tam, int legajo, eSector sector[]){
    int indice = -1;
    for (int x = 0; x < tam; x++){
        if (lista[x].legajo == legajo){
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
                scanf("%d", &nuevoEmpleado.idSector);

                printf("Ingrese nombre\n");
                fflush(stdin);
                while(obtenerNombre(nuevoEmpleado.nombre) < 0){
                    printf("\nError!Ingrese nombre correcto\n");
                }

                printf("Ingrese edad\n");
                while (obtenerMayorDeEdad(&nuevoEmpleado.edad) < 0){
                    printf("\nError! Ingrese edad correcta!");
                }

                do{
                printf("Ingrese sexo (m/f)\n");
                fflush(stdin);
                scanf("%c", &nuevoEmpleado.sexo);

                if (tolower(nuevoEmpleado.sexo) != 'm' && tolower(nuevoEmpleado.sexo) != 'f'){
                    printf("\nError! Ingrese sexo\n");
                    fflush(stdin);
                    scanf("%c", &nuevoEmpleado.sexo);
                }

                } while (tolower(nuevoEmpleado.sexo) != 'm' && tolower(nuevoEmpleado.sexo) != 'f');

                printf("Ingrese sueldo\n");
                scanf("%f", &nuevoEmpleado.sueldo);

                printf("Ingrese la fecha de hoy\n");
                scanf("%d/%d/%d", &nuevoEmpleado.fechaIngreso.dia, &nuevoEmpleado.fechaIngreso.mes, &nuevoEmpleado.fechaIngreso.anio);
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

int obtenerNombre(char * cadenaTexto)
{
    int allRight = -1;

    if (cadenaTexto != NULL)
    {
        if (fixedGets(cadenaTexto, sizeof(cadenaTexto)) == 0 && esNombre(cadenaTexto) && formatearNombre(cadenaTexto))
        {
            allRight = 0;
        }

    }
    return allRight;
}

int esNombre(char * cadena)
{
    int allRight = 0;
    if (cadena != NULL && sizeof(cadena) > 0)
    {
        allRight = 1;
        for (int x = 0; x < cadena[x] && cadena[x] != '\0'; x++)
        {
            if (((cadena[x] < 65 || cadena[x] > 122) && cadena[x] != ' ' && cadena[x] != '\n') || cadena[0] == ' ' || cadena[strlen(cadena)-2] == ' ') //si no es texto incluyendo espacio y salto de linea, mientras que el espacio no este adelante o al final de la cadena
            {
                allRight = 0;
                break;
            }
            if (x > 0)  //evita leer fuera del rango de cadena
            {
                if (cadena[x - 1] == ' ' && cadena[x] == ' ')  //si hay por lo menos dos espacios consecutivos
                {
                    allRight = 0;
                    break;
                }
            }
        }
    }
    return allRight;
}

int fixedGets(char * cadena, int longitud)
{
    int allRight = -1;
    if (cadena != NULL && longitud > 0 && fgets(cadena, longitud, stdin)== cadena  && cadena[0] != '\n')
    {
        fflush(stdin);
        if (cadena[strlen(cadena)-1] == '\n')
        {
            cadena[strlen(cadena)-1] = '\0';
        }
        allRight = 0;
    }
    return allRight;
}

int esEntero(char * cadena) //modificar
{
    int allRight = 1; //inicia en verdadero, y de no cumplir algun requisito la funcion le asignara el 0

    if (cadena != NULL && strlen(cadena) > 0){ //si el puntero cadena no apunta al vacio y su largo es mayor a 0
        for (int x = 0; x < strlen(cadena); x++)
        {
            if (cadena[x] < '0' || cadena[x] > '9') //si el caracter no es numerico
            {
                allRight = 0;
                break;
            }
        }
    }
    return allRight;
}

int obtenerMayorDeEdad(int * edad)
{
    int allRight = -1;
    char buffer[64];

    if (edad != NULL)
    {
        if (fixedGets(buffer, sizeof(buffer)) == 0 && esEntero(buffer))
        {
            *edad = atoi(buffer);
            if (*edad >= 18 && *edad <= 99){
               allRight = 0;
            }

        }
   }
    return allRight;
}

int formatearNombre(char * cadena)
{
    int allRight = 0;
    if (cadena != NULL && sizeof(cadena) > 0) //mayuscula para el primer caracter si la necesita
    {
        if (cadena[0] >= 97 && cadena[0] <= 122)
        {
            cadena[0] -= 32;
        }
        for (int x = 1; cadena[x] != '\0'; x++)
        {
            if (cadena[x] >= 65 && cadena[x] <= 90) //minuscula para el caracter que la necesite
            {
                cadena[x] += 32;
            }
            if (x > 0)  //para no leer la posicion de memoria anterior a la cadena
            {
                if (cadena[x-1] == ' ')  //para darle mayuscula a iniciales de nombres o apellidos dobles que la necesiten
                {
                    if (cadena[x] >= 97 && cadena[x] <= 122)
                    {
                        cadena[x] -= 32;
                    }
                }
            }
        }
        allRight = 1;
    }
    return allRight;
}

int menu(){
    int opcion;

    printf("\t\t***Menu principal***");
    printf("\n1. ALTAS");
    printf("\n2. MODIFICAR");
    printf("\n3. BAJA");
    printf("\n4. LISTAR EMPLEADOS");
    printf("\n5. ORDENAR EMPLEADOS");
    printf("\n6. INFORMES");
    printf("\n7. SALIR");
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
    char nombreSector[20];
    int indice;
    if (lista != NULL && tam > 0){

        if (!hayEmpleado(lista, tam)){
            printf("\nNo hay empleados cargados en sistema.\n");
        } else {
            printf("\nIngrese el legajo del cliente a eliminar\n");
            scanf("%d", &legajo);
            indice = buscarEmpleado(lista, tam, legajo, sector);
            if (indice == -1){
            printf("\nNo existe empleado con ese N de legajo\n");
            } else {
                printf("\n");
                printf("N° Legajo || Nombre || Edad || Sexo || Sueldo|| Fecha\n");
                mostrarEmpleado(lista[indice], sector, tamsec);
                printf("\nRealmente quiere dar de baja el empleado? (s/n)\n");
                fflush(stdin);
                scanf("%c", &respuesta);

                if (respuesta == 's'){
                    lista[indice].isEmpty = 1;
                } else {
                    printf("\nNo se ha dado de baja al empleado\n");
                    allRight = 0;
                }
            allRight = 1;
            }
        }
    }
    return allRight;
}
