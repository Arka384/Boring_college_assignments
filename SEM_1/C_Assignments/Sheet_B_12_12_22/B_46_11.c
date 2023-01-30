#include <stdio.h>
#include <string.h>
#include <malloc.h>

void sortNames(char **countryNames, int n) {
    int i,j;
    for(i=0;i<n;i++)
        for(j=i;j<n;j++)
            if(strcmp(countryNames[i], countryNames[j]) > 0) {
                char *temp = countryNames[i];
                countryNames[i] = countryNames[j];
                countryNames[j] = temp;
            }
}

int main()
{
    int n, i, nameSize = 20;
    char **countryNames;
    printf("\nEnter number of country names: ");
    scanf("%d", &n);
    countryNames = (char** )malloc(sizeof(char* )*n);

    printf("\nEnter country names: \n");
    for(i=0;i<n;i++) {
        countryNames[i] = (char* )malloc(sizeof(char )*nameSize);
        fflush(stdin);
        gets(countryNames[i]);
    }

    sortNames(countryNames, n);

    printf("\nCountry names after sorting are :\n");
    for(i=0;i<n;i++) {
        puts(countryNames[i]);
    }

}