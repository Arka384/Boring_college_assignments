#include <stdio.h>
#include <string.h>

void countStr(char *, int *, int *);
/*
Bengali, or Bangla, is an Indo-Aryan language spoken
predominantly in Bangladesh and in the Indian states of West Bengal and Tripura by
approximately 200 million people. The language has a rich literary heritage and
underwent a renaissance in the late 19th century
*/
int main()
{
    char str[500], c;
    int i=0;
    int nArticle = 0, nCapWords = 0;

    printf("Enter the string(put # at end): ");
    while(1){
        scanf("%c", &c);
        if(c == '#') {
            str[i++] = ' ';
            str[i] = '\0';
            break;
        }
        str[i++] = c;
    }

    puts(str);
    countStr(str, &nArticle, &nCapWords);
    printf("\nNumber of words starting with Caps is: %d", nCapWords);
    printf("\nNumber of articles is: %d", nArticle);

}

void countStr(char *str, int *article, int *capWords) {
    int i=0, j=i, k=0;
    char word[20] = {' '};
    //counting the number of Cap words
    while(str[i] != '\0') {
        if(str[i] == ' ' || str[i] == '\0'){

            //found one word
            word[k] = '\0';
            k=0;
            
            //checking if the word is an atricel
            if(strcmp(word, "a") == 0 || strcmp(word, "an") == 0 || strcmp(word, "the") == 0 ||
                strcmp(word, "A") == 0 || strcmp(word, "An") == 0 || strcmp(word, "The") == 0 )
                *article = *article + 1;

            //checking if word starts with Caps
            if(str[j] >= 65 && str[j] <= 90)
                *capWords = *capWords + 1;
            j = i + 1;
        }
        else
            word[k++] = str[i];
        i++;
    }

}