.globl main
main:
    pushq %rbp
    movq %rsp, %rbp
    movl $2, %eax
    movl %eax , -4(%rbp) 
    movl $4, %eax
    movl %eax , -8(%rbp) 
    movl -8(%rbp), %eax
    movl %eax, -12(%rbp)
    movl -4(%rbp), %eax
    addl -12(%rbp), %eax
    movq %rbp, %rsp
    popq %rbp
    ret
#Variable 'x' declared but never used
