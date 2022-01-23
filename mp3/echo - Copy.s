	.data

	escapeChar:	 .byte 0
	currentChar:	 .byte 0

	.text
	.globl echo

echo:
	pushl %ebp           #stack frame setup
	movl %esp, %ebp
	subl $12, %esp 	     #adjust pointer for two passed vars
	movl 8(%ebp), %edx   #take conport from stack
	movl 12(%ebp), %ecx  #take esc_char from stack
	movb %cl,escapeChar  #put esc_char in as var
	jmp loop	     #begin loop

loop:
	addw $4, %dx	  #move dx to status byte
	inb (%dx), %al    #copy status byte
	orb $0x3, %al	   #set RTS and DTR true
	outb %al, (%dx)
	jmp loopf      #check modem status

loopf:
	addw $2, %dx	    #move dx to modem status byte
	inb (%dx), %al	    #copy modem status byte
	andb $0xb0, %al	    #check if char == escape
	cmpb $0xb0, %al
	jnz loopf	    #if true, move to dataloop
	subw $1, %dx	    #move dx to read status byte
	jmp loops	    #if false, reloop until true

loops:
	inb (%dx), %al	        #copy read byte
	andb $0x1, %al	        #check if data ready
	jz loops	        #if no data ready, wait for ready
	subw $5, %dx		#move dx to data
	inb (%dx), %al	        #if data ready, put in reg
	cmpb escapeChar, %al	#check if char is the escchar
	jz done			#if so, done
	movb %al, currentChar   #else move data to currentchar
	addw $5, %dx		#move dx to read byte
	jmp loopt		#go to sendloop

loopt:
	inb (%dx), %al		#copy read byte
	andb $0x20, %al		#check if transmit reg empty
	jz loopt		#if not empty, wait until it is
	movb currentChar, %al	#move current char to reg
	subw $5, %dx		#move to data byte
	outb %al, (%dx)		#send char
	addw $5, %dx		#move to read byte
	jmp loops		#return to read

done:
	movl %ebp, %esp	     #replace stack
	popl %ebp	     #restore ebp
	ret		     #return (function is void)
	.end		     #end function