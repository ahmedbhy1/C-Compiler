.globl main
main:
    pushq %rbp
    movq %rsp, %rbp
    subq $4, %rsp
    subq $4, %rsp
    subq $4, %rsp
    subq $4, %rsp
    movl $10, %eax
    movl %eax, -0(%rbp)
    movl $12, %eax
    movl %eax, -4(%rbp)
    movl -0(%rbp), %eax
    movl %eax, -16(%rbp)
    movl -4(%rbp), %eax
    addl -16(%rbp), %eax
    movl %eax, -8(%rbp)
    movl -8(%rbp), %eax
    movq %rbp, %rsp
    popq %rbp
    ret