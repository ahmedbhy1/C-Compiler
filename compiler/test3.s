.globl main
main:
    pushq %rbp
    movq %rsp, %rbp
    subq $4, %rsp
    subq $4, %rsp
    subq $4, %rsp
    movl $32, -4(%rbp)
    movl -4(%rbp), %eax
    movq %rbp, %rsp
    popq %rbp
    ret