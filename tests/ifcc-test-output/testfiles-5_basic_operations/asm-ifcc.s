.globl main
main:
    pushq %rbp
    movq %rsp, %rbp
    movl $2, %eax
    movl %eax, -4(%rbp)
    movl $4, %eax
    movl %eax, -8(%rbp)
    movl $11, %eax
    movl %eax, -12(%rbp)
    movl $2, %eax
    imull -12(%rbp), %eax
    addl -8(%rbp), %eax
    movl %eax, -16(%rbp)
    movl $10, %eax
    subl %eax, -16(%rbp)
    movl  -16(%rbp), %eax
    movl %eax, -20(%rbp)
    movl -4(%rbp), %eax
    movl %eax, %ecx
    movl -20(%rbp), %eax
    cltd
    idivl %ecx
    movl %eax, -0(%rbp)
    movl -0(%rbp), %eax
    jmp end_main
end_main:
    movq %rbp, %rsp
    popq %rbp
    ret
