/**
 *
 * Descripcion: Implementacion de funciones de generacion de permutaciones
 *
 * Fichero: permutaciones.c
 * Autor: Carlos Aguirre
 * Version: 1.0
 * Fecha: 16-09-2017
 *
 */


#include "permutaciones.h"
#include <stdlib.h>

/***************************************************/
/* Funcion: aleat_num Fecha:27/09/2020             */
/* Autores: Isaac Barriales Y Jose Antonio Bravo   */
/*                                                 */
/* Rutina que genera un numero aleatorio           */
/* entre dos numeros dados                         */
/*                                                 */
/* Entrada:                                        */
/* int inf: limite inferior                        */
/* int sup: limite superior                        */
/*                                                 */
/* limite inferior siempre mayor que 0             */
/* limite superior siempre mayor que 0             */
/*                                                 */
/* Salida:                                         */
/* int: numero aleatorio                           */
/***************************************************/
int aleat_num(int inf, int sup)
{

  int aleatBig = 0, aleat2 = 0, aleatFinal = 0;


  aleatBig = rand();

  aleat2 = aleatBig % (sup - inf + 1);
  aleatFinal = aleat2 + inf;

  return aleatFinal;

}

/***************************************************/
/* Funcion: swap Fecha: 04/10/2020                 */
/* Autores: Isaac Barriales Y Jose Antonio Bravo   */
/*                                                 */
/* Función que inetercambia el contenido           */
/* de dos punteros integer                         */
/*                                                 */
/* Entrada:                                        */
/* int a: Dirección del número a cambiar           */
/* int b: Dirección del número a cambiar           */
/***************************************************/
void swap(int* a, int *b){
  int aux = *a;
  *a = *b;
  *b = aux;
}

/***************************************************/
/* Funcion: genera_perm Fecha: 27/09/2020          */
/* Autores: Isaac Barriales Y Jose Antonio Bravo   */
/*                                                 */
/* Rutina que genera una permutacion               */
/* aleatoria                                       */
/*                                                 */
/* Entrada:                                        */
/* int n: Numero de elementos de la                */
/* permutacion                                     */
/* Salida:                                         */
/* int *: puntero a un array de enteros            */
/* que contiene a la permutacion                   */
/* o NULL en caso de error                         */
/***************************************************/
int* genera_perm(int N)
{
  int * perm;
  int i=0;


  perm = (int *) malloc (N* sizeof(perm[0]));

  if(perm == NULL){
    return NULL;
  }
  
  for(i=0;i<N;i++){
    perm[i] = i+1;
  }

  for(i=0;i<N;i++){
    swap(&perm[i],&perm[aleat_num(i, N -1)]);
  }

  return perm;

}

/***************************************************/
/* Funcion: genera_permutaciones Fecha:            */
/* Autores:                                        */
/*                                                 */
/* Funcion que genera n_perms permutaciones        */
/* aleatorias de tamanio elementos                 */
/*                                                 */
/* Entrada:                                        */
/* int n_perms: Numero de permutaciones            */
/* int N: Numero de elementos de cada              */
/* permutacion                                     */
/* Salida:                                         */
/* int**: Array de punteros a enteros              */
/* que apuntan a cada una de las                   */
/* permutaciones                                   */
/* NULL en caso de error                           */
/***************************************************/
int** genera_permutaciones(int n_perms, int N)
{



}
