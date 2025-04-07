.globl main
main:
    pushq %rbp
    movq %rsp, %rbp
    movl $5, %eax
    movl %eax , -0(%rbp) 
    movl $3, %eax
    movl %eax , -4(%rbp) 
    movl $5, %eax
    negl %eax
    movl %eax, -12(%rbp)
    movl $3, %eax
    imull -12(%rbp), %eax
    movl %eax, -16(%rbp)
    movl $2, %eax
    negl %eax
    subl %eax, -16(%rbp)
    movl  -16(%rbp), %eax
    movl %eax, -8(%rbp)
    movl -8(%rbp), %eax
    movq %rbp, %rsp
    popq %rbp
    ret
#Variable 'x' declared but never used
#Variable 'y' declared but never used
