.data
	myMessage: .asciiz "This is my first function practice \n"
	name: 	.asciiz "Mqondisi Mavuso\n"
	age: .asciiz "24"
	
.text
	main:
		addi $t0, $zero, 24	# Assign 24 to $t0
		
		jal function		# function call
		
		# This for terminating the programm
		li $v0, 10
		syscall
		
	# function definition
	function:
		li $v0, 4	# Tell the programme to prepare to print some text on the screen
		la $a0, myMessage	# load address of myMessage on the $a0 register
		syscall			# exucute the function
		
		li $v1, 4		
		la $a0, name		# load address of the name to the $a0 register
		syscall
		
		li $v1, 4
		la $a0, age		# load the address of the call to the $a0 register
		syscall
		
		jr $ra			# return the address to where the function was called 