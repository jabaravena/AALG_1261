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

/***************************************************/
/* Funcion: tiempo_medio_ordenacion Fecha:         */
/*                                                 */
/* Vuestra documentacion (formato igual            */
/* que en el primer apartado):                     */
/***************************************************/
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

    /*Guardamos en una tabla los obs*/
    tabla[j] = obs;
  }

  t2 = clock();

  tiempo_total = (double)(t2-t1);
  ptiempo->tiempo = tiempo_total/n_perms;

  /*La variable medio/n_perms va a tener el numero promedio de veces que se ejecuta la OB*/
  ptiempo->medio_ob = medio/n_perms;

  

  ptiempo->max_ob = max;
  ptiempo->min_ob = min;

  return OK;
}

/***************************************************/
/* Funcion: genera_tiempos_ordenacion Fecha:       */
/*                                                 */
/* Vuestra documentacion                           */
/***************************************************/
short genera_tiempos_ordenacion(pfunc_ordena metodo, char* fichero, 
                                int num_min, int num_max, 
                                int incr, int n_perms)
{
  PTIEMPO tiempos;
  int num=0;
  int i, j;

  /*¿control de errores?? por si incr es 0 o si num_max es menor que num_min???*/
  num = ((num_max - num_min)/incr) +1;

  tiempos = malloc(num * sizeof(TIEMPO));
  if(!tiempos) {
    return ERR;
  }

  for(j=num_min, i=0; j <= num_max; j+=incr, i++) {
    if(tiempo_medio_ordenacion(metodo, n_perms, j, tiempos+i) == ERR) {
      free(tiempos);
      return ERR;
    }
  }

  if(guarda_tabla_tiempos(fichero, tiempos, num)==ERR) {
    free(tiempos);
    return ERR;
  }

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

  fp = open(fichero, "w");
  if(!fp) {
    return ERR;
  }

  for(j=0; j<n_tiempos; j++) {
    fprintf(fp, "%d %d %d %d %d\n", tiempo[j].N, tiempo[j].tiempo, tiempo[j].medio_ob, tiempo[j].max_ob, tiempo[j].min_ob);
  }

  fclose(fp);

  return OK;
}


