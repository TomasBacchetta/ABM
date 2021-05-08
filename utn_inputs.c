#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "empleados.h"
#include "sectores.h"
#include "utn_inputs.h"


int obtenerNombre(char * cadenaTexto)
{
    int allRight = -1;
    char buffer[64];
    if (cadenaTexto != NULL)
    {
        if (fixedGets(buffer, sizeof(buffer)) == 0 && esNombre(buffer) && formatearNombre(buffer))
        {
            strncpy(cadenaTexto, buffer, 20);
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

int obtenerPorcentaje(int * porcentaje)
{
    int allRight = -1;
    char buffer[64];

    if (porcentaje != NULL)
    {
        if (fixedGets(buffer, sizeof(buffer)) == 0 && esEntero(buffer))
        {
            *porcentaje = atoi(buffer);
            if (*porcentaje > 0){
               allRight = 0;
            }

        }
   }
    return allRight;
}

int esFloat(char * cadena)
{
    int allRight = 1; //inicia en verdadero, y de no cumplir algun requisito la funcion le asignara el 0
    int contadorPunto = 0;
    int stop = 0;

    if (cadena != NULL && strlen(cadena) > 0){ //si el puntero cadena no apunta al vacio y su largo es mayor a 0
        for (int x = 0; x < strlen(cadena) && !stop ; x++)
        {
            if (cadena[x] < '0' || cadena[x] > '9') //si el caracter no es numerico
            {
                switch(cadena[x]){
                    case '.':
                        if (contadorPunto > 1 || x == 0 || x == strlen(cadena)-1 || (x == 1 && cadena[0] == '-')) //si hay mas de un punto, o si este esta al final o al principio, o si prosigue a un signo negativo
                    {
                        allRight = 0;
                        stop = 1; //finaliza la iteracion (utilizar break entraria en conflicto con el switch)
                    }
                    break;
                    case '-':
                        if (x != 0 || strlen(cadena) == 1) //si el signo negativo no se encuentra al principio o si la cadena tiene solo 1 elemento
                        {
                            allRight = 0;
                            stop = 1;
                        }
                    break;
                    default:
                    allRight = 0;
                    stop = 1;
                }
            }
        }
    }
    return allRight;
}

int obtenerSueldo(float * sueldo)
{
    int allRight = -1;
    char buffer[64];
    fflush(stdin);
    if (sueldo != NULL)
    {
        if (fixedGets(buffer, sizeof(buffer)) == 0 && esFloat(buffer))
        {
            *sueldo = atof(buffer);
            if (*sueldo > 0){
               allRight = 0;
            }

        }
   }
    return allRight;
}

int obtenerFecha(int * dia, int * mes, int * anio){
    int allRight = -1;
    char buffer[64];
    int diaNum;
    int mesNum;
    int anioNum;

    if (dia != NULL && mes != NULL && anio != NULL){
        if (fixedGets(buffer, sizeof(buffer)) == 0 && esFecha(buffer, &diaNum, &mesNum, &anioNum)){
            *dia = diaNum;
            *mes = mesNum;
            *anio = anioNum;

            allRight = 0;
        }

    }
    return allRight;
}

int esFecha (char * fecha, int * pDia, int * pMes, int * pAnio){
    int allRight = 1;
    char dia[10];
    char mes[10];
    char anio[10];
    int diaNum;
    int mesNum;
    int anioNum;
    if (fecha != NULL && pDia != NULL && pMes != NULL && pAnio != NULL){
        if (strlen(fecha) != 10){
            allRight = 0;
        } else {
            strncpy(dia, &fecha[0], 2);
            dia[2] = '\0';//SEGURIDAD
            strncpy(mes, &fecha[3], 2);
            mes[2] = '\0';
            strncpy(anio, &fecha[6], 4);
            anio[4] = '\0';

            if (!esEntero(dia) || !esEntero(mes) || !esEntero(anio)){
                allRight = 0;
            } else {
                diaNum = atoi(dia);
                mesNum = atoi(mes);
                anioNum = atoi(anio);
            if (mesNum < 1 || mesNum > 12 || diaNum < 1 || diaNum > diasDelMes(mesNum) || fecha[2] != '/' || fecha[5] != '/' || anioNum != 2021){
                    allRight = 0;
                } else {
                    *pDia = diaNum;
                    *pMes = mesNum;
                    *pAnio = anioNum;
                }
            }
        }
    } else {
        allRight = 0;
    }

    return allRight;
}

int diasDelMes(int mes){
    int diasMaximos;
    if (mes <= 7){
        if (mes == 2){
            diasMaximos = 28;
        } else {
            if (mes % 2 == 0){
                diasMaximos = 30;
            } else {
                diasMaximos = 31;
            }
        }
    } else {
        if (mes % 2 == 0){
            diasMaximos = 31;
        } else {
            diasMaximos = 30;
        }
    }
    return diasMaximos;
}

int obtenerSexo(char * sexo){
    int allRight = -1;
    char buffer[64];
    if (sexo != NULL){
        if (fixedGets(buffer, sizeof(buffer)) == 0 && esSexo(buffer)){
            strncpy(sexo, buffer, 1);

            allRight = 0;
        }
    }
    return allRight;
}

int esSexo(char * sexo){
    int allRight = 0;
    if (sexo != NULL){
        if (tolower(sexo[0]) == 'm' || tolower(sexo[0]) == 'f'){
            allRight = 1;
        }
    }
    return allRight;
}
