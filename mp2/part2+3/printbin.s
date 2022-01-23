
.global printbin
	.text
printbin:
	pushl %ebp		#pushing in stack	    
	movl %esp, %ebp
    	movb 8(%ebp), %al		
	movl $string, %edx		
	call donibble		# calling donibble 1st time	
	movb $' ', (%edx)		
	incl %edx			   
	call donibble		# calling donibble 2nd time	
	movl $string, %eax	#move string to eax	
    	movl %ebp, %esp			
	popl %ebp               #poping from stack
	ret				        

donibble:
	movl $4, %ecx			

lp:
	shlb $1, %al		#shifting 1 byte	
	jc lp1			    
	movb $'0', (%edx)		
	jmp lp2

lp1:
	movb $'1', (%edx)		

lp2:
	incl %edx			    
	loop lp			#loop for lp    
	ret				        
    	.data
string:	                    
	.asciz "xxxx xxxx\n"      #to store binary string