#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED
#include "sectores.h"


struct{
    int dia;
    int mes;
    int anio;
} typedef eFecha;

struct {
    int legajo;
    char nombre[20];
    int edad;
    char sexo;
    float sueldo;
    eFecha fechaIngreso;
    int idSector;
    int isEmpty;

} typedef eEmpleado;



#endif // EMPLEADOS_H_INCLUDED


void inicializarEmpleados(eEmpleado dotacion[], int tam);
void mostrarEmpleado (eEmpleado emp, eSector sectores[], int tamsec);
void mostrarEmpleados (eEmpleado lista[], int tam, eSector sectores[], int tamsec);
int buscarLibre(eEmpleado lista[], int tam);
int buscarEmpleado(eEmpleado lista[], int tam, int legajo, eSector sector[]);
int ingresarEmpleado(eEmpleado nomina[], int tam, int * pId, eSector sector[], int tamsec);
int obtenerNombre(char * cadenaTexto);
int esNombre(char * cadena);
int fixedGets(char * cadena, int longitud);
int esEntero(char * cadena);
int obtenerMayorDeEdad(int * edad);
int formatearNombre(char * cadena);
int hayEmpleado(eEmpleado lista[], int tam);
int bajaEmpleado(eEmpleado lista[], int tam, eSector sector[], int tamsec);
int menu();
