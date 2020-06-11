#include <stdio.h>

int main(int args, char *argv[]){

    FILE *input, *output; 
    char *key; 
    int aux; 
    key = argv[1]; 

    //Check arguments ammount
    if(args < 4)
        printf("More arguments need to be provided!");
    else{
        //Attempts to open the input file
        printf("Trying to open the file \"%s\"...\n",argv[2]);
        input = fopen(argv[2], "rb");
        if(input == NULL)
            printf("Cannot open the file \"%s\"",argv[2]);
        else{

            //Attempts to open output file
            output = fopen(argv[3], "wb");
            if(output == NULL)
                printf("Cannot open the file \"%s\"",argv[3]);
            else{

                //Starts encryption
                printf("Encrypting \"%s\" to \"%s\"\n",argv[2],argv[3]);
                while ( (aux = getc(input)) != EOF)
                {
                    if(!*key)
                        key = argv[1];
                    aux ^= *(key++);
                    putc(aux, output);
                }
                fclose(output);
                printf("Success!\n");
            }
            fclose(input);
        }
    }
    return 1;
}