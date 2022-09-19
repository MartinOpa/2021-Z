#include<stdio.h>
#include<stdlib.h>

int* alloc(int n){
    int *list;
    list = malloc((int)(n)*sizeof(int*));

    return list;
}

int input(int* list, int n){
    for(int i = 0; i < n; i++){
        scanf("%d", &list[i]);
    }

    return 0;
}

int print(int* list, int n){
    printf("%d \n", n);
    for(int i = 0; i < n; i++){
        if(list[i] % 2 == 0)
            printf("%d even \n", list[i]);
        else
            printf("%d odd \n", list[i]);
    }

    return 0;
}

int main(){
    int n;
    scanf("%d", &n);

    int *list = alloc(n);

    input(list, n);
    
    print(list, n);
    
    free(list);

    return 0;
}