.globl main
main:
    pushq %rbp
    movq %rsp, %rbp
    movl $5, %eax
    movl %eax , -0(%rbp) 
    movl $3, %eax
    movl %eax , -4(%rbp) 
    movl $2, %eax
    movl %eax , -8(%rbp) 
    movl $1, %eax
    movl %eax, -16(%rbp)
    movl -0(%rbp), %eax
    addl -16(%rbp), %eax
    movl %eax, -20(%rbp)
    movl -4(%rbp), %eax
    movl %eax, -24(%rbp)
    movl -8(%rbp), %eax
    movl %eax, -28(%rbp)
    movl $1, %eax
    and -28(%rbp), %eax
    xor -24(%rbp), %eax
    or -20(%rbp), %eax
    movl %eax, -32(%rbp)
    movl $2, %eax
    imull -32(%rbp), %eax
    movl %eax, -12(%rbp)
    movl -12(%rbp), %eax
    jmp end_main
end_main:
    movq %rbp, %rsp
    popq %rbp
    ret
