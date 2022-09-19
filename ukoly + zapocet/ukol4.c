#include<stdio.h>
#include<stdlib.h>

int main(){
    int s = 100;
    char *inputString = NULL;

    inputString = malloc(s*sizeof(char)+1);
    fgets(inputString, (s*sizeof(char)+1), stdin);
    for(int i = 0, j; inputString[i] != '\0'; i++){
        while (!(inputString[i] >= 'a' && inputString[i] <= 'z') && !(inputString[i] >= 'A' && inputString[i] <= 'Z') && !(inputString[i] == '\0')) {
            for(j = i; inputString[j] != '\0'; j++){
                inputString[j] = inputString[j+1];
            }
            inputString[j] = '\0';
        }
    }
    
    printf("%s", inputString);
    free(inputString);
   
    return 0;

}