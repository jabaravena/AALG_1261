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
/* Salida:                                         */
/* int: numero aleatorio                           */
/***************************************************/
int aleat_num(int inf, int sup)
{
  /**rand ---> numero entre 0 y 100000000 = aleatBig
  aleatBig % (sup - inf + 1) ----> numeros aleatorios entre 0 y (sup - inf)      = aleat2

  aleatFinal = aleat2 + inf ---> entre inf y sup**/

  int aleatBig = 0, aleat2 = 0, aleatFinal = 0;

  if(inf > sup || inf < 0 || sup < 0){
    return -1;
  }

  aleatBig = rand();

  aleat2 = aleatBig % (sup - inf + 1);
  aleatFinal = aleat2 + inf;

  return aleatFinal;

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
  int aux = 0, aleat;

  perm = calloc(sizeof(int), N);

  if(perm == NULL){
    return NULL;
  }
  
  for(i=0;i<N;i++){
    perm[i] = i+1;
  }

  for(i=0;i<N;i++){
    aux = perm[i];
    aleat = aleat_num(i, N-1);
    perm[i] = perm[aleat];
    perm[aleat] = aux;
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
