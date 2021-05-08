#ifndef COMIDA_H_INCLUDED
#define COMIDA_H_INCLUDED

struct{
    int idComida;
    char descripcion[20];
    float precio;
    int isEmpty;
} typedef eComida;

#endif // COMIDA_H_INCLUDED

void mostrarComidas(eComida comidas[], int tam);
void mostrarComida(eComida comida);
void buscarComida(eComida comidas[], int tamAlmu, char * nombreComida, int idComida);
