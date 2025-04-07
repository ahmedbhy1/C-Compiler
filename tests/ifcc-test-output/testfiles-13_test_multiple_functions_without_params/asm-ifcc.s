.globl main
test2:
    pushq %rbp
    movq %rsp, %rbp
    movl $3, %eax
    movq %rbp, %rsp
    popq %rbp
    ret
test:
    pushq %rbp
    movq %rsp, %rbp
    movl $4, %eax
    movq %rbp, %rsp
    popq %rbp
    ret
main:
    pushq %rbp
    movq %rsp, %rbp
    call test
    movl %eax, -0(%rbp)
    call test2
    imull -0(%rbp), %eax
    movl %eax , -0(%rbp) 
    movl -0(%rbp), %eax
    movl %eax, -8(%rbp)
    movl $1, %eax
    addl -8(%rbp), %eax
    movq %rbp, %rsp
    popq %rbp
    ret
