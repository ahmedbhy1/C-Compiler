# config.mk contains the paths to antlr4 etc.
# Each student should have a config.mk corresponding to her system.

include config.mk

CC=g++
CCFLAGS+=-g -c -std=c++17 -I"$(ANTLRINC)" -Wno-attributes
LDFLAGS=-g

# Corrected ANTLR paths without quotes in the definition
ANTLRINC=C:/Users/IT Dep/Desktop/INSA/S2/4IF - Compilateur/compilateur/compiler/vcpkg/installed/x64-windows/include/antlr4-runtime
ANTLRLIB="C:/Users/IT Dep/Desktop/INSA/S2/4IF - Compilateur/compilateur/compiler/vcpkg/installed/x64-windows/lib/libantlr4-runtime.a""

default: all
all: ifcc

##########################################
# link together all pieces of our compiler 
OBJECTS=build/ifccBaseVisitor.o \
	build/ifccLexer.o \
	build/ifccVisitor.o \
	build/ifccParser.o \
	build/main.o \
	build/CodeGenVisitor.o

ifcc: $(OBJECTS)
	@if not exist build mkdir build
	$(CC) $(LDFLAGS) build/*.o "$(ANTLRLIB)" -o ifcc

##########################################
# compile our hand-written C++ code: main(), CodeGenVisitor, etc.
build/%.o: %.cpp generated/ifccParser.cpp
	@if not exist build mkdir build
	$(CC) $(CCFLAGS) -MMD -o $@ $< 

##########################################
# compile all the antlr-generated C++ files
build/%.o: generated/%.cpp
	@if not exist build mkdir build
	$(CC) $(CCFLAGS) -MMD -o $@ $< 

# automagic dependency management: `gcc -MMD` generates all the .d files for us
-include build/*.d
build/%.d:

##########################################
# generate the C++ implementation of our Lexer/Parser/Visitor
generated/ifccLexer.cpp: generated/ifccParser.cpp
generated/ifccVisitor.cpp: generated/ifccParser.cpp
generated/ifccBaseVisitor.cpp: generated/ifccParser.cpp
generated/ifccParser.cpp: ifcc.g4
	@if not exist generated mkdir generated
	java -jar "C:\Program Files\ANTLR4\antlr-4.13.2-complete.jar" -visitor -no-listener -Dlanguage=Cpp -o generated ifcc.g4

# prevent automatic cleanup of "intermediate" files like ifccLexer.cpp etc
.PRECIOUS: generated/ifcc%.cpp   

##########################################
# view the parse tree in a graphical window

# Usage: `make gui FILE=path/to/your/file.c`
FILE ?= ../tests/testfiles/1_return42.c

gui:
	@if not exist generated mkdir generated
	@if not exist build mkdir build
	java -jar "C:\Program Files\ANTLR4\antlr-4.13.2-complete.jar" -Dlanguage=Java -o generated ifcc.g4
	javac -cp "$(ANTLRJAR)" -d build generated/*.java
	java -cp "$(ANTLRJAR);build" org.antlr.v4.gui.TestRig ifcc axiom -gui "$(FILE)"

##########################################
# delete all machine-generated files
clean:
	@if exist build rmdir /s /q build
	@if exist generated rmdir /s /q generated
	@if exist ifcc del ifcc
