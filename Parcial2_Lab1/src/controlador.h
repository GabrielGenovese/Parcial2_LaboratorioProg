#include "LinkedList.h"

/*brief Hace la carga de datos de un archivo pasado por parametros
 * param1 path char*
 * param2 libros LinkedList*
 * return retorna 0  si no hubo problemas y -1 si hubo algun problema
 * */
int controlador_cargaDeDatos(char* path , LinkedList* libros);


/*brief Controla el Listado de todos los libros de la linkedlist pasada por parametros.
 * param1 libros LinkedList*
 * return retorna 0  si no hubo problemas y -1 si hubo algun problema
 * */
int controlador_ListarLibros(LinkedList* libros);


/*brief Controla el ordenamientro de la LinkedList pasada por parametros.
 * param1 libros LinkedList*.
 * return retorna 0  si no hubo problemas y -1 si hubo algun problema.
 * */
int controlador_OrdenarLibros(LinkedList* libros);


/*brief Controla La aplicacion de los descuentos en los libros de la LinkedList pasada por parametros
 * param1 libros LinkedList*.
 * return retorna 0  si no hubo problemas y -1 si hubo algun problema.
 * */
int controlador_AplicaDescuentos(LinkedList* libros);


/*brief Controla el guardado de datos de la LinkedList en un archivo con el path pasado por parametros
 * param1 path char*
 * param2 libros LinkedList*
 * return retorna 0  si no hubo problemas y -1 si hubo algun problema
 * */
int controlador_GuardarDatos(char* path , LinkedList* libros);



