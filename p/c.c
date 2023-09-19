#include "shell.h"

int main() {
    char str[] = "apple,banana,kiwi";
    char *delimiter = ",";

    char *token = strtok(str, delimiter);
    while (token != NULL) {
        printf("Token: %s\n", token);
        token = strtok(NULL, delimiter);
    }
   token = _strtok(str, delimiter);
    while (token != NULL) {
        printf("Token: %s\n", token);
        token = _strtok(NULL, delimiter);
    }
    return 0;
}
