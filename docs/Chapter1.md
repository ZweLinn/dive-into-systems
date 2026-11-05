# Dive Into Systems — အခန်း (၁)

## By the C, by the C, the Beautiful C — C ဘာသာစကား၏ အခြေခံ

ဒီီီ Docs ဟာ **Dive Into Systems** စာအုပ်ရဲ့ အခန်း (၁) ဖြစ်တဲ့ **"By the C, by the C, the
Beautiful C"** ကို မြန်မာလိုနဲ့ ပြန်လည်ရှင်းပြထားတဲ့ documentation ဖြစ်ပါတယ်။
C programming ကို အခုမှ စလေ့လာမယ့်သူတွေ၊ ဒါမှမဟုတ် အခြေခံကို ပြန်နွှေးချင်တဲ့သူတွေအတွက်
ရည်ရွယ်ပါတယ်။ ဥပမာ code တွေအားလုံးဟာ `Getting_started/` folder ထဲက ဖိုင်တွေကို အခြေခံထားပါတယ်။

C ဟာ ကွန်ပျူတာစနစ်တွေ (operating systems, compilers, embedded devices စသည်) နဲ့ နီးစပ်တဲ့
ဘာသာစကားဖြစ်ပြီး၊ နောက်ပိုင်း memory, pointer, hardware စတာတွေကို နားလည်ဖို့အတွက်
အခြေခံအုတ်မြစ်လည်း ဖြစ်ပါတယ်။

---

## အခန်း (၁) မှာ ဘာတွေ လေ့လာမလဲ

| အပိုင်း | ခေါင်းစဉ် | အကြောင်းအရာ |
| --- | --- | --- |
| ၁.၁ | Getting Started Programming in C | ပထမဆုံး C program, variables, types |
| ၁.၂ | Input / Output in C | `printf` နဲ့ `scanf` |
| ၁.၃ | Conditionals and Loops | `if`, `while`, `for`, booleans |
| ၁.၄ | Functions | function prototype, definition, call stack |
| ၁.၅ | Arrays and Strings | array, string, C string library |
| ၁.၆ | Structs | struct နဲ့ data collection |

---

## ၁.၁ Getting Started Programming in C

### ပထမဆုံး C program

C program တိုင်းမှာ `main` လို့ခေါ်တဲ့ function တစ်ခု မဖြစ်မနေ ရှိရပါတယ်။ Program က
စတင်အလုပ်လုပ်တဲ့အခါ အရင်ဆုံး `main` ထဲက code ကို run ပါတယ်။

```c
#include <stdio.h>

int main(void) {
  printf("hello\n");
  return 0;
}
```

**ဖွဲ့စည်းပုံကို ရှင်းပြချက်**

- `#include <stdio.h>` — Standard Input/Output library ကို ထည့်သွင်းပါတယ်။ ဒီ library ထဲမှာ
  `printf` လို function တွေ ရှိပါတယ်။
- `int main(void)` — `main` function ရဲ့ ကြေညာချက်ဖြစ်ပါတယ်။ `int` ဆိုတာ ဒီ function က
  integer တစ်ခု ပြန်ပေးမယ်လို့ ဆိုလိုပါတယ်။ `void` ဆိုတာ argument မယူဘူးလို့ ဆိုလိုပါတယ်။
- `printf("hello\n");` — screen ပေါ်မှာ `hello` ဆိုတဲ့ စာကို ရိုက်ထုတ်ပါတယ်။ `\n` ဟာ
  newline (စာကြောင်းအသစ်ဆီ ဆင်းတဲ့) character ဖြစ်ပါတယ်။
- `return 0;` — program က အောင်မြင်စွာ ပြီးဆုံးကြောင်း operating system ကို ပြန်ပြောပါတယ်။
  `0` ဆိုတာ "အဆင်ပြေပြီး" ဆိုတဲ့ အဓိပ္ပာယ်ပါ။

### Compile နဲ့ Run လုပ်နည်း

