.data
	prompt:	.asciiz "Please enter an integer between 4 and 40\n"
	message: .asciiz "Your fibonacci series is as follows\n"
	errorInput: .asciiz "The number you entred is not within bounds!"
	space: .asciiz " "

.text
	main:
		#prompt the user to enter the number
		li $v0, 4	#'4' code for printing text
		la $a0, prompt	# load the address of prompt to the register $a0
		syscall		#system call
	
		#getting the number from user 
		li $v0, 5	#'5' is the 'code' for cin to $v0
		syscall
	
		#storing the number  from user in a safe $t0
		move $t0, $v0
	
		#checking for validity of the user input (3 < n < 40)
        	bltz $t0, errorI	#Branch to errorI if input less than zero
        	bgt $t0, 40, errorI	#Branch to errorI if input is greater than 40	

		#displaying the fibonacci message
		li $v0, 4
		la $a0, message
		syscall 
		
		move  $a1, $t0				#move user input($t1) to register $a1
		subi  $a1, $a1, 3
        	
        	jal fib
        	
	
	#fibonacci function
	fib:
       		move $t3, $a1
       		li $t0,0 #previous
        	li $t1, 1 #Current
        	li $t2, 0 #Next

        	move $a0, $t0
        	li $v0, 1
        	syscall
        	
        	li $v0,4				# This for printing the space between the numbers
        	la $a0,space
        	syscall

        	move $a0,$t1
       		li $v0,1
        	syscall
        	
        	loop:
        		add $t2,$t1,$t0			#add previous value $t0 to current value $t1 and save it to $t2

        		li $v0,4
        		la $a0,space
        		syscall

        		move $a0,$t2
        		li $v0,1
        		syscall

        		move $t0,$t1
        		move $t1,$t2

        		slt $t5,$t4,$t3			#if $t4 is less than $t3, set $t5 to 1
        		beqz  $t5,end

        		addi $t4,$t4,1

        	j loop
	
	#Printing the error message 
	errorI:
		li $v0, 4
		la $a0, errorInput
		syscall
		
	#Telling the system to end the program
	end:
		li $v0, 10
		syscall
