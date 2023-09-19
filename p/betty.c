#include "shell.h"


int main() {
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    while (1) {
        /* Display the prompt*/
        printf("Your Shell> ");

        /*Read user input using getline8*/
        nread = getline(&line, &len, stdin);

        /*Check for errors*/
        if (nread == -1) {
            perror("getline");
            break;
        }

        /*Process the user input (execute the command)*/
        /*You can add code here to parse and execute the command*/

        /*Free the memory allocated by getline*/
        free(line);
        line = NULL; /*Reset the line pointer for the next iteration*/
    }

    return 0;
}
