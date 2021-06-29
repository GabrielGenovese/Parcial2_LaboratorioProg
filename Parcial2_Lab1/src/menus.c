#include <stdio.h>
#include "validaciones_UTN.h"


/*brief menu principal del programa, devuelve la respuesta del usuario por referencia
 * param1 opcElegida int*
 * param2 mensaje char*
 * return retorna 0 si no hubo problemas y -1 si hubo algun error.
 * */
int menu(int* opcElegida, char mensaje[])
{
	int retorno = -1;

	if(opcElegida != NULL && mensaje != NULL)
	{
		printf("\n\n							MENU								\n");
		printf("1. Carga de datos.\n");
		printf("2. Ordenar.\n");
		printf("3. Imprimir todos los datos.\n");
		printf("4. Aplicar descuentos.\n");
		printf("5. Guardar los datos en archivo.\n");
		printf("6. Salir\n");
		validacionNumeroEntero(opcElegida,mensaje);

		retorno = 0;
	}

	return retorno;
}

int menuListaUsada(int* opcElegida, char mensaje[])
{
	int retorno = -1;
	if(opcElegida != NULL && mensaje != NULL)
	{
		printf("1. Borrar Lista.\n");
		printf("2. Guardar Lista en backUp y Borrar.\n");
		printf("3. Salir.\n");
		validacionNumeroEntero(opcElegida,mensaje);

		retorno = 0;
	}
	return retorno;
}
