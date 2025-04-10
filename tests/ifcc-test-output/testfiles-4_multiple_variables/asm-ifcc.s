.globl main
main:
    pushq %rbp
    movq %rsp, %rbp
    movl $1, %eax
    movl %eax, -0(%rbp)
    movl $2, %eax
    movl %eax, -4(%rbp)
    movl $23, %eax
    movl %eax, -0(%rbp)
    movl -0(%rbp), %eax
    jmp end_main
end_main:
    movq %rbp, %rsp
    popq %rbp
    ret
