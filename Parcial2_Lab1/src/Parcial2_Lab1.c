#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "controlador.h"
#include "LinkedList.h"
#include "validaciones_UTN.h"

int main(void) {

	setbuf(stdout,NULL);

	LinkedList *Libros;
	int opcion;
	char path[30];
	int flagDescuentos = 0;

	Libros = ll_newLinkedList();

	do
	{
		menu(&opcion,"Opcion: ");
		switch(opcion)
		{
		case 1:
			validacionStringAlphaConEspacios(path,"Ingrese el nombre del archivo (Datos.csv): ",30);
			controlador_cargaDeDatos(path,Libros);
			break;
		case 2:
			controlador_OrdenarLibros(Libros);
			break;
		case 3:
			controlador_ListarLibros(Libros);
			break;
		case 4:
			if(!flagDescuentos)
			{
				controlador_AplicaDescuentos(Libros);
				flagDescuentos = 1;
			}
			else
			{
				printf("Los descuentos ya han sido aplicados");
			}
			break;
		case 5:
			controlador_GuardarDatos("prueba.csv",Libros);
			break;
		case 6:
			break;
		}
	}while(opcion != 6);

	ll_deleteLinkedList(Libros);

	return EXIT_SUCCESS;
}
