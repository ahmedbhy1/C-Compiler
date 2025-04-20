**PLD Comp : C compiler written in C++ and using Antlr4, by HexaOne (H412)**  
This is a long duration project made in 4th year at INSA Lyon. The objective of this project is the design of a compiler for a subset of the C language.

---

**Folders**  
- `compiler/` : contains the Antlr4 grammar (`ifcc.g4`).  
- `compiler/src/` : contains the source code (`.h` and `.cpp` files).  
- `tests/` : contains all the files and scripts related to tests.

---

**Prerequisites**
You have to override the antlr directories in the Makefile with you local installation :

ANTLR4_BINDIR=/usr/bin
ANTLR4_INCDIR=/shares/public/tp/ANTLR4-CPP/antlr4-runtime 
ANTLR4_LIBDIR=/shares/public/tp/ANTLR4-CPP/lib

---

**Usage**  
First, you have to go in the `compiler/` folder.

You can compile the project by running `make`.

You can execute the compiler with:

./ifcc INPUT_FILE [OUTPUT_FILE] [--as=ASSEMBLY_TYPE]

- `INPUT_FILE` : a path to a `.c` file with the code you want to compile  
- `OUTPUT_FILE` : a path to a `.s` file, where the assembly code will be written (default: same name as `INPUT_FILE`, with `.s` extension)  
- `ASSEMBLY_TYPE` : the assembly language you want to compile to. Supported: `x86`, `arm` (default: `x86`)

---

**Implemented Features**

✅ Basic data type: `int` (32-bit)  
✅ Variable declarations  
✅ Integer and character constants (using single quotes)  
✅ Arithmetic operations: `+`, `-`, `*`  
✅ Division and modulo  
✅ Bitwise logical operations: `|`, `&`, `^`  
✅ Comparison operations: `==`, `!=`, `<`, `>`  
✅ Unary operations: `!` and `-`  
✅ Variable declarations anywhere in the code  
✅ Assignments (returns a value, as in C)  
✅ Input/Output using `putchar` and `getchar`  
✅ Function definitions with parameters and return types (`int` or `void`)  
✅ Block structures using `{` and `}`  
✅ Control structures: `if`, `else`, `while`  
✅ `return expression` supported anywhere  
✅ Verification that a variable is declared before use  
✅ Verification that a variable is not declared multiple times  
✅ Verification that a declared variable is used

---

**Tests**  
You can run all the tests with `./ifcc-test.py ./testfiles`.

Then, you can view detailed results in the folder `tests/pld-test-output/` (one folder per test).
