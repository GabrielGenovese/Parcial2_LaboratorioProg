#include "Libro.h"

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "validaciones_UTN.h"



int libro_setId(eLibro* this,int id)
{
	int retorno = -1;
	if(this != NULL && id > -1)
	{
		(*this).id = id;
		retorno = 0;
	}
	return retorno;
}


int libro_getId(eLibro* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		retorno = (*this).id;
	}
	return retorno;
}


int libro_setTitulo(eLibro* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		strcpy((*this).titulo,nombre);
		retorno = 0;
	}
	return retorno;
}


int libro_getTitulo(eLibro* this,char* autor)
{
	int retorno = -1;
	if(this != NULL && autor != NULL)
	{
		strcpy(autor,(*this).titulo);
		retorno = 0;
	}
	return retorno;
}


int libro_setAutor(eLibro* this,char* autor)
{
	int retorno = -1;
	if(this != NULL && autor != NULL)
	{
		strcpy((*this).autor,autor);
		retorno = 0;
	}
	return retorno;
}


int libro_getAutor(eLibro* this,char* autor)
{
	int retorno = -1;
	if(this != NULL && autor != NULL)
	{
		strcpy(autor,(*this).autor);
		retorno = 0;
	}
	return retorno;
}


int libro_setPrecio(eLibro* this,float horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas > -1)
	{
		(*this).precio = horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}


float libro_getPrecio(eLibro* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		retorno = (*this).precio;
	}
	return retorno;
}


int libro_setEditorialId(eLibro* this,int idEditorial)
{
	int retorno = -1;
	if(this != NULL && idEditorial > -1)
	{
		(*this).editorialID = idEditorial;
		retorno = 0;
	}
	return retorno;
}

int libro_getEditorialId(eLibro* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		retorno =(*this).editorialID;
	}
	return retorno;
}


eLibro* libro_nuevo()
{
	eLibro* retorno = NULL;
	eLibro* newEmployee = NULL;

	newEmployee = (eLibro*)malloc(sizeof(eLibro));

	if (newEmployee != NULL)
	{
		libro_setId(newEmployee,0);
		libro_setTitulo(newEmployee," ");
		libro_setPrecio(newEmployee,0);
		libro_setEditorialId(newEmployee,0);

		retorno = newEmployee;
	}

	return retorno;
}


eLibro* libro_nuevoParametros(char* idStr,char* titulo,char* autor,char* precioStr,char* idEditorialStr)
{
	eLibro* retorno = NULL;
	eLibro* nuevoLibro = NULL;
	int id;
	float precio;
	int idEditorial;



	if( idStr != NULL && titulo != NULL && precioStr != NULL && idEditorialStr != NULL  && autor != NULL)
	{
		nuevoLibro = libro_nuevo();

		if(nuevoLibro != NULL )
		{
			id = atoi(idStr);
			precio = atof(precioStr);
			idEditorial = atoi(idEditorialStr);

			libro_setId(nuevoLibro,id);
			libro_setTitulo(nuevoLibro,titulo);
			libro_setAutor(nuevoLibro,autor);
			libro_setPrecio(nuevoLibro,precio);
			libro_setEditorialId(nuevoLibro,idEditorial);

			retorno = nuevoLibro;
		}
	}
	return retorno;
}

int libro_entradaDeDatos(char *titulo,char *autor, char *editorial, char *precio)
{
	int retorno = -1;
	char dataEmployee[4][128];
	int count = 0;

	if(titulo != NULL && autor != NULL && precio != NULL)
	{
		count +=validacionStringAlphaConEspacios(*(dataEmployee+0),"Ingrese el Titulo del Libro: ",128);
		count +=validacionStringAlphaSinEspacios(*(dataEmployee+1),"Ingrese el Autor del Libro: ",128);
		count +=validacionStringAlphaSinEspacios(*(dataEmployee+2),"Ingrese la Editorial del Libro: ",128);
		count +=validacionStringNumerico(*(dataEmployee+3),"Ingrese e Precio del Libro: ",128);
		if(!count)
		{
			strcpy(titulo,*(dataEmployee));
			strcpy(autor,*(dataEmployee+1));
			strcpy(editorial,*(dataEmployee+2));
			strcpy(precio,*(dataEmployee+3));
		}
	}
	return retorno;
}

void imprimirTutilo()
{
	printf("%10s|","ID");
	printf("%50s|","Titulo");
	printf("%30s|","Autor");
	printf("%20s|","Precio");
	printf("%20s|\n","Editorial");
}

int descripcionEditorialSegunId(int id, char* descripcion)
{
	int retorno = -1;
	if(id > -1 && descripcion != NULL)
	{
		switch(id)
		{
		case 1:
			strcpy(descripcion,"PLANETA");
			break;
		case 2:
			strcpy(descripcion,"SIGLO XXI EDITORES");
			break;
		case 3:
			strcpy(descripcion,"PEARSON");
			break;
		case 4:
			strcpy(descripcion,"MINOTAURO");
			break;
		case 5:
			strcpy(descripcion,"SALAMANDRA");
			break;
		case 6:
			strcpy(descripcion,"PENGUIN BOOKS");
			break;
		}
		retorno = 0;
	}
	return retorno;
}

int imprimirLibro(eLibro *libro)
{
	int retorno = 1;
	char Autor[128];
	char titulo[128];
	char editorial[20];

	if(libro != NULL)
	{

		libro_getTitulo(libro,titulo);
		libro_getAutor(libro,Autor);
		descripcionEditorialSegunId(libro_getEditorialId(libro),editorial);

		printf("%10d|",libro_getId(libro));
		printf("%50s|",titulo);
		printf("%30s|",Autor);
		printf("%20.2f|",libro_getPrecio(libro));
		printf("%20s|\n",editorial);

		retorno = 0;
	}

	return retorno;
}


int ordenPorAutor(void* libro1,void* libro2)
{
	int retorno = 0;
	char nombreEmp1[128];
	char nombreEmp2[128];

	if(libro1 != NULL && libro2 != NULL )
	{

		libro_getAutor(libro1,nombreEmp1);
		libro_getAutor(libro2,nombreEmp2);
		retorno = strcmp(nombreEmp1,nombreEmp2);
	}

	return retorno;
}


void DescuentosSegunIdEditorial(void* elemento)
{
	float precio;

	if(elemento != NULL)
	{
		precio = libro_getPrecio(elemento);
		switch(libro_getEditorialId(elemento))
		{
		case 1:
			if(precio > 299)
			{
				precio -= (precio * 0.20);
				libro_setPrecio(elemento,precio);
			}
			break;
		case 2:
			if(precio < 201)
			{
				precio -= (precio * 0.10);
				libro_setPrecio(elemento,precio);
			}
			break;
		}
	}
}
