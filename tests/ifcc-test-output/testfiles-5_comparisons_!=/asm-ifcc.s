.globl main
main:
    pushq %rbp
    movq %rsp, %rbp
    movl $15, %eax
    movl %eax , -0(%rbp) 
    movl $10, %eax
    movl %eax , -4(%rbp) 
    movl -0(%rbp), %eax
    pushq %rax
    movl -4(%rbp), %eax
    movl %eax, %ebx
    popq %rax
    cmpl %ebx, %eax
    setne %al
    movzbl %al, %eax
    movl %eax, -8(%rbp)
    movl -8(%rbp), %eax
    jmp end_main
end_main:
    movq %rbp, %rsp
    popq %rbp
    ret