C source file (`.c`) ကို တိုက်ရိုက် run လို့ မရပါဘူး။ ပထမ **compiler** (ဥပမာ `gcc`) နဲ့
machine နားလည်တဲ့ executable file အဖြစ် ပြောင်းရပါတယ်။

```bash
gcc hello.c -o hello   # hello.c ကို compile လုပ်ပြီး hello ဆိုတဲ့ executable ထုတ်မယ်
./hello                # executable ကို run မယ်
```

Output က:

```
hello
```

### Comments (မှတ်ချက်)

Code ထဲမှာ ကိုယ့်အတွက် ဒါမှမဟုတ် တခြားသူအတွက် ရှင်းပြချက်တွေ ရေးထားချင်ရင် comment
သုံးပါတယ်။ Compiler က comment တွေကို လုံးဝ လျစ်လျူရှုပါတယ်။

```c
// ဒါက single-line comment ပါ

/*
   ဒါက multi-line comment ပါ။
   စာကြောင်းအများကြီး ရေးလို့ရပါတယ်။
*/
```

### Variables နဲ့ Types

**Variable** ဆိုတာ ဒေတာ (data) တန်ဖိုးတွေကို သိမ်းထားတဲ့ နာမည်ရှိတဲ့ နေရာတစ်ခုပါ။
Variable တစ်ခု မသုံးခင် အရင်ဆုံး **type** (အမျိုးအစား) နဲ့အတူ ကြေညာ (declare) ရပါတယ်။
Type က variable ထဲမှာ ဘာအမျိုးအစား ဒေတာ သိမ်းမယ်၊ memory ဘယ်လောက် ယူမယ်ဆိုတာကို
ဆုံးဖြတ်ပေးပါတယ်။

```c
int x;        // integer (ကိန်းပြည့်) variable တစ်ခု ကြေညာ
int i, j, k;  // variable အများကြီးကို တစ်ကြောင်းတည်းနဲ့ ကြေညာလို့ရ
char letter;  // character variable
float winpct; // floating-point (ဒဿမ) variable
double pi;    // ပိုကြီးပြီး ပိုတိကျတဲ့ floating-point variable
```

#### C ရဲ့ အခြေခံ numeric types

| Type | ပုံမှန် အရွယ် | သိမ်းတဲ့ တန်ဖိုး | ကြေညာနည်း |
| --- | --- | --- | --- |
| `char` | 1 byte | integers | `char x;` |
| `short` | 2 bytes | signed integers | `short x;` |
| `int` | 4 bytes | signed integers | `int x;` |
| `long` | 4 or 8 bytes | signed integers | `long x;` |
| `long long` | 8 bytes | signed integers | `long long x;` |
| `float` | 4 bytes | signed real numbers | `float x;` |
| `double` | 8 bytes | signed real numbers | `double x;` |

Type တစ်ခုစီ ဘယ်လောက် byte ယူလဲဆိုတာကို `sizeof` operator နဲ့ စစ်လို့ရပါတယ်။

```c
#include <stdio.h>

int main(void) {
    printf("number of bytes in an int: %lu\n", sizeof(int));
    printf("number of bytes in a short: %lu\n", sizeof(short));
    return 0;
}
```

#### Variable တွေကို တန်ဖိုးသတ်မှတ်ခြင်း

```c
x = 7;        // x ကို 7 သတ်မှတ်
k = x + 2;    // k က x + 2 ရဲ့ တန်ဖိုးဖြစ်တဲ့ 9 ဖြစ်သွား
letter = 'H'; // character တစ်လုံးကို single quote (') နဲ့ ရေး
letter = letter + 1; // char ဟာ integer ဖြစ်လို့ ဂဏန်းသချၤာလုပ်လို့ရ (H + 1 = I)
pi = 3.1415926;
```

#### Integer နဲ့ floating-point ခွဲခြင်း (Division)

ဒါက C မှာ အရမ်းအရေးကြီးတဲ့ အချက်ပါ။

