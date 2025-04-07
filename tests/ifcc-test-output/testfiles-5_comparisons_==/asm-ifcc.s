.globl main
main:
    pushq %rbp
    movq %rsp, %rbp
    movl $15, %eax
    movl %eax , -0(%rbp) 
    movl $10, %eax
    movl %eax , -4(%rbp) 
    movl -0(%rbp), %eax
    movl %eax, %ecx
    movl -4(%rbp), %eax
    cmpl %eax, %ecx
    sete %al
    movzbl %al, %eax
    movl %eax, -8(%rbp)
    movl -8(%rbp), %eax
    movq %rbp, %rsp
    popq %rbp
    ret
