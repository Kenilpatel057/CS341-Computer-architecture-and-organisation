
        
        .globl count
        .text

count:
        pushl %ebp
        movl $0, %eax
        movl 8(%esp), %edx 
        movl 12(%esp), %ecx
       
        #jmp la
la:                    #begining of main loop
        cmpb $0, (%edx) #checks for null character
        je ld      #goes to return
        cmpb %ecx, (%edx)  #test to see if chars are equal
        je lb            #jump to increment eax
        jmp lc         #jump to increment string pointer
lb:                    #this loop increment eax
        addl $1, %eax
        #jmp lc
lc:                    #increments string pointer then tests for null
        incl %edx
        #cmpl %ebx, (%edx) #checks for null character
        #je ld      #goes to return
        jmp la      #there are still more characters
ld:     
	popl %ebp
        ret
        .data
nl:
        .asciz "\n"
        .end