```c
winpct = 11 / 2.0;  // = 5.5  (float ပါလို့ ဒဿမရလဒ်ရ)
j = 11 / 2;         // = 5    (int ချင်းစားလို့ ဒဿမကို ဖြတ်ပစ်)
x = k % 2;          // % ဟာ remainder (အကြွင်း) operator ပါ
```

- `11 / 2.0` — operand တစ်ခုမှာ `.0` (float) ပါလို့ floating-point division ဖြစ်ပြီး `5.5`
  ရပါတယ်။
- `11 / 2` — နှစ်ခုလုံး integer ဖြစ်လို့ integer division ဖြစ်ပြီး ဒဿမကို ဖြတ်ပစ်လို့ `5`
  ရပါတယ်။
- `%` — modulo operator ဖြစ်ပြီး စားလို့ ကျန်တဲ့ အကြွင်းကို ပြန်ပေးပါတယ်။

#### Increment / Decrement (`++` နဲ့ `--`)

Variable တန်ဖိုးကို ၁ တိုး (`++`) ဒါမှမဟုတ် ၁ လျှော့ (`--`) လုပ်တဲ့ operator တွေပါ။
**ရှေ့မှာထားတာ (prefix)** နဲ့ **နောက်မှာထားတာ (postfix)** ရလဒ်မတူပါဘူး။

```c
#include <stdio.h>

int main(void) {
  int x;
  int y;

  x = 6;
  y = ++x + 2;   // y = 9 : x ကို အရင်တိုး (7)၊ ပြီးမှ x + 2 = 9
  printf("x is %d\n", y);

  x = 6;
  y = x++ + 2;   // y = 8 : x + 2 = 8 ကို အရင်တွက်၊ ပြီးမှ x ကို တိုး (7)
  printf("x is %d\n", y);
  return 0;
}
```

- `++x` (prefix) — အရင် တိုး၊ ပြီးမှ တခြား expression မှာ သုံး။
- `x++` (postfix) — တခြား expression မှာ အရင်သုံး၊ ပြီးမှ တိုး။

---

## ၁.၂ Input / Output in C

### `printf` — ရိုက်ထုတ်ခြင်း

`printf` က Python ရဲ့ formatted print နဲ့ ဆင်တူပါတယ်။ Format string ထဲမှာ **format
specifier** (`%` နဲ့စတဲ့ placeholder) တွေထည့်ပြီး၊ အဲဒီနေရာမှာ ဘာတန်ဖိုး အစားထိုးမလဲဆိုတာ
နောက်မှာ argument တွေအဖြစ် ပေးရပါတယ်။

```c
#include <stdio.h>

int main(void) {
    printf("Name: %s,  Info:\n", "Vijay");
    printf("\tAge: %d \t Ht: %g\n", 20, 5.9);
    printf("\tYear: %d \t Dorm: %s\n", 3, "Alice Paul");
    return 0;
}
```

#### သုံးများတဲ့ format specifier တွေ

| Specifier | အဓိပ္ပာယ် | ဥပမာ |
| --- | --- | --- |
| `%d` | integer (int, short, char) | `printf("%d", 20);` |
| `%g` | float / double | `printf("%g", 5.9);` |
| `%f` | float / double (fixed ပုံစံ) | `printf("%f", 3.5);` |
| `%s` | string | `printf("%s", "hi");` |
| `%c` | character | `printf("%c", 'A');` |
| `%lu` | unsigned long (ဥပမာ `sizeof` ရလဒ်) | `printf("%lu", sizeof(int));` |
| `\t` | tab (ခြားနားအောင် ခွာ) | |
| `\n` | newline | |

`char` ဟာ အတွင်းမှာ integer (ASCII တန်ဖိုး) ဖြစ်တာကြောင့် `%d` နဲ့လည်း ထုတ်လို့ရပါတယ်။

```c
char ch = 'A';
printf("ch value is %d which is the ASCII value of %c\n", ch, ch);
// Output: ch value is 65 which is the ASCII value of A
```

