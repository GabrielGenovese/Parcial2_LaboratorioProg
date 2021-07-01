#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

typedef struct
{
    int id;
    char titulo[128];
    char autor[128];
    float precio;
    int editorialID;
}eLibro;

/*brief Crea una estructura eLibro inicializado en '0' o ' ' en memoria dinamica y devuelve un puntero a ella.
 * return eLibro*.
 * */
eLibro* libro_nuevo();


/*brief crea una estructura eLibro en memoria dinamica y le asigna los valores pasados por parametro y devuelve un
puntero a ella.
 * param1 idStr char*.
 * param2 titulo char*.
 * param3 autor char*.
 * param4 precioStr char*.
 * param5 idEditorial char*
 * return eLibro*.
 * */
eLibro* libro_nuevoParametros(char* idStr,char* titulo,char* autor,char* precioStr,char* idEditorial);


/*brief Le asigna el id pasado por parametros a una estructura eLibro* pasada por referencia
 * param1 this eLibro*
 * param2 id int
 * return retorna 0 si funciono correctamente o -1 si hubo algun problema.
 * */
int libro_setId(eLibro* this,int id);


/*brief Devuelve por referencia el id de la estructura eLibro pasado por parametros
 * param1 this eLibro*
 * param2 id int*
 * return retorna 0 si funciono correctamente o -1 si hubo algun problema.
 * */
int libro_getId(eLibro* this);


/*brief Le asigna el titulo pasado por parametros a una estructura eLibro* pasada por referencia
 * param1 this eLibro*
 * param2 titulo char*
 * return retorna 0 si funciono correctamente o -1 si hubo algun problema.
 * */
int libro_setTitulo(eLibro* this,char* titulo);


/*brief Devuelve por referencia el titulo eLibro de la estructura eLibro pasado por parametros
 * param1 this eLibro*
 * param2 titulo char*
 * return retorna 0 si funciono correctamente o -1 si hubo algun problema.
 * */
int libro_getTitulo(eLibro* this,char* titulo);


/*brief Le asigna el autor pasado por parametros a una estructura eLibro* pasada por referencia
 * param1 this eLibro*
 * param2 titulo char*
 * return retorna 0 si funciono correctamente o -1 si hubo algun problema.
 * */
int libro_setAutor(eLibro* this,char* autor);


/*brief Devuelve por referencia el titulo eLibro de la estructura eLibro pasado por parametros
 * param1 this eLibro*
 * param2 titulo char*
 * return retorna 0 si funciono correctamente o -1 si hubo algun problema.
 * */
int libro_getAutor(eLibro* this,char* autor);


/*brief Le asigna el precio pasado por parametros a una estructura eLibro* pasada por referencia
 * param1 this eLibro*
 * param2 precio int
 * return retorna 0 si funciono correctamente o -1 si hubo algun problema.
 * */
int libro_setPrecio(eLibro* this,float precio);


/*brief Devuelve por referencia el precio de la estructura eLibro pasado por parametros
 * param1 this eLibro*
 * param2 precio int*
 * return retorna 0 si funciono correctamente o -1 si hubo algun problema.
 * */
float libro_getPrecio(eLibro* this);


/*brief Le asigna el idEditorial pasado por parametros a una estructura eLibro* pasada por referencia
 * param1 this eLibro*
 * param2 sueldo int
 * return retorna 0 si funciono correctamente o -1 si hubo algun problema.
 * */
int libro_setEditorialId(eLibro* this,int idEditorial);


/*brief Devuelve por referencia el idEditorial de la estructura eLibro pasado por parametros
 * param1 this eLibro*
 * param2 sueldo int*
 * return retorna 0 si funciono correctamente o -1 si hubo algun problema.
 * */
int libro_getEditorialId(eLibro* this);


/*brief Hace la validacion de datos para el alta de un nuevo eLibro.
 * param1 titulo char*.
 * param2 autor char*.
 * param3 editorial char*.
 * param4 precio char*
 * return retorna 0 si funciono correctamente o -1 si hubo algun problema.
 * */
int libro_entradaDeDatos(char *titulo,char *autor, char *editorial, char *precio);


/*brief Imprime Todos los datos de la estructura Employee pasada por parametros
 * param1 empleado Employee*
 * return retorna 0 si funciono correctamente o -1 si hubo algun problema.
 * */
int imprimirLibro(eLibro *Libro);


/*brief imprime la cabecera de los datos de un eLibro
 * */
void imprimirTutilo();


/*brief decide cual de los 2 Libros pasados por parametros es mayor o menor dependiendo del autor
 * param1 Libro1 void*
 * param2 Libro2 void*
 * return retorna 1 si Libro1 > Libro2,| retorna -1 si Libro1 < Libro2 y retorna 0 si son iguales
 * */
int ordenPorAutor(void* libro1,void* libro2);

/*brief Aplica los descuentos dependiendo del precio y la descripcion de la editorial
 * param1 elemento de la estructura.
 * */
void DescuentosSegunIdEditorial(void* elemento);

/*brief devuelve la descripcion de una editorial por referencia segun el ID pasado por parametros.
 * param1 ID int.
 * param2 editorial char*
 * return retorna 0 si no hubo problemas, y -1 si hubo algun problema
 * */
int descripcionEditorialSegunId(int id,char* editorial);

#endif // employee_H_INCLUDED
