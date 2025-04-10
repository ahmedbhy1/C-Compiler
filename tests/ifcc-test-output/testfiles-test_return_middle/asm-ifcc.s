.globl main
main:
    pushq %rbp
    movq %rsp, %rbp
    movl $10, %eax
    movl %eax , -0(%rbp) 
    movl $5, %eax
    movl %eax , -4(%rbp) 
    movl -0(%rbp), %eax
    movl %eax, -8(%rbp)
    movl -4(%rbp), %eax
    addl -8(%rbp), %eax
    jmp end_main
    movl $3, %eax
    movl %eax , -12(%rbp) 
end_main:
    movq %rbp, %rsp
    popq %rbp
    ret