`'A'` ရဲ့ ASCII တန်ဖိုးက `65` ဖြစ်လို့ `%d` က `65` ကိုပြပြီး၊ `%c` က `A` ကို ပြပါတယ်။

### `scanf` — အသုံးပြုသူထံမှ ဒေတာ ဖတ်ခြင်း

`scanf` က keyboard ကနေ ရိုက်ထည့်လိုက်တဲ့ တန်ဖိုးတွေကို ဖတ်ပြီး variable ထဲ သိမ်းပါတယ်။
ဒီမှာ **အရေးကြီးတဲ့ အချက်** က `&` (address-of operator) ကို သုံးရပါတယ်။ `&x` ဆိုတာ "x
ရဲ့ memory လိပ်စာ (address)" ကို ဆိုလိုပြီး၊ `scanf` က အဲဒီ memory လိပ်စာထဲကို ဖတ်လို့ရတဲ့
တန်ဖိုးကို ရေးထည့်ပေးပါတယ်။

```c
#include <stdio.h>

int main(void) {
  int num1, num2;

  printf("Enter a number: ");
  scanf("%d", &num1);

  printf("Enter a number: ");
  scanf("%d", &num2);

  printf("%d + %d = %d\n", num1, num2, (num1 + num2));

  int x;
  float pi;

  // int တစ်ခု ပြီးရင် float တစ်ခုကို "%d%g" ပုံစံနဲ့ ဖတ်
  scanf("%d%g", &x, &pi);
  printf("%d%g", x, pi);
  return 0;
}
```

> **မှတ်ချက်** — `scanf` မှာ `&` မေ့လိုက်ရင် compiler က warning ပေးတတ်ပြီး program က
> မှားတဲ့ နေရာကို ရေးမိနိုင်ပါတယ်။ ဒါကြောင့် `scanf` နဲ့ဆို `&` မပါမဖြစ် သတိရပါ။

---

## ၁.၃ Conditionals and Loops

### `if` / `else` — အခြေအနေပေါ် မူတည်ပြီး ဆုံးဖြတ်ခြင်း

```c
#include <stdio.h>

int main(void) {
  int num1, num2;

  printf("Enter the 1st number: ");
  scanf("%d", &num1);
  printf("Enter the 2nd number: ");
  scanf("%d", &num2);

  if (num1 > num2) {
      printf("1st number is biggest");
  } else {
      printf("2nd number is biggest");
  }
  return 0;
}
```

- `if (အခြေအနေ) { ... }` — အခြေအနေ မှန်ရင် block ထဲက code ကို run ပါတယ်။
- `else { ... }` — `if` အခြေအနေ မမှန်ရင် run ပါတယ်။
- အခြေအနေတွေ ဆက်တွဲချင်ရင် `else if` ကို သုံးနိုင်ပါတယ်။

#### Relational operators (နှိုင်းယှဉ်တဲ့ operator)

| Operator | အဓိပ္ပာယ် |
| --- | --- |
| `>` | ပိုကြီး |
| `<` | ပိုငယ် |
| `>=` | ကြီး သို့မဟုတ် ညီ |
| `<=` | ငယ် သို့မဟုတ် ညီ |
| `==` | ညီသလား (နှိုင်းယှဉ်) |
| `!=` | မညီဘူးလား |

#### Logical operators (အခြေအနေတွေ ပေါင်းစပ်တဲ့ operator)

| Operator | အဓိပ္ပာယ် |
| --- | --- |
| `&&` | AND — နှစ်ခုလုံး မှန်မှ မှန် |
| `\|\|` | OR — တစ်ခုမှန်ရင် မှန် |
| `!` | NOT — ပြောင်းပြန် |

### Booleans (true / false)

C မှာ မူရင်း (original) boolean type မရှိပါဘူး။ ဒါပေမဲ့ `stdbool.h` ကို include လုပ်ရင်
`bool`, `true`, `false` တွေကို သုံးလို့ရပါတယ်။

