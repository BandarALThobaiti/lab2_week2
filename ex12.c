#include <stdio.h>
#include <stdlib.h>

struct student{
    int id;
    char name;
    int age;


};

int main(){
    // void *ptr =malloc(8);
    // char *str = (char *) ptr;
    // short *num = (short *)ptr;
    // int *arr = (int*)ptr;
    // long *longarr = (long *) ptr'

    void *ptr = malloc (sizeof(struct student));
    struct student *sptr = (struct student*)ptr;
    sptr ->id = 0x44aaff11;
    sptr ->name = 'A';
    sptr->age = 0x667788dd;

    FILE *fh = fopen("student.std" , "wb");
    if(fh != NULL){
    fwrite(ptr, sizeof(struct student), 1 , fh);
    fclose(fh);

    }

    free(ptr);



     fh = fopen("student.std" , "rb");
    if(fh != NULL){
        fread(ptr, sizeof(struct student), 1 , fh);
        fclose(fh);


        printf("ID: %x\n", sptr->id);
        printf("Name: %c\n", sptr->name);
        printf("Age: %x\n", sptr->age);
    }

    free(ptr);

    return 0;
}
