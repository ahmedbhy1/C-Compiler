token list =
tocken 0 = int
tocken 1 =  
tocken 2 = main
tocken 3 = (
tocken 4 = )
tocken 5 =  
tocken 6 = {
tocken 7 = 
   
tocken 8 = return
tocken 9 =  
tocken 10 = 42
tocken 11 = ;
tocken 12 = 

tocken 13 = }
tocken 14 = 

tocken 15 = <EOF>
.globl main
main:
    movl (%rsp), %eax
    addq $4, %rsp
    ret
