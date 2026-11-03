#include <stdio.h>

int main(void) {
  printf("hello\n");

  int num1, num2;

  printf("Enter the 1st number: ");
  scanf("%d", &num1);
  printf("Enter the 2nd number: ");
  scanf("%d", &num2);

  if(num1 > num2){
      printf("1st number is biggest");
  }else{
      printf("2nd number is biggest");
  };
  return 0;
}
