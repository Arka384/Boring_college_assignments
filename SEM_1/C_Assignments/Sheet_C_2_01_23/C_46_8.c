#include <stdio.h>

int main()
{
    char buff[100];
    FILE *in = fopen("C_46_8_input.txt", "r");
    FILE *out = fopen("C_46_8_output.txt", "w");

    while(fgets(buff, 100, in) != NULL) {
        fputs(buff, out);
    }
    printf("\nData of input file has been copied to output file");
    fclose(in);
    fclose(out);
    return 0;
}