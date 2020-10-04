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

/***************************************************/
/* Funcion: InsertSort    Fecha: 04/10/2020        */
/* Autores: Isaac Barriales & Jose A. Bravo        */  
/* Entrada:                                        */
/* tabla: puntero a integer que se va a ordenar    */
/* ip: El indice del primer elemento de la tabla   */
/* iu: El indice del último elemento de la tabla   */
/* Salida                                          */
/* Count: El Nº de veces que se ejecuta la OB      */
/***************************************************/
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

int InsertSortInv(int* tabla, int ip, int iu)
{
  /* vuestro codigo */
}


