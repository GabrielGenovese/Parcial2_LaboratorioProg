#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Libro.h"


int IdEditorialSegunDescripcion(char *descripcion,char* idEditorialStr)
{
	int retorno = -1;
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
				retorno = 0;
				break;
			}
		}
		itoa(ID,idEditorialStr,10);
	}
	return retorno;
}


int parser_libroDelTexto(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	char buffer[5][128];
	int cantidadDatosLeidos;
	eLibro* LibroLeido;
	char idEditorial[128];

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);

		while(!feof(pFile))
		{
			cantidadDatosLeidos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);

			if(cantidadDatosLeidos == 5)
			{
				IdEditorialSegunDescripcion(buffer[4],idEditorial);
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
