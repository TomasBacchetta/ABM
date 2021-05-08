#ifndef SECTORES_H_INCLUDED
#define SECTORES_H_INCLUDED


struct{
    int id;
    char descripcion[20];
}typedef eSector;


#endif // SECTORES_H_INCLUDED

void mostrarSector(eSector sector);
void mostrarSectores(eSector sector[], int tam);
void buscarSector(int idSector, eSector sector[], int tam, char * nombreSector);
