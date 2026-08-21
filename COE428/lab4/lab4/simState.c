#include <stdio.h>
#include <string.h>

typedef struct{
    char name;
    char next0;
    char next1;
    int visited;
    int deleted;
} State;

State states[8];
char current = 'F';

int indexOf(char c){
    return c - 'A';
}

void initFSM(){

    states[0]=(State){'A','H','F',0,0};
    states[1]=(State){'B','D','C',0,0};
    states[2]=(State){'C','C','E',0,0};
    states[3]=(State){'D','B','H',0,0};
    states[4]=(State){'E','A','G',0,0};
    states[5]=(State){'F','G','D',0,0};
    states[6]=(State){'G','A','B',0,0};
    states[7]=(State){'H','C','F',0,0};

}

void findReachable(){

    for(int i=0;i<8;i++)
        states[i].visited = 0;

    states[current-'A'].visited = 1;

    int changed = 1;

    while(changed){

        changed = 0;

        for(int i=0;i<8;i++){

            if(states[i].visited && !states[i].deleted){

                int a = states[i].next0 - 'A';
				int b = states[i].next1 - 'A';

				if(a >= 0 && a < 8 && !states[a].deleted){
					if(!states[a].visited){
						states[a].visited = 1;
						changed = 1;
					}
				}

				if(b >= 0 && b < 8 && !states[b].deleted){
					if(!states[b].visited){
						states[b].visited = 1;
						changed = 1;
					}
				}

            }

        }

    }
}

void printFSM(){

    for(int i=0;i<8;i++){

        if(!states[i].deleted){

            printf("%c %c %c\n",
                   states[i].name,
                   states[i].next0,
                   states[i].next1);
        }
    }
}

void garbage(){

    findReachable();

    int found = 0;

    for(int i=0;i<8;i++){

        if(!states[i].visited && !states[i].deleted)
            found = 1;
    }

    if(!found){
        printf("No garbage\n");
        return;
    }

    printf("Garbage:");

    for(int i=0;i<8;i++){

        if(!states[i].visited && !states[i].deleted)
            printf(" %c",states[i].name);
    }

    printf("\n");
}

void deleteUnreachable(){

    findReachable();

    int found = 0;

    printf("Deleted:");

    for(int i=0;i<8;i++){

        if(!states[i].visited && !states[i].deleted){

            states[i].deleted = 1;
            printf(" %c",states[i].name);
            found = 1;
        }
    }

    if(!found)
        printf("\nNo states deleted.\n");
    else
        printf("\n");
}

void deleteState(char s){

    findReachable();

    int i = indexOf(s);

    if(!states[i].visited && !states[i].deleted){

        states[i].deleted = 1;
        printf("Deleted.\n");

    }else{

        printf("Not deleted.\n");

    }
}

int main(){

    initFSM();

    printf("%c\n",current);

    char line[100];

    while(fgets(line,100,stdin)){

        if(line[0]=='0'){

            current = states[current-'A'].next0;
            printf("%c\n",current);

        }

        else if(line[0]=='1'){

            current = states[current-'A'].next1;
            printf("%c\n",current);

        }

        else if(line[0]=='p'){

            printFSM();

        }

        else if(line[0]=='g'){

            garbage();

        }

        else if(line[0]=='d'){

            if(strlen(line)<=2){

                deleteUnreachable();

            }else{

                char s;
                sscanf(line,"d %c",&s);
                deleteState(s);
            }
        }

        else if(line[0]=='c'){

            char bit,state;

            sscanf(line,"c %c %c",&bit,&state);

            if(states[state-'A'].deleted)
                continue;

            if(bit=='0')
                states[current-'A'].next0 = state;
            else
                states[current-'A'].next1 = state;
        }

    }

    return 0;
}
