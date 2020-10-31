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



/*CABECERA*/
int mergesort(int* tabla, int ip, int iu) {
  int med = 0;
  int obs = 0;
  int mer = 0, ret1=0, ret2=0;

  /*No pongo el primer CdE del pscodigo pq lo diré en la cabecera*/
  /*No pongo CdE para tabla pq nunca debe ser NULL, tampoco si en
  combinar fallara la reserva de memoria*/

  if(ip == iu) {
    return 0;
  }

  med = (iu - ip) / 2;
  ret1 = mergesort(tabla, ip, med);
  if(ret1 == ERR) {
    return ERR;
  }
  obs += ret1;

  ret2 = mergesort(tabla, med + 1, iu);
  if(ret2 == ERR) {
    return ERR;
  }
  obs += ret2;

  mer = merge(tabla, ip, iu, med);

  if(ERR == mer) {
    return ERR;
  }
  obs += mer;
  
  return obs;
}


/*CABECERA*/
int merge(int* tabla, int ip, int iu, int imedio) {
  int * aux;
  int i,j,k;
  int obs=0;

  aux = malloc(iu - ip +1);
  if(!aux) {
    return ERR;
    /*Yo creo que tendré que devolver -1 pq ERR no es int, right??*/
  }


  for(i=ip, j=imedio+1, k=0; i<= imedio && j<= iu; k++, obs++) {
    if(tabla[i] < tabla[j]) {
      aux[k] = tabla[i];
      i++;
    }
    else {
      aux[k] = tabla[j];
      j++;
    }
  }

  /*Pasa a aux los restantes elementos de la tabla*/
  /*Si la segunda mitad se agotó no entra en el for*/
  for(; j<= iu; j++, k++) 
    aux[k] = tabla[j];

  /*Si la primera mitad se agotó los elementos, no entra*/
  for(; i<= imedio; i++, k++)
    aux[k] = tabla[i];

  copy(tabla, aux, ip, iu);
  free(aux);

  return obs;
}


/*Cabecera*/
void copy(int * tabla, int * aux, int ip, int iu) {
  int i = 0;

  for(i=0; i <= iu-ip; i++) {
    tabla[ip + i] = aux[i];
  }

  return;
}