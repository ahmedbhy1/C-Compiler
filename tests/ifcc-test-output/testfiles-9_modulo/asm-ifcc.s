.globl main
main:
    pushq %rbp
    movq %rsp, %rbp
    movl $0, %eax
    movl %eax, -4(%rbp)
    movl $3, %eax
    movl %eax, %ecx
    movl -4(%rbp), %eax
    cltd
    idivl %ecx
   movl %edx, %eax
    movl %eax, -0(%rbp)
    movl -0(%rbp), %eax
    jmp end_main
end_main:
    movq %rbp, %rsp
    popq %rbp
    ret
