.globl main
main:
    pushq %rbp
    movq %rsp, %rbp
    movl $10, %eax
    movl %eax , -0(%rbp) 
    movl $0, %eax
    movl %eax , -4(%rbp) 
    movl $42, %eax
    movl %eax, -4(%rbp)
    movl -4(%rbp), %eax
    jmp end_main
end_main:
    movq %rbp, %rsp
    popq %rbp
    ret
