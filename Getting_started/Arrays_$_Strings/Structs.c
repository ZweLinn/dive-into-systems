// Arrays and structs are the two ways in which C supports creating collections
// of data elements. Structs are used to create a collection of data elements of
// different types.
#include <stdio.h>
#include <string.h>

int main(void) {
  printf("hello\n");

  struct Student {
    char name[64];
    int age;
    float gpa;
    int grad_yr;
  };

  struct Student student1;

  printf("student name is %s\n" , strcpy(student1.name, "Kwame Salter"));
  printf("student name is %d\n" , student1.age = 22);
  printf("student name is %f\n" , student1.gpa = 3.5);
  printf("student name is %d\n" , student1.grad_yr = 2023);

  return 0;
}
