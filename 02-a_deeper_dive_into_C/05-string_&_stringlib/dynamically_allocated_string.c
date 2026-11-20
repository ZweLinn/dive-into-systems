// When dynamically allocating space to store a string, it’s important to
// remember to allocate space in the array for the terminating '\0' character at
// the end of the string.

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // include the C string library

#include <stdio.h>

int main(void) {
  int size;
  char str[64];             // statically allocated
  char *dynamic_str = NULL; // dynamically allocated

  strcpy(str, "hello world");
  size = strlen(str);

  dynamic_str = malloc(sizeof(char) * (size + 1)); // need space for \0

  if (dynamic_str == NULL) {
    printf("ERROR: malloc failed!\n");
    exit(1);
  }

  strcpy(dynamic_str, str);
  printf("dynamically allocated string is %s\n", dynamic_str);

  strcat(str, ", I'm learnin C");
  printf("After concantenate %s\n", str);

  free(dynamic_str);
  dynamic_str = NULL;
  return 0;
}
