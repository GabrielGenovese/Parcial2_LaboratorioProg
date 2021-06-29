#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Libro.h"


char IdEditorialSegunDescripcion(char * descripcion)
{
	char retorno;
	char editoriales [6][30] = {
			{"PLANETA"},
			{"SIGLO XXI EDITORES"},
			{"PEARSON"},
			{"MINOTAURO"},
			{"SALAMANDRA"},
			{"PENGUIN BOOKS"}
	};
	int ID;
	char auxiliar[30];

	if(descripcion != NULL)
	{
		strcpy(auxiliar,descripcion);
		for(int i = 0; i < 6; i++)
		{
			strupr(auxiliar);
			if(!strcmp(auxiliar,*(editoriales+i)))
			{
				ID = i+1;
				break;
			}
		}
		itoa(ID,&retorno,10);
	}
	return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_libroDelTexto(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	char buffer[5][128];
	int cantidadDatosLeidos;
	eLibro* LibroLeido;
	char idEditorial;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);

		while(!feof(pFile))
		{
			cantidadDatosLeidos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);

			if(cantidadDatosLeidos == 5)
			{
				idEditorial = IdEditorialSegunDescripcion(buffer[4]);
				LibroLeido = libro_nuevoParametros(buffer[0],buffer[1],buffer[2],buffer[3],idEditorial);
				ll_add(pArrayListEmployee,LibroLeido);
				retorno = 0;
			}
			else
			{
				printf("No Se han podido leer todos los Datos del Archivo");
				break;
			}
		}


	}

    return retorno;
}
