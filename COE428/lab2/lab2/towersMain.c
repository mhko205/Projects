#include <stdlib.h>
#include "towers.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    int n = 3;
    int from = 1;
    int dest = 2;
    int check;
    if (argc == 2) {
		n = atoi(argv[1]);
	}  else if (argc == 4){
		n = atoi(argv[1]);
		from = atoi(argv[2]);
		check = atoi(argv[3]);
		if (check != from){
			dest = check;
		}
		else{
			fprintf(stderr, "invalid input");
			exit(0);
		}
	}
	towers (n, from, dest);
    exit(0);
}

