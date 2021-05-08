
#include "fecha.h"
#include "sectores.h"

#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED



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
/** \brief busca al empleado y devuelve el indice, siempre que este exista (tiene en cuenta si de dio de baja)
 *
 * \param lista[] eEmpleado
 * \param tam int
 * \param legajo int
 * \return int
 *
 */
int buscarEmpleado(eEmpleado lista[], int tam, int legajo);
int ingresarEmpleado(eEmpleado nomina[], int tam, int * pId, eSector sector[], int tamsec);
int hayEmpleado(eEmpleado lista[], int tam);
int bajaEmpleado(eEmpleado lista[], int tam, eSector sector[], int tamsec);
int obtenerSector(eSector sector[], int tamsec, int * idSector);
int modificarEmpleado(eEmpleado lista[], int tam, eSector sector[], int tamsec);
int buscarNombreEmpleado(eEmpleado lista[], int tam, int legajo, char * nombreEmpleado);
int menuOrdenar();
int ordenarEmpleados(eEmpleado lista[], int tam, eSector sectores[], int tamsec);
void hardcodearEmpleados(eEmpleado lista[], int tam, int * proxId);



int menu();
