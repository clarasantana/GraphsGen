#include <stdio.h>
#include "loadingjsonfile.h"
#include "plotgraph.h"
#include "drawgraph.h"

int main(int argc, char *argv[]){
	if (argc != 2)
	{
		printf ("Erro!\n");
	}	
	show_graph(argv[1]);
	
	return 0;
}