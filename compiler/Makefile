# config.mk contains the paths to antlr4 etc.
include config.mk

CC = g++
CCFLAGS += -g -c -std=c++17 -I$(ANTLRINC) -Wno-attributes
LDFLAGS = -g

default: all
all: ifcc

##########################################
# Link together all pieces of our compiler 
OBJECTS = build/ifccBaseVisitor.o \
          build/ifccLexer.o \
          build/ifccVisitor.o \
          build/ifccParser.o \
          build/main.o \
          build/CodeGenVisitor.o \
          build/IR.o

ifcc: $(OBJECTS)
	@mkdir -p build
	$(CC) $(LDFLAGS) build/*.o $(ANTLRLIB) -o ifcc

##########################################
# Compile our hand-written C++ code
build/%.o: %.cpp generated/ifccParser.cpp
	@mkdir -p build
	$(CC) $(CCFLAGS) -MMD -o $@ $<

##########################################
# Compile IR.cpp (new rule)
build/IR.o: IR.cpp IR.h
	@mkdir -p build
	$(CC) $(CCFLAGS) -MMD -o $@ $<

##########################################
# Compile all the antlr-generated C++
build/%.o: generated/%.cpp
	@mkdir -p build
	$(CC) $(CCFLAGS) -MMD -o $@ $<

# Automagic dependency management
-include build/*.d
build/%.d:

##########################################
# Generate the C++ implementation of our Lexer/Parser/Visitor
generated/ifccLexer.cpp: generated/ifccParser.cpp
generated/ifccVisitor.cpp: generated/ifccParser.cpp
generated/ifccBaseVisitor.cpp: generated/ifccParser.cpp
generated/ifccParser.cpp: ifcc.g4
	@mkdir -p generated
	$(ANTLR) -visitor -no-listener -Dlanguage=Cpp -o generated ifcc.g4

.PRECIOUS: generated/ifcc%.cpp

##########################################
# View the parse tree in a graphical window
FILE ?= ../tests/testfiles/1_return42.c

gui:
	@mkdir -p generated build
	$(ANTLR) -Dlanguage=Java -o generated ifcc.g4
	javac -cp $(ANTLRJAR) -d build generated/*.java
	java -cp $(ANTLRJAR):build org.antlr.v4.gui.TestRig ifcc axiom -gui $(FILE)

##########################################
# Clean
clean:
	rm -rf build generated
	rm -f ifcc