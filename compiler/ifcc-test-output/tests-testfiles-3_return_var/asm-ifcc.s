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
tocken 11 = ;
tocken 12 = 
    
tocken 13 = x
tocken 14 = =
tocken 15 = 8
tocken 16 = ;
tocken 17 = 
    
tocken 18 = return
tocken 19 =  
tocken 20 = x
tocken 21 = ;
tocken 22 = 

tocken 23 = }
tocken 24 = 

tocken 25 = <EOF>
.globl main
main:
    subq $4, %rsp
    movl $8, (%rsp)
    movl (%rsp), %eax
    addq $4, %rsp
    ret
