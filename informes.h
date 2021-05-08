#include "empleados.h"
#include "almuerzo.h"
#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED


void empleadosSector(eEmpleado lista[], int tam, eSector sectores[], int tamsec);
void actualizarSueldosXSector(eEmpleado lista[], int tam, eSector sectores[], int tamsec);
void totalSueldos(eEmpleado lista[], int tam, eSector sectores[], int tamsec);
void menuInformes(eEmpleado dotacion[], int tam, eSector sectores[], int tamsec);
int sectorMasRico(eEmpleado lista[], int tam, eSector sectores[], int tamsec);
void mostrarAlmuerzoEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamsec, eAlmuerzo almuerzos[], int tamAlmu, eComida comidas[], int tamCom);
