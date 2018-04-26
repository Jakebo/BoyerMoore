#include <stdio.h>
#include "boyermoore.h"

int main(int argc, char **argv)
{
    int index;

    if (argc != 3) {
        printf("Usage: ./strfind <long str> <find str>\n\n");
        return -1;
    }

    index = strfind(argv[1], argv[2]);
    printf("%s found at %d\n", argv[2], index);
}

