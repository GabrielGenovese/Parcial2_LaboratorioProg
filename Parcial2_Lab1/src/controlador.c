#include "controlador.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "controlador.h"
#include "Libro.h"
#include "LinkedList.h"
#include "parser.h"
#include "menus.h"
#include "validaciones_utn.h"



/** \brief Carga los datos de los empleados desde el path (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */


int controlador_cargaDeDatos(char* path , LinkedList* libros)
{
    int retorno = -1;
    FILE* pFile;
    int opcionesListaUsada;

    if(path != NULL && libros != NULL)
    {
    	if(ll_isEmpty(libros))
    	{
			pFile = fopen(path,"r");
			if(pFile != NULL)
			{
				if(!parser_libroDelTexto(pFile,libros))
				{
					printf("LOS DATOS SE CARGARON CORRECTAMENTE");
					retorno = 0;
				}
				else
				{
					printf("No se pudieron cargar los datos");
				}
				fclose(pFile);
			}
			else
			{
				printf("No se pudo abrir el archivo.");
			}
		}
    	else
    	{
    		menuListaUsada(&opcionesListaUsada,"Opcion: ");
    		do{
				switch(opcionesListaUsada)
				{
				case 1:
					ll_clear(libros);
					break;
				case 2:
					controlador_GuardarDatos("backup.csv",libros);
					ll_clear(libros);
					break;
				case 3:
					break;
				default:
					printf("opcion Invalida");
					break;
				}
    		}while(opcionesListaUsada > 3 || opcionesListaUsada < 1);
    	}
    }

    return retorno;
}


/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controlador_ListarLibros(LinkedList* libros)
{
    int retorno = -1;
    int lenList;
    eLibro* employeeAux;

    if(libros != NULL)
    {
    	if(!ll_isEmpty(libros))
    	{
			lenList = ll_len(libros);
			imprimirTutilo();
			for(int i = 0; i < lenList; i++)
			{
				employeeAux = ll_get(libros,i);
				imprimirLibro(employeeAux);
			}
    	}
    	else
    	{
    		printf("No hay empleados que listar\n");
    	}

    	retorno = 0;
    }

    return retorno;
}


/** \brief Ordenar Libros
 *
 * \param Libros LinkedList*
 * \return int
 *
 */


int controlador_OrdenarLibros(LinkedList* libros)
{
	int retorno = -1;

	if(libros!= NULL)
	{
		if(!ll_isEmpty(libros))
		{
			if(!ll_sort(libros,ordenPorAutor,1))
			{
				printf("Datos cargados correctamente.");
			}
		}
		else
		{
			printf("No hay empleados que Ordenar.");
		}
	}

	return retorno;
}

/*brief Aplica descuentos
 * param Libros LinkedList
 * return int 0 si no hubo errores -1 si hubo alguno
 * */
int controlador_AplicaDescuentos(LinkedList* libros)
{
	int retorno = -1;
	LinkedList* Aux = NULL;


	if(libros != NULL)
	{
		if(!ll_isEmpty(libros))
		{
			Aux = ll_map(libros,DescuentosSegunIdEditorial);
			if (Aux != NULL )
			{
				libros = Aux;
				retorno = 0;
				printf("Descuentos aplicados Correctamente");
			}
			else
			{
				printf("Error aux null");
			}
		}
		else
		{
			printf("No se pueden aplicar descuentos en una lista vacia.");
		}
	}

	return retorno;
};


/** \brief Guarda los datos de los empleados en el path (modo texto).
 *
 * \param path char*
 * \param libro LinkedList*
 * \return int
 *
 */
int controlador_GuardarDatos(char* path, LinkedList* libros)
{
	int retorno = -1;
	FILE* pFile;
	int id;
	float precio;
	int idEditorial;
	char autor[128];
	char titulo[128];
	char editorial[128];
	eLibro * LibroActual;

	if(path != NULL && libros != NULL)
	{
		if(!ll_isEmpty(libros))
		{
			pFile = fopen(path,"w");

			if(pFile != NULL)
			{
				fprintf(pFile,"ID,TITULO,AUTOR,PRECIO,EDITORIAL\n");

				for(int i = 0; i < ll_len(libros); i++)
				{
					LibroActual = ll_get(libros,i);
					if(LibroActual != NULL)
					{
						id = libro_getId(LibroActual);
						libro_getTitulo(LibroActual,titulo);
						libro_getAutor(LibroActual,autor);
						precio = libro_getPrecio(LibroActual);
						idEditorial = libro_getEditorialId(LibroActual);
						descripcionEditorialSegunId(idEditorial,editorial);

						fprintf(pFile,"%d,%s,%s,%.0f,%s\n",id,titulo,autor,precio,editorial);
					}
				}
				printf("Se guardaron los datos exitosamente en %s",path);
				fclose(pFile);
			}
			else
			{
				printf("No se pudo abrir %s",path);
			}
		}
		else
		{
			printf("No hay nada que imprimir");
		}
	}

    return retorno;
}
