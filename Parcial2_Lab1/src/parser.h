#ifndef PARSER_H_
#define PARSER_H_

/*brief Parsea los datos los datos de los Libro desde el archivo pasado por parametros y los agrega a la LinkedList.
 *param1 pFile FILE*
 *param2 libros LinkedList*
 *return retorna 0 si no hubo ningun problema y -1 si hubo alguno.
 **/
int parser_libroDelTexto(FILE* pFile , LinkedList* libros);


/*brief Compara Las descripciones tomada por parametros y devuelve el id correspondiente (en char) por referencia
 * param1 descripcion char*
 * param2 idEditorialStr char*
 * return retorna 0 si hubo coincidencia con las descripciones, y retorna -1 su hubo algun problema o no hubo coincidencia
 * */
char IdEditorialSegunDescripcion(char* descripcion, char* idEditorialStr);

#endif /* PARSER_H_ */