```c
#include <stdbool.h> // bool, true, false အတွက်
#include <stdio.h>

int main(void) {
  int num1 = 1, num2 = 4;

  _Bool x = num1 == num2;  // _Bool ဟာ C ရဲ့ built-in boolean type

  bool isTrue = true;
  bool isFalse = false;

  bool negativeInt = -3; // nonzero (positive ဖြစ်ဖြစ် negative ဖြစ်ဖြစ်) က true ဖြစ်

  printf("True : %d\n", isTrue);      // 1
  printf("False : %d\n", isFalse);    // 0
  printf("Negative : %d\n", negativeInt); // 1
  return 0;
}
```

**C ရဲ့ စည်းမျဉ်း** — `0` က **false**၊ `0` မဟုတ်တဲ့ ဘယ် value မဆို **true** ဖြစ်ပါတယ်။
ဒါကြောင့် `-3` ဟာ true ဖြစ်ပါတယ်။

### `while` loop — အခြေအနေ မှန်နေသရွေ့ ထပ်ခါထပ်ခါ run

```c
int val = 1;
while (val < num) {     // val < num မှန်နေသရွေ့ loop ပတ်
    val = val * 2;
    printf("val is now: %d\n", val);
}
```

`while` ဟာ အရင်ဆုံး အခြေအနေကို စစ်ပြီးမှ မှန်ရင် body ကို run ပါတယ်။ အခြေအနေ မမှန်တော့ရင်
loop ရပ်ပါတယ်။

### `for` loop — အကြိမ်အရေအတွက် သေချာတဲ့ loop

```c
int num1, i;

printf("Enter a value: ");
scanf("%d", &num1);

for (i = 0; i <= num1; i++) {
    printf("%d\n", i);
}
```

`for` loop မှာ အပိုင်း (၃) ပိုင်း ရှိပါတယ်။

1. **Initialization** — `i = 0` (loop မစခင် တစ်ကြိမ်သာ run)
2. **Condition** — `i <= num1` (မှန်မှ body ကို run)
3. **Update** — `i++` (body run ပြီးတိုင်း run)

> **သတိထားရမယ့်အချက် (gotcha)** — `loop.c` မှာ `int num, val;` လို့ ကြေညာပြီး `num` ကို
> မသတ်မှတ်ဘဲ `if (num < 0)` လို့ သုံးထားပါတယ်။ ဒါက **uninitialized variable** ဖြစ်ပြီး
> `num` ရဲ့ တန်ဖိုးက ကြိုတင်မသိနိုင်တဲ့ garbage value ဖြစ်နေပါတယ်။ Variable ကို မသုံးခင်
> တန်ဖိုး သေချာ သတ်မှတ်ပေးဖို့ အရေးကြီးပါတယ်။

---

## ၁.၄ Functions

**Function** ဆိုတာ သီးခြား အလုပ်တစ်ခုကို လုပ်ဆောင်တဲ့ code block တစ်ခုပါ။ Function တွေ
သုံးခြင်းဖြင့် code ကို ပြန်သုံးလို့ရတယ်၊ ဖတ်ရလွယ်တယ်၊ စီမံရလွယ်တယ်။

### Function ရဲ့ အပိုင်း (၂) ပိုင်း

1. **Prototype (ကြေညာချက်)** — function ရဲ့ နာမည်၊ return type နဲ့ parameter list ကိုသာ
   ကြေညာပါတယ်။ Body မပါပါဘူး။ `main` ထဲမှာ function ကို အပြည့်အစုံ မရေးခင် ခေါ်ချင်တဲ့အခါ
   သုံးပါတယ်။
2. **Definition (အဓိပ္ပာယ်ဖွင့်ဆိုချက်)** — function ရဲ့ body (လုပ်ဆောင်ချက် code) အပြည့်အစုံကို
   ရေးပါတယ်။

```c
#include <stdio.h>

/* Function prototypes */
int max(int n1, int n2);                 // int ပြန်ပေးတဲ့ function
void print_table(int start, int stop);   // ဘာမှမပြန်ပေးတဲ့ function (void)

int main(void) {
    int x, y, larger;

    printf("Enter the first value: ");
    scanf("%d", &x);
    printf("Enter the second value: ");
    scanf("%d", &y);

    larger = max(x, y);   // max function ကို ခေါ်ပြီး ရလဒ်ကို larger ထဲသိမ်း

    printf("The larger of %d and %d is %d\n", x, y, larger);

    print_table(x, larger);  // value ပြန်မပေးတဲ့ function ကို ခေါ်

    return 0;
}

/* Function definition */
int max(int n1, int n2) {
    int result;
    result = n1;

    if (n2 > n1) {
        result = n2;
    }
    return result;   // int တန်ဖိုး ပြန်ပေး
}

void print_table(int start, int stop) {
    int i;
    for (i = start; i <= stop; i++) {
        printf("%d\t", i * i);
    }
    printf("\n");
    // return statement မလို (void ဖြစ်လို့)
}
```

### Function definition ရဲ့ ပုံစံ

```
<return type> <function name> (<parameter list>)
{
   <function body>
}
```

Parameter list ရဲ့ ပုံစံ:

```
<type> <param1 name>, <type> <param2 name>, ..., <type> <last param name>
```

### Return type နဲ့ `void`

- **Value ပြန်ပေးတဲ့ function** — return type က `int`, `double` စသည်ဖြင့် ရှိပြီး `return
  တန်ဖိုး;` နဲ့ ပြန်ပေးပါတယ်။
- **Value မပြန်ပေးတဲ့ function** — return type က `void` ဖြစ်ပြီး `return` မလိုပါဘူး။
  (လိုရင် `return;` ဆိုပြီး ရေးလို့ရပါတယ်။)

### Parameters နဲ့ Arguments

- **Parameter** — function definition မှာ ကြေညာတဲ့ variable တွေ (ဥပမာ `n1`, `n2`)။
- **Argument** — function ကို ခေါ်တဲ့အခါ တကယ်ပေးလိုက်တဲ့ တန်ဖိုးတွေ (ဥပမာ `x`, `y`)။

`max(x, y)` ခေါ်တဲ့အခါ `x` ရဲ့ တန်ဖိုးက `n1` ထဲ၊ `y` ရဲ့ တန်ဖိုးက `n2` ထဲ ကူးပြီး ဝင်ပါတယ်။
C မှာ parameter တွေကို **by value** (တန်ဖိုးကို ကူးယူ) ပုံစံနဲ့ ပို့ပါတယ်။

### Call Stack (Function တွေ ခေါ်ပုံ)

Program run နေတဲ့အချိန်မှာ function တွေရဲ့ အခြေအနေကို **call stack** (execution stack) မှာ
ခြေရာခံထားပါတယ်။ Function တစ်ခု ခေါ်လိုက်တိုင်း **stack frame** အသစ်တစ်ခု ပေါ်လာပြီး၊
အဲဒီ function ရဲ့ parameter နဲ့ local variable တွေကို သိမ်းထားပါတယ်။ Function ပြီးဆုံးရင်
အဲဒီ frame ကို stack ကနေ ဖယ်ထုတ်လိုက်ပါတယ်။

`max(100, 100)` ခေါ်တဲ့အခါ stack ဟာ ဒီလိုပုံစံ ဖြစ်နိုင်ပါတယ်။

```
        ┌─────────────────────┐
 max:   │  x:       [ 100 ]   │   ← အပေါ်ဆုံး frame (အခု run နေတဲ့ function)
        │  y:       [ 100 ]   │
        │  bigger:  [ 100 ]   │
        ├─────────────────────┤
 main:  │  a:       [  13 ]   │
        │  b:       [ 100 ]   │
        │  res:     [  ?  ]   │
        └─────────────────────┘
                Stack
```

`main` က အောက်ခြေမှာ အရင်ဆုံးရှိပြီး၊ `max` ကို ခေါ်လိုက်တဲ့အခါ `max` frame က အပေါ်မှာ
ထပ်ပေါ်လာပါတယ်။ `max` ပြီးသွားရင် `max` frame ဖျက်ပြီး `main` ဆီ ပြန်ရောက်ပါတယ်။

---

## ၁.၅ Arrays and Strings

### Arrays — တူညီတဲ့ type ဒေတာတွေ စုစည်းခြင်း

**Array** ဆိုတာ တူညီတဲ့ type ရှိတဲ့ ဒေတာတန်ဖိုးများစွာကို ဆက်တိုက် (contiguous) memory
နေရာမှာ သိမ်းထားတဲ့ collection တစ်ခုပါ။

```c
#include <stdio.h>

int main(void) {
  int i, size = 0;

  // int ၁၀ လုံးဆံ့တဲ့ array ကြေညာ
  int my_arr[10];

  for (i = 0; i < 10; i++) {
    my_arr[i] = i;   // index i မှာ i ကို သိမ်း
    size++;
  }

  my_arr[3] = 100;   // index 3 ရဲ့ တန်ဖိုးကို 100 ပြောင်း

  for (i = 0; i < 10; i++) {
    printf("%d\n", my_arr[i]);
  }
  return 0;
}
```

#### အရေးကြီးတဲ့ အချက်တွေ

- **Index က 0 ကနေ စပါတယ်။** `int my_arr[10];` ဆိုရင် valid index က `0` ကနေ `9` အထိပါ။
  (index `10` မရှိပါဘူး။)
- Array ကို ကြေညာရင် size ကို `[10]` လို square bracket နဲ့ ရေးပါတယ်။
- Element တစ်ခုချင်း ဝင်ရောက်ဖို့ `my_arr[3]` လို့ ရေးပါတယ်။

#### Out-of-bounds access (အန္တရာယ်)

```c
int array1[10];
printf("%d\n", array1[9]);    // OK — valid index
printf("%d\n", array1[10]);   // မှား — index 10 ဟာ မရှိ (undefined behavior)
```

C မှာ valid index ပြင်ပကို ဝင်ရောက်တာကို compiler က မတားပါဘူး။ ဒါကို **undefined behavior**
လို့ခေါ်ပါတယ်။ Program က crash ဖြစ်နိုင်တယ်၊ တခြား variable တန်ဖိုးကို မသိမသာ
ပျက်စီးစေနိုင်တယ်၊ တစ်ခါတစ်လေ ပုံမှန်အလုပ်လုပ်သလိုတောင် ထင်ရနိုင်ပါတယ်။ ဒါကြောင့်
index ကို အမြဲ သေချာ စစ်ပါ။

### Strings — character array

C မှာ သီးသန့် string type မရှိပါဘူး။ String ဆိုတာ `char` array တစ်ခုပါ။ String ရဲ့
အဆုံးကို သိဖို့ **null character (`'\0'`)** ကို အဆုံးမှာ ထားပါတယ်။

```c
#include <stdio.h>
#include <string.h> // C string library

int main(void) {
  char str1[10];
  char str2[10];
  int len;

  str1[0] = 'h';
  str1[1] = 'i';
  str1[2] = '\0';   // null character — string ရဲ့ အဆုံး

  len = strlen(str1);   // str1 ရဲ့ စာလုံးအရေအတွက် ပြန်ပေး (2)
  printf("%s %d\n", str1, len);   // hi 2

  strcpy(str2, str1);   // str1 ရဲ့ အကြောင်းအရာကို str2 ထဲ ကူး
  printf("%s\n", str2);           // hi

  strcpy(str2, "hello");          // str2 ထဲ "hello" ကို ကူး
  len = strlen(str2);
  printf("%s has %d chars\n", str2, len);   // hello has 5 chars
  return 0;
}
```

#### `char` နဲ့ string ရဲ့ ကွာခြားချက်

