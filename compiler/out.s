.globl main
main:
    pushq %rbp
    movq %rsp, %rbp
    movl $1, %eax
    movl %eax , -0(%rbp) 
    movl $2, %eax
    movl %eax , -4(%rbp) 
    movl $100, %eax
    movl %eax , -8(%rbp) 
    movl -4(%rbp), %eax
    movl %eax, -12(%rbp)
    movl -8(%rbp), %eax
    addl -12(%rbp), %eax
    movl %eax, -4(%rbp)
    movl -22100(%rbp), %eax
    movq %rbp, %rsp
    popq %rbp
    ret
    movq %rbp, %rsp
    popq %rbp
    ret
