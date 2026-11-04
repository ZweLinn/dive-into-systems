// C arrays can store multiple data values of the same type

#include <stdio.h>

int main(void) {
  printf("hello\n");

  int i, size = 0;

  // declare array of 10 int
  int my_arr[10];

  for (i = 0; i < 10; i++) {
    my_arr[i] = i;
    size++;
  }
  // set value at position 3 to 100
  my_arr[3] = 100;
  printf("array of %d items:\n", size);

  for (i = 0; i < 10; i++) {
    printf("%d\n", my_arr[i]);
  }

  int array1[10];   // an array of size 10 has valid indices 0 through 9

  printf("value of 9 index is %d\n" , array1[9]);
  printf("value of 10 index is %d\n" , array1[10]);

  int ind10 =array1[10] = 100;  // 10 is not a valid index into the array
  printf("value is %d\n" , ind10);

  // C မှာ ဒီလို ရေးရင် compiler error မပေးတာမျိုး များပါတယ်။
  // ဒါပေမဲ့ undefined behavior ဖြစ်ပါတယ်။ Program က crash ဖြစ်နိုင်ပါတယ်၊
  // တခြား variable ရဲ့ တန်ဖိုးကို မသိမသာ ပျက်စီးစေနိုင်ပါတယ်၊
  // တခါတလေ ပုံမှန် အလုပ်လုပ်သလိုလည်း ထင်ရနိုင်ပါတယ်။ အဲဒါကြောင့် bug ရှာရတာ ခက်ပါတယ်။
  return 0;
}
