.globl main
main:
    pushq %rbp
    movq %rsp, %rbp
    movl $17, %eax
    movl %eax, -0(%rbp)
    movl $42, %eax
    movl %eax, -4(%rbp)
    movl -0(%rbp), %eax
    movl %eax, -12(%rbp)
    movl -0(%rbp), %eax
    imull -12(%rbp), %eax
    movl %eax, -16(%rbp)
    movl -4(%rbp), %eax
    movl %eax, -20(%rbp)
    movl -4(%rbp), %eax
    imull -20(%rbp), %eax
    addl -16(%rbp), %eax
    movl %eax, -24(%rbp)
    movl $1, %eax
    addl -24(%rbp), %eax
    movl %eax, -8(%rbp)
    movl -8(%rbp), %eax
    jmp end_main
end_main:
    movq %rbp, %rsp
    popq %rbp
    ret
