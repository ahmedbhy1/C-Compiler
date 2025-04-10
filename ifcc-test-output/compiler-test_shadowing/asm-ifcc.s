.globl main
main:
    pushq %rbp
    movq %rsp, %rbp
    movl $10, %eax
    movl %eax , -0(%rbp) 
    movl $5, %eax
    movl %eax , -4(%rbp) 
    movl -4(%rbp), %eax
    movq %rbp, %rsp
    popq %rbp
    ret
    movl -0(%rbp), %eax
    movq %rbp, %rsp
    popq %rbp
    ret
    movq %rbp, %rsp
    popq %rbp
    ret
