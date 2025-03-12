.globl main
main:
    subq $4, %rsp       # Allocate 4 bytes on the stack for x
    movl $12, (%rsp)     # Store the value 12 in x (on the stack)
    movl (%rsp), %eax   # Load the value of x into %eax (return value register)
    addq $4, %rsp       # Deallocate the space for x
    ret                 # Return from the function

