token list =
tocken 0 = int
tocken 1 =  
tocken 2 = main
tocken 3 = (
tocken 4 = )
tocken 5 =  
tocken 6 = {
tocken 7 = 
   
tocken 8 = int
tocken 9 =  
tocken 10 = x
tocken 11 =  
tocken 12 = =
tocken 13 =  
tocken 14 = 2
tocken 15 = ;
tocken 16 = 
   
tocken 17 = return
tocken 18 =  
tocken 19 = 42
tocken 20 = ;
tocken 21 = 

tocken 22 = }
tocken 23 = 

tocken 24 = <EOF>
.globl main
main:
    movl $2, (%rsp)
    movl (%rsp), %eax
    addq $4, %rsp
    ret
