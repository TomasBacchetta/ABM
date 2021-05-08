#include "fecha.h"
#include "comida.h"
#include "empleados.h"
#ifndef ALMUERZO_H_INCLUDED
#define ALMUERZO_H_INCLUDED

struct{
    int idAlmuerzo;
    int legajo;
    int idComida;
    eFecha fechaAlmuerzo;
    int isEmpty;
    }typedef eAlmuerzo;

#endif // ALMUERZO_H_INCLUDED


void altaAlmuerzo(eEmpleado lista[], int tamEmp, eSector sectores[], int tamsec, eComida comidas[], int tamCom, eAlmuerzo almuerzos[], int TAMALMU, int * idAlmuerzo);
void inicializarAlmuerzos(eAlmuerzo almuerzos[], int tam);
int buscarLibreAlmuerzo(eAlmuerzo almuerzo[], int tam);
void mostrarAlmuerzo(eAlmuerzo almuerzo, eComida comidas[], int tamCom, eEmpleado lista[], int tam);
void mostrarAlmuerzos(eAlmuerzo almuerzos[], int tamAlmu, eComida comidas[], int tamCom, eEmpleado lista[], int tam);
void hardcodearAlmuerzos(eAlmuerzo almuerzos[], int tamAlmu , int * proxIdAlmu);
void totalGastoAlmuerzo (eEmpleado lista[], int tam, eSector sectores[], int tamsec, eAlmuerzo almuerzos[], int tamAlmu, eComida comidas[], int tamCom);
