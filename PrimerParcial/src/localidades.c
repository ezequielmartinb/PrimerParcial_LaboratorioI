#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "localidades.h"

int imprimirLocalidades(Localidad* localidades, int len)
{
	int retorno=-1;

	if(localidades!=NULL && len>0)
	{
		retorno=0;
		for(int i=0;i<len;i++)
		{
			printf("%-5d %-15s\n", localidades[i].idLocalidades, localidades[i].localidades);
		}
	}

	return retorno;
}
