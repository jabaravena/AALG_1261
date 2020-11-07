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
#include "permutaciones.h"
#include <stdlib.h>

void copy(int * tabla, int * aux, int ip, int iu);
int partir(int* tabla, int ip, int iu, int* pos);
int medio(int* tabla, int ip, int iu, int *pos);



/***********************************************************/
/* Funcion: InsertSort                  Fecha: 04/10/2020  */
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
/* Funcion: InsertSortInv              Fecha: 06/10/2020   */
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



/***********************************************************/
/* Funcion: mergesort                   Fecha: 02/11/2020  */
/* Autores: Isaac Barriales & Jose A. Bravo                */
/*                                                         */
/* Esta función devuelve el número de veces que            */
/* se ha ejecutado la OB en el caso de que la              */
/* tabla se ordene correctamente.                          */
/* Se ordena mediante el algortimo mergesort               */  
/* Entrada:                                                */
/*     int* tabla: puntero a una tabla que se va a ordenar */
/*                 tabla != NULL                           */
/*     int ip: El indice del primer elemento de la tabla   */
/*                                                         */
/*     int iu: El indice del último elemento de la tabla   */
/*                                                         */
/* Salida                                                  */
/*     int obs: El Nº de veces que se ejecuta la OB        */
/*                o ERR en caso de error                   */
/***********************************************************/
int mergesort(int* tabla, int ip, int iu) {
  int med = 0;
  int obs = 0;
  int mer = 0, ret1=0, ret2=0;


  if (ip == iu) {
    return 0;
  }

  med = (iu - ip) / 2;
  ret1 = mergesort(tabla, ip, ip + med);
  if (ret1 == ERR) {
    return ERR;
  }
  obs += ret1;

  ret2 = mergesort(tabla, ip + med + 1, iu);
  if (ret2 == ERR) {
    return ERR;
  }
  obs += ret2;

  mer = merge(tabla, ip, iu, med);

  if (ERR == mer) {
    return ERR;
  }
  obs += mer;
  
  return obs;
}


/***********************************************************/
/* Funcion: Merge                       Fecha: 02/11/2020  */
/* Autores: Isaac Barriales & Jose A. Bravo                */
/*                                                         */
/* Esta función devuelve el número de veces que            */
/* se ha ejecutado la OB en el caso de que la              */
/* tabla se ordene correctamente.                          */  
/* Entrada:                                                */
/*     int* tabla: puntero a una tabla que se va a ordenar */
/*                 tabla != NULL                           */
/*     int ip: El indice del primer elemento de la tabla   */
/*                                                         */
/*     int iu: El indice del último elemento de la tabla   */
/*     int imedio: El indice del elemento medio de la tabla*/
/*                                                         */
/* Salida                                                  */
/*     int obs: El Nº de veces que se ejecuta la OB        */
/*                o ERR en caso de error                   */
/***********************************************************/
int merge(int* tabla, int ip, int iu, int imedio) {
  int * aux;
  int i,j,k;
  int obs=0;

  aux = (int *) malloc((iu - ip +1)*sizeof(int));
  if (aux == NULL) 
    return ERR;


  for (i=ip, j=ip +imedio +1, k=0; i<= ip +imedio && j<= iu; k++, obs++) {
    if (tabla[i] < tabla[j]) {
      aux[k] = tabla[i];
      i++;
    }
    else {
      aux[k] = tabla[j];
      j++;
    }
  }

  for (; j<= iu; j++, k++) 
    aux[k] = tabla[j];

  for (; i<= ip+imedio; i++, k++)
    aux[k] = tabla[i];

  copy(tabla, aux, ip, iu);
  free(aux);

  return obs;
}



/***********************************************************/
/* Funcion: copy                      Fecha: 02/11/2020    */
/* Autores: Isaac Barriales & Jose A. Bravo                */
/*                                                         */
/* Esta función copia en la tabla 'tabla' los elementos    */
/* de la tabla aux en sus respectivos índices              */
/*                                                         */  
/* Entrada:                                                */
/*     int* tabla: puntero a una tabla que se va a ordenar */
/*                 tabla != NULL                           */
/*     int ip: El indice del primer elemento de la tabla   */
/*                                                         */
/*     int iu: El indice del último elemento de la tabla   */
/*     int* aux: puntero a una tabla auxiliar ordenada     */
/***********************************************************/
void copy(int * tabla, int * aux, int ip, int iu) {
  int i = 0;

  for(i=0; i <= iu-ip; i++) {
    tabla[ip + i] = aux[i];
  }

  return;
}


/*CABECERA*/
int quicksort(int* tabla, int ip, int iu) {
  int m=0;
  int ob1=0, ob2=0, ob3=0;

  if (ip == iu) 
    return 0;
  
  ob1 = partir(tabla, ip, iu, &m); 
  if (ob1 == ERR)
    return ERR;

  if (ip < m-1){
    ob2 = quicksort(tabla, ip, m-1);
    if (ob2 == ERR)
      return ERR;
  }

  if (m+1 < iu){
    ob3 = quicksort(tabla, m+1, iu);
    if (ob3 == ERR)
      return ERR;
  }
  
  return ob1+ob2+ob3;
}

/*CABECERA*/
int quicksort_src(int* tabla, int ip, int iu) {
  int m;
  int ob1 = 0, ob2 = 0;

  while (ip < iu) {
    ob1 += partir(tabla, ip, iu, &m);
    if (ob1 == ERR)
      return ERR;
    
    if (ip < m-1){
      ob2 += quicksort_src(tabla, ip, m-1);
      if (ob2 == ERR)
        return ERR;
    }

    if (m+1 < iu)
      ip = m + 1;
  }

  return ob1 + ob2;
}


/*CABECERA*/
int partir(int* tabla, int ip, int iu, int* pos) {
  int i, k;
  int obs;

  if ( ERR == medio(tabla, ip, iu, pos) )
    return ERR;
  k = tabla[*pos];

  swap(&tabla[ip], &tabla[*pos]);

  for (i=ip +1, obs = 0; i <= iu; i++, obs++) {
    if (tabla[i] < k) {
      (*pos)++;
      swap(&tabla[i], &tabla[*pos]);
    }
  }

  swap(&tabla[ip], &tabla[*pos]);

  return obs;
}


/*CABECERA*/
int medio(int* tabla, int ip, int iu, int *pos) {

  *pos = ip;
  
  return 0;
}