```c
'h'   // char literal — single quote၊ တန်ဖိုးက ASCII 104
"h"   // string literal — double quote၊ 'h' နဲ့ '\0' နှစ်လုံးပါ
```

#### သုံးများတဲ့ string library functions

| Function | အလုပ် |
| --- | --- |
| `strlen(s)` | string ရဲ့ စာလုံးအရေအတွက် ပြန်ပေး (null မပါ) |
| `strcpy(dst, src)` | `src` ကို `dst` ထဲ ကူးယူ |
| `strcmp(a, b)` | string နှစ်ခု နှိုင်းယှဉ် (တူရင် 0) |
| `strcat(dst, src)` | `dst` နောက်ကို `src` ဆက်တွဲ |

---

## ၁.၆ Structs

**Struct** (`struct`) ဆိုတာ **မတူညီတဲ့ type** ရှိတဲ့ ဒေတာတွေကို တစ်စုတစ်စည်းတည်း သိမ်းတဲ့
နည်းပါ။ Array က တူညီတဲ့ type တွေသာ သိမ်းနိုင်ပေမယ့် struct က type အမျိုးမျိုး ပေါင်းစည်း
သိမ်းလို့ရပါတယ်။

```c
#include <stdio.h>
#include <string.h>

int main(void) {
  // struct type တစ်ခု သတ်မှတ်
  struct Student {
    char name[64];
    int age;
    float gpa;
    int grad_yr;
  };

  // struct variable တစ်ခု ကြေညာ
  struct Student student1;

  // field (အဖွဲ့ဝင်) တွေကို dot (.) နဲ့ ဝင်ရောက်
  strcpy(student1.name, "Kwame Salter");
  student1.age = 22;
  student1.gpa = 3.5;
  student1.grad_yr = 2023;

  printf("Name: %s\n", student1.name);
  printf("Age: %d\n", student1.age);
  printf("GPA: %f\n", student1.gpa);
  printf("Graduation year: %d\n", student1.grad_yr);

  return 0;
}
```

#### Struct ရဲ့ အဓိက အချက်တွေ

- **Type သတ်မှတ်ခြင်း** — `struct Student { ... };` ဆိုပြီး struct type အသစ်ကို သတ်မှတ်ပါတယ်။
- **Variable ကြေညာခြင်း** — `struct Student student1;` လို့ ကြေညာပါတယ်။
- **Field ဝင်ရောက်ခြင်း** — `student1.name`, `student1.age` စသည်ဖြင့် **dot (`.`)** operator
  နဲ့ ဝင်ရောက်ပါတယ်။
- Field တစ်ခုချင်းစီမှာ ကိုယ်ပိုင် type ရှိပါတယ် (`char[]`, `int`, `float` စသည်)။

---

## အကျဉ်းချုပ်

| အပိုင်း | အဓိက မှတ်သားစရာ |
| --- | --- |
| ၁.၁ | C program တိုင်းမှာ `main` ရှိ၊ variable ကို type နဲ့ ကြေညာ၊ `int/int` စားရင် ဒဿမပျက် |
| ၁.၂ | `printf` က format specifier သုံး၊ `scanf` မှာ `&` မဖြစ်မနေသုံး |
| ၁.၃ | `0` = false, nonzero = true; `for` နဲ့ `while` loop |
| ၁.၄ | Function မှာ prototype နဲ့ definition; `void` က value မပြန်ပေး |
| ၁.၅ | Array index က 0 ကစ၊ string က `char` array + `'\0'` |
| ၁.၆ | Struct က type မတူတဲ့ ဒေတာတွေ ပေါင်းသိမ်း၊ field ကို `.` နဲ့ ဝင်ရောက် |

နောက်အခန်းတွေမှာ **pointers**, **dynamic memory allocation**, **linked lists** စတဲ့ C ရဲ့
ပိုနက်နဲတဲ့ အကြောင်းအရာတွေကို ဆက်လေ့လာပါမယ်။
