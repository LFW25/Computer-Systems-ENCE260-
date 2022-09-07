# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <stdbool.h>
# include <string.h>

typedef struct {
    char* name;
    int age;
    double height;
} Person_t;

Person_t* newPerson(char* name, int age, double height)
{
    Person_t* person = calloc(1, sizeof(Person_t));
    char* newName = calloc(strlen(name)+1, sizeof(char));
    strncpy(newName, name, strlen(name));
    person->name = newName;
    person->age = age;
    person->height = height;

    return person;

}

void freePerson(Person_t* person)
{
    free(person->name);
    free(person);
}

int main(void)
{
    Person_t* employee = newPerson("Billy", 30, 1.68);
    printf("%s is age %d and is %.2f m tall\n", employee->name, employee->age, employee->height);
    freePerson(employee);
    /* Billy is age 30 and is 1.68 m tall */
}