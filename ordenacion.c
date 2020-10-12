/**
 *
 * Descripcion: Implementacion de funciones de ordenacion 
 *
 * Fichero: ordenacion.c
 * Autor: Carlos Aguirre
 * Version: 1.0
 * Fecha: 16-09-2019
 *
 */


#include "ordenacion.h"

/***********************************************************/
/* Funcion: InsertSort    Fecha: 04/10/2020                */
/* Autores: Isaac Barriales & Jose A. Bravo                */
/*                                                         */
/* Esta función devuelve el número de veces que            */
/* se ha ejecutado la OB en el caso de que la              */
/* tabla se ordene correctamente.                          */
/* Se ordena mediante el algortimo InsertSort              */  
/* Entrada:                                                */
/*     int* tabla: puntero a una tabla que se va a ordenar */
/*                 tabla != NULL                           */
/*     int ip: El indice del primer elemento de la tabla   */
/*                                                         */
/*     int iu: El indice del último elemento de la tabla   */
/*                                                         */
/* Salida                                                  */
/*     int count: El Nº de veces que se ejecuta la OB      */
/*                o ERR en caso de error                   */
/***********************************************************/
int InsertSort(int* tabla, int ip, int iu)
{
  int i,j;
  int aux, count=0;

  for(i=ip + 1; i<= iu; i++) {
    aux = tabla[i];
    j=i-1;
    while(j>=ip && tabla[j]>aux) {
      tabla[j+1] = tabla[j];
      j--;
      count++;
    }
    tabla[j+1] = aux;
  }

  return count;
}


/***********************************************************/
/* Funcion: InsertSortInv    Fecha: 06/10/2020             */
/* Autores: Isaac Barriales & Jose A. Bravo                */
/*                                                         */
/* Esta función devuelve el número de veces que            */
/* se ha ejecutado la OB en el caso de que la              */
/* tabla se ordene de mayor a menor correctamente.         */
/* La tabla se ordena mediante una variación del           */ 
/* algoritmo de InsertSort                                 */  
/* Entrada:                                                */
/*     int* tabla: puntero a una tabla que se va a ordenar */
/*                 tabla != NULL                           */
/*     int ip: El indice del primer elemento de la tabla   */
/*                                                         */
/*     int iu: El indice del último elemento de la tabla   */
/*                                                         */
/* Salida                                                  */
/*     int count: El Nº de veces que se ejecuta la OB      */
/*                o ERR en caso de error                   */
/***********************************************************/
int InsertSortInv(int* tabla, int ip, int iu)
{
  int i,j;
  int aux, count=0;

  for(i=iu - 1; i>= ip; i--) {
    aux = tabla[i];
    j=i+1;
    while(j<=iu && tabla[j]>aux) {
      tabla[j-1] = tabla[j];
      j++;
      count++;
    }
    tabla[j-1] = aux;
  }

  return count;
}


