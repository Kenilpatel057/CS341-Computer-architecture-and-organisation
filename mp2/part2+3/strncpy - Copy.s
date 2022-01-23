.text
	.globl  mystrncpy
mystrncpy:
	pushl	%ebp			# This will setup stack frame
	movl	%esp, %ebp
	movl	8(%ebp), %ecx		# get argument s
	movl	12(%ebp), %edx		# get argument ct
	movl    16(%ebp), %edi	        # get argument n
loop:
	movb	(%edx), %al          	# move a byte from source
	movb	%al, (%ecx)	        # move via al to destination
	incl	%ecx		        # increment to pointer
	incl	%edx	                # incrementing from pointer
	decl    %edi                    # decrement number of bytes moved to n
	cmpb    $0, %al		        # check for null terminator
	jz      exit		        # jumping if the byte moved was the null term
	cmpl    $0, %edi            	# This will check if nis 0
	jnz     loop                	# jump out of the loop # of byte moved is not equal to 0

exit:
	movl	8(%ebp), %eax		# returning address of s in %eax
	movl	%ebp, %esp		# removing stack frame
	popl	%ebp
	ret
	.end