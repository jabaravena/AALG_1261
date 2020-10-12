/**
 *
 * Descripcion: Implementacion de funciones de tiempo
 *
 * Fichero: tiempos.c
 * Autor: Carlos Aguirre Maeso
 * Version: 1.0
 * Fecha: 16-09-2017
 *
 */

#include "tiempos.h"
#include "ordenacion.h"
#include "permutaciones.h"
#include <stdio.h>
#include <stdlib.h>

/***************************************************************/
/* Funcion: tiempo_medio_ordenacion       Fecha: 06/10/20      */
/* Autores: Isaac Barriales & José A. Bravo                    */
/*                                                             */
/* Función que ordena n_perms permutaciones de                 */
/*    tamaño N mediante el método de ordenacion                */
/*    pfunc_ordena metodo. Guarda los parámetros temporales    */
/*    en un puntero de tipo TIEMPO.                            */
/*                                                             */
/* Entrada:                                                    */
/*  pfunc_ordena metodo: Puntero a una rutina que implementa   */
/*                       un algoritmo de ordenación.           */
/*                       metodo != NULL                        */
/*  int n_perms: número de permutaciones a generar             */
/*               n_perms > 0                                   */
/*  int N: número de elementos de cada permutación             */
/*         N > 0                                               */
/*  PTIEMPO tiempo: puntero a una estructura de tipo TIEMPO    */
/*                  que será modificada con los parámetros     */
/*                  temporales resultantes de la ordenación    */
/*                                                             */
/* Salida:                                                     */
/*  short: OK si se han ordenado correctamente las             */
/*         permutaciones y no ha habido ningún error.          */
/*         ERR si ha habido algún error.                       */ 
/***************************************************************/
short tiempo_medio_ordenacion(pfunc_ordena metodo, 
                              int n_perms,
                              int N, 
                              PTIEMPO ptiempo)
{
  int ** perms;
  int i, j, obs;
  double tiempo_total, medio;
  int min = __INT_MAX__, max = 0;

  time_t t1, t2;


  /*Rellenamos los primeros campos de la estructura*/
  ptiempo->N = N;
  ptiempo->n_elems = n_perms;

  perms = genera_permutaciones(n_perms, N);
  if(!perms) {
    return ERR;
  }


  t1 = clock();

  for(j=0, obs=0, medio=0; j<n_perms; j++) {
    obs = metodo(perms[j], 0, N-1);
    if(obs == ERR) {   
      for(i=0; i<n_perms; i++) {
        free(perms[i]);
      }
      free(perms);
      return ERR;
    }

    /*Calcular maximo y minimo*/
    if(max < obs) {
      max = obs;
    }
    if(min > obs) {
      min = obs;
    }

    /*Calcular el promedio*/
    medio += (double)obs;

  }

  t2 = clock();

  tiempo_total = (double)(t2-t1);
  ptiempo->tiempo = tiempo_total/n_perms/CLOCKS_PER_SEC;

  /*La variable medio/n_perms va a tener el numero promedio de veces que se ejecuta la OB*/
  ptiempo->medio_ob = medio/n_perms;

  

  ptiempo->max_ob = max;
  ptiempo->min_ob = min;


  for(i=0; i<n_perms; i++) {
        free(perms[i]);
  }
  free(perms);

  return OK;
}

/***************************************************************/
/* Funcion: Genera_tiempos_ordenacion       Fecha: 06/10/20    */
/* Autores: Isaac Barriales & José A. Bravo                    */
/*                                                             */
/* Función que escribe en el fichero fichero los tiempos       */
/* medios, y los números promedio, mı́nimo y máximo de veces    */
/* que se ejecuta la OB en la ejecución del algoritmo de       */
/* ordenación metodo con n_perms permutaciones de tamaños      */
/* en el rango desde num_min hasta num_max, ambos incluidos,   */
/* usando incrementos de tamaño incr.                          */
/*                                                             */
/* Entrada:                                                    */
/*  pfunc_ordena metodo: Puntero a una rutina que implementa   */
/*                       un algoritmo de ordenación.           */
/*                       metodo != NULL                        */
/*  char* fichero: String con el nombre del fichero de         */
/*                   salida. Este fichero contendrá una tabla  */
/*                   con los tiempos de ejecución.             */
/*  int n_perms: número de permutaciones a generar             */
/*               n_perms > 0                                   */
/*  int N: número de elementos de cada permutación             */
/*         N > 0                                               */
/*  PTIEMPO tiempo: puntero a una estructura de tipo TIEMPO    */
/*                  que será modificada con los parámetros     */
/*                  temporales resultantes de la ordenación    */
/*                                                             */
/* Salida:                                                     */
/*  short: OK si se han ordenado correctamente las             */
/*         permutaciones y no ha habido ningún error.          */
/*         ERR si ha habido algún error.                       */ 
/***************************************************************/
short genera_tiempos_ordenacion(pfunc_ordena metodo, char* fichero, 
                                int num_min, int num_max, 
                                int incr, int n_perms)
{
  PTIEMPO tiempos;
  int num=0;
  int i, j;

  num = ((num_max - num_min)/incr) +1;

  tiempos = malloc(num * sizeof(TIEMPO));
  if(!tiempos) {
    return ERR;
  }

  for(j=num_min, i=0; i<num; j+=incr, i++) {
    if(tiempo_medio_ordenacion(metodo, n_perms, j, tiempos+i) == ERR) {
      free(tiempos);
      return ERR;
    }
    /*Para imprimir por terminal como va avanzando en los calculos...*/
    fprintf(stdout, "%d %f %f %d %d\n", tiempos[i].N, tiempos[i].tiempo, tiempos[i].medio_ob, tiempos[i].min_ob, tiempos[i].max_ob);

  }

  if(guarda_tabla_tiempos(fichero, tiempos, num)==ERR) {
    free(tiempos);
    return ERR;
  }

  free(tiempos);

  return OK;
  
}

/***************************************************/
/* Funcion: guarda_tabla_tiempos Fecha:            */
/*                                                 */
/* Vuestra documentacion (formato igual            */
/* que en el primer apartado):                     */
/***************************************************/
short guarda_tabla_tiempos(char* fichero, PTIEMPO tiempo, int n_tiempos)
{
  FILE * fp;
  int j;

  fp = fopen(fichero, "w");
  if(!fp) {
    return ERR;
  }

  for(j=0; j<n_tiempos; j++) {
    fprintf(fp, "%d %f %f %d %d\n", tiempo[j].N, tiempo[j].tiempo, tiempo[j].medio_ob, tiempo[j].min_ob, tiempo[j].max_ob);
  }

  fclose(fp);

  return OK;
}


