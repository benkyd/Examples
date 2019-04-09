#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* exec(char* command) {
    char* result = malloc(128 * sizeof(char));
    char buffer[128];
    FILE* pipe = popen(command, "r");
    for(int i = 0; fgets(buffer, sizeof buffer, pipe) != NULL; i++) {
        printf("%s", buffer);
        result = realloc(result, i * 128 * sizeof(char));
        memcpy(result + (i * 128 * sizeof(char)), buffer, sizeof(buffer) * sizeof(char));


        //result = realloc(result, i * 128 * sizeof(char));
        //memcpy(result + i * 128 * sizeof(char), buffer, sizeof(buffer));
    }
    pclose(pipe);
    return result;
}

int main() {
    printf("%s", exec("dir"));
}
