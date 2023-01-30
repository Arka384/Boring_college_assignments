#include <stdio.h>
#include <string.h>

typedef struct Library
{
    int accessionNumber;
    char title[30];
    char authorName[30];
    int price;
    int issued; //0 or 1
}Library;

int G_arrIndex = 0;
void addBook(Library *);
void displayBook(Library *, int );
void displayAllBooks(Library *);
void booksOfGivenAuthor(Library *, char *);
void bookWithAccNum(Library *, int );
void sortBooks(Library *);

int main()
{
    Library library[10];
    char authorName[30];
    int accNum, choice;

    while(1)
    {
        printf("\n1 -> Add book information");
        printf("\n2 -> Display book information");
        printf("\n3 -> List all books of given author");
        printf("\n4 -> List the title of specified book");
        printf("\n4 -> List the title of specified book");
        printf("\n5 -> List the count of books in the library");
        printf("\n6 -> List the books in the order of accession number");
        printf("\n7 -> Exit");
        printf("\nEnter you choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addBook(library);
            break;
        case 2:
            displayAllBooks(library);
            break;
        case 3:
            printf("\nEnter author name for finding: ");
            fflush(stdin);
            gets(authorName);
            booksOfGivenAuthor(library, authorName);
            break;
        case 4:
            printf("\nEnter accession number of the book to find: ");
            scanf("%d", &accNum);
            bookWithAccNum(library, accNum);
            break;
        case 5:
            printf("\nNumber of books in library is: %d", G_arrIndex-1);
            break;
        case 6:
            sortBooks(library);
            displayAllBooks(library);
            break;
        case 7:
            return 0;
        default:
            break;
        }
    }

    return 0;
}

void sortBooks(Library *lib)
{
    int i,j;
	for(i=0;i<G_arrIndex-1;i++) {
		for(j=i;j<G_arrIndex-i-1;j++) {
			if((lib + j)->accessionNumber > (lib + j + 1)->accessionNumber) {
				Library t = *(lib+j);
				*(lib+j) = *(lib+j+1);
				*(lib+j+1) = t;
			}
		}
	}
}

void bookWithAccNum(Library *lib, int accNum)
{
    int i=0, flag = 0;
    for(i=0;i<G_arrIndex;i++) {
        if((lib+i)->accessionNumber == accNum) {
            displayBook(lib, i);
            flag = 1;
        } 
    }
    if(flag == 0)
        printf("\nNo records found");
}

void booksOfGivenAuthor(Library *lib, char *author)
{
    int i=0, flag = 0;
    for(i=0;i<G_arrIndex;i++) {
        if(strcmp((lib+i)->authorName, author) == 0) {
            displayBook(lib, i);
            flag = 1;
        }
    }
    if(flag == 0)
        printf("\nNo records found");
}

void addBook(Library *lib) 
{
    Library temp;
    printf("\nEnter book information: \n");
    printf("\nEnter accession number: ");
    scanf("%d", &temp.accessionNumber);
    printf("\nEnter book title: ");
    fflush(stdin);
    gets(temp.title);
    printf("\nEnter author name: ");
    gets(temp.authorName);
    printf("\nEnter price: ");
    scanf("%d", &temp.price);
    temp.issued = 0;
    *(lib + G_arrIndex) = temp;
    G_arrIndex++;
}

void displayBook(Library *lib, int index) {
    printf("\nAccession number: %d", (lib + index)->accessionNumber);
    printf("\nBook title: ");
    fputs((lib + index)->title, stdout);
    printf("\nAuthor name: ");
    fputs((lib + index)->authorName, stdout);
    printf("\nPrice: %d", (lib + index)->price);
    if((lib + index)->issued == 1)
        printf("\nStatus: issued");
    else
        printf("\nStatus: NOT issued");
    printf("\n");
}

void displayAllBooks(Library *lib)
{
    if(G_arrIndex == 0) {
        printf("\nNo records");
        return;
    }
    
    int i=0;
    printf("\n=========================================");
    for(i=0;i<G_arrIndex;i++) {
        printf("\nAccession number: %d", (lib + i)->accessionNumber);
        printf("\nBook title: ");
        fputs((lib + i)->title, stdout);
        printf("\nAuthor name: ");
        fputs((lib + i)->authorName, stdout);
        printf("\nPrice: %d", (lib + i)->price);
        if((lib + i)->issued == 1)
            printf("\nStatus: issued");
        else
            printf("\nStatus: NOT issued");
        printf("\n");
    }
    printf("\n=========================================\n");
}