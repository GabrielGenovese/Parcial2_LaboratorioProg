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

/*brief Crea una estructura Employee inicializado en '0' o ' ' en memoria dinamica y devuelve un puntero a ella.
 * return Employee*.
 * */
eLibro* libro_nuevo();


/*brief crea una estructura Employee en memoria dinamica y le asigna los valores pasados por parametro y devuelve un
puntero a ella.
 * param1 idStr char*.
 * param2 nombreStr char*.
 * param3 horasTrabajadas char*.
 * param4 sueldoStr char*.
 * return Employee*.
 * */
eLibro* libro_nuevoParametros(char* idStr,char* titulo,char* autor,char* precioStr,char idEditorial);


/*brief Le asigna el id pasado por parametros a una estructura Employee* pasada por referencia
 * param1 this Employee*
 * param2 id int
 * return retorna 0 si funciono correctamente o -1 si hubo algun problema.
 * */
int libro_setId(eLibro* this,int id);


/*brief Devuelve por referencia el id de la estructura Employee pasado por parametros
 * param1 this Employee*
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


/*brief Devuelve por referencia el Nombre de la estructura Employee pasado por parametros
 * param1 this Employee*
 * param2 nombre char*
 * return retorna 0 si funciono correctamente o -1 si hubo algun problema.
 * */
int libro_getTitulo(eLibro* this,char* titulo);


int libro_setAutor(eLibro* this,char* autor);
int libro_getAutor(eLibro* this,char* autor);


/*brief Le asigna Las horas trabajadas pasadas por parametros a una estructura Employee* pasada por referencia
 * param1 this Employee*
 * param2 horasTrabajadas int
 * return retorna 0 si funciono correctamente o -1 si hubo algun problema.
 * */
int libro_setPrecio(eLibro* this,float precio);


/*brief Devuelve por referencia las horas trabajadas de la estructura Employee pasado por parametros
 * param1 this Employee*
 * param2 horasTrabajadas int*
 * return retorna 0 si funciono correctamente o -1 si hubo algun problema.
 * */
float libro_getPrecio(eLibro* this);


/*brief Le asigna el sueldo por parametros a una estructura Employee* pasada por referencia
 * param1 this Employee*
 * param2 sueldo int
 * return retorna 0 si funciono correctamente o -1 si hubo algun problema.
 * */
int libro_setEditorialId(eLibro* this,int idEditorial);


/*brief Devuelve por referencia el sueldo de la estructura Employee pasado por parametros
 * param1 this Employee*
 * param2 sueldo int*
 * return retorna 0 si funciono correctamente o -1 si hubo algun problema.
 * */
int libro_getEditorialId(eLibro* this);


/*brief Hace la validacion de datos para el alta de un nuevo empleado.
 * param1 nombre char*.
 * param2 horasTrabajadas char*.
 * param3 sueldo char*.
 * return retorna 0 si funciono correctamente o -1 si hubo algun problema.
 * */
int libro_entradaDeDatos(char *titulo,char *autor, char *editorial, char *precio);


/*brief Imprime Todos los datos de la estructura Employee pasada por parametros
 * param1 empleado Employee*
 * return retorna 0 si funciono correctamente o -1 si hubo algun problema.
 * */
int imprimirLibro(eLibro *empleado);


/*brief imprime la cabecera de los datos de un empleado
 * */
void imprimirTutilo();


/*brief decide cual de los 2 empleados pasados por parametros es mayor o menor dependiendo del nombre
 * param1 employee1 void*
 * param2 employee2 void*
 * return retorna 1 si employee1 > employee2, retorna -1 si employee1 < employee2 y retorna 0 si son iguales
 * */
int ordenPorAutor(void* employee1,void* employee2);


void DescuentosSegunIdEditorial(void* elemento);

int descripcionEditorialSegunId(int id,char* editorial);

#endif // employee_H_INCLUDED
