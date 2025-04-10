.globl main
test2:
    pushq %rbp
    movq %rsp, %rbp
    movl $3, %eax
    jmp end_test2
end_test2:
    movq %rbp, %rsp
    popq %rbp
    ret
test:
    pushq %rbp
    movq %rsp, %rbp
    movl $4, %eax
    jmp end_test
end_test:
    movq %rbp, %rsp
    popq %rbp
    ret
main:
    pushq %rbp
    movq %rsp, %rbp
    call test
    movl %eax, -4(%rbp)
    call test2
    imull -4(%rbp), %eax
    movl %eax , -0(%rbp) 
    movl -0(%rbp), %eax
    movl %eax, -8(%rbp)
    movl $1, %eax
    addl -8(%rbp), %eax
    jmp end_main
end_main:
    movq %rbp, %rsp
    popq %rbp
    ret
