#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* openFile(FILE* file, char* filename, char* mode)
{
    file = NULL;
    file = fopen(filename, mode);

    return file;
}

int* alloc(int col, int row)
{
    int *list;
    list = malloc((int)(col*row)*sizeof(int*));

    return list;
}

int input(FILE* file, int* list, int row, int col)
{
    for ( int i = 0; i < row*col; i++)
    {
        fscanf(file, "%d", &list[i]);
    }

    return 0;
}

int output(FILE* fileOut, int* list, int row, int col)
{
    for( int i = 0; i < col; i++ )
    {
        for ( int j = 0; j < row; j++ )
        {
            fprintf(fileOut, "%d ", list[i+(j*col)]);
        }
        fprintf(fileOut, "\n");
    }

    return 0;
}

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        return 1;
    }

    int row;
    int col;

    FILE* file;
    file = openFile(file, argv[1], "r");

    if ( file == NULL )
    {
        fprintf(stderr, "Chybi cesta k vstupnimu a vystupnimu souboru.\n");

        return 1;
    }

    FILE* fileOut;
    fileOut = openFile(file, argv[2], "w");

    if ( fileOut == NULL )
    {
        fprintf(stderr, "Chybi cesta k vstupnimu a vystupnimu souboru.\n");

        return 1;
    }

    fscanf(file, "%d", &row);
    fscanf(file, "%d", &col);

    int *list = alloc(col, row);

    input(file, list, row, col);

    output(fileOut, list, row, col);

    free(list);

    fclose(file);

    fclose(fileOut);

    return 0;
}