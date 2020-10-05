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
  int * tabla;
  int i, j, obs;
  double tiempo_total, medio;
  int min, max;

  time_t t1, t2;

  //¿control de errores verdad?
  if(n_perms <= 0) {
    return ERR;
  }

  //Rellenamos los primeros campos de la estructura
  ptiempo->N = N;
  ptiempo->n_elems = n_perms;

  perms = genera_permutaciones(n_perms, N);
  if(!perms) {
    return ERR;
  }

  tabla = (int *)malloc(n_perms * sizeof(*tabla));
  if(!tabla) {
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

    //Calcular el promedio
    medio += (obs/n_perms);

    //Guardamos en una tabla los obs
    tabla[j] = obs;
  }

  t2 = clock();

  tiempo_total = t2-t1;
  ptiempo->tiempo = tiempo_total / n_perms;

  //La variable sumas va a tener el numero promedio de veces que se ejecuta la OB
  ptiempo->medio_ob = medio;

  //Calculamos el maximo y minimo de las obs obtenidas
  for(i=1, max=perms[0], min=perms[0]; i<n_perms; i++) {
    if(max < perms[i]) {
      max = perms[i];
    }
    if(min > perms[i]) {
      min = perms[i];
    }
  }

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
  /* vuestro codigo */
}

/***************************************************/
/* Funcion: guarda_tabla_tiempos Fecha:            */
/*                                                 */
/* Vuestra documentacion (formato igual            */
/* que en el primer apartado):                     */
/***************************************************/
short guarda_tabla_tiempos(char* fichero, PTIEMPO tiempo, int n_tiempos)
{
  /* vuestro codigo */
}


