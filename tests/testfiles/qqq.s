.globl main
main:
    pushq %rbp
    movq %rsp, %rbp
    movl $'a', %eax
    movl %eax, %edi
    call putchar
    movl $0, %eax
    movq %rbp, %rsp
    popq %rbp
    ret