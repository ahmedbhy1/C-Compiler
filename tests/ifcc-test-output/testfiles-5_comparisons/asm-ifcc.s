.globl main
main:
    pushq %rbp
    movq %rsp, %rbp
    subq $4, %rsp
    movl $5, %eax
    movl %eax, -0(%rbp)
    subq $4, %rsp
    movl $10, %eax
    movl %eax, -4(%rbp)
    subq $4, %rsp
    movl -0(%rbp), %eax
    pushq %rax
    movl -4(%rbp), %eax
    movl %eax, %ebx
    popq %rax
    cmpl %ebx, %eax
    sete %al
    movzbl %al, %eax
    movl %eax, -8(%rbp)
    movl -0(%rbp), %eax
    pushq %rax
    movl -4(%rbp), %eax
    movl %eax, %ebx
    popq %rax
    cmpl %ebx, %eax
    setne %al
    movzbl %al, %eax
    movl %eax, -8(%rbp)
    movl -0(%rbp), %eax
    pushq %rax
    movl -4(%rbp), %eax
    movl %eax, %ebx
    popq %rax
    cmpl %ebx, %eax
    setg %al
    movzbl %al, %eax
    movl %eax, -8(%rbp)
    movl -0(%rbp), %eax
    pushq %rax
    movl -4(%rbp), %eax
    movl %eax, %ebx
    popq %rax
    cmpl %ebx, %eax
    setl %al
    movzbl %al, %eax
    movl %eax, -8(%rbp)
    movl -8(%rbp), %eax
    movq %rbp, %rsp
    popq %rbp
    ret
