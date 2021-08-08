#include <stdio.h>

/* define the person struct here using the typedef syntax */
    typedef struct {
        char *name;
        int *age;
    } person;
int main() {

    person john;
    /* testing code */
    john.name = "John";
    int age = 27;
    john.age = &age;
    printf("%s is %d years old.", john.name, *john.age);
}