#include <stdio.h>
#include <string.h>

typedef struct person {
    char name[10];
    float marks;
    int age;
}person;

int main()
{
    person people[4];
    person me;
    {
        strcpy(me.name, "Arka");
        me.age = 22;
        me.marks = 90.55f;
        people[0] = me;

        strcpy(me.name, "Ditu");
        me.age = 26;
        me.marks = 80.55f;
        people[1] = me;

        strcpy(me.name, "Dad");
        me.age = 52;
        me.marks = 70.55f;
        people[2] = me;

        strcpy(me.name, "Mom");
        me.age = 42;
        me.marks = 85.55f;
        people[3] = me;
    }
    ///////////////////////////////////////////////
    
    // FILE* fp = fopen("binary_text.bin", "wb");
    FILE* fp = fopen("binary_text.bin", "rb");
    // fwrite(&people, sizeof(person), 4, fp);

    person peopleAgain[4];
    fread(&peopleAgain, sizeof(person), 4, fp);
    for(int i=0;i<4;i++) {
        printf("%s\n", peopleAgain[i].name);
        printf("%f\n", peopleAgain[i].marks);
        printf("%d\n", peopleAgain[i].age);
    }


    fclose(fp);
}