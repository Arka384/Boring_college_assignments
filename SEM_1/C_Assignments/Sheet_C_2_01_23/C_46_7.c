#include <stdio.h>
#include <ctype.h>

int main()
{
    char c;
    FILE *in = fopen("C_46_7_input.txt", "r");
    FILE *out = fopen("C_46_7_output.txt", "w");

    while(1) {
        fflush(stdin);
        c = fgetc(in);
        if(c == EOF)
            break;
        fputc(toupper(c), out);
    }

    printf("\nAll characters of input file have been changed to upper case in output file");
    fclose(in);
    fclose(out);
    return 0;
}