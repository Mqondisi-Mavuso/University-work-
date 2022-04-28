
.data
array: .space 800
prompt: .asciiz "Enter elements of array (0 to stop): \n"
output: .asciiz "After sorted in ascending order: \n"
size:	.word	5		# actual count of the elements in the array.
line:	.asciiz	"\n"		# a newline string.
space:	.asciiz " "		# a space string.
.text
        # printing promt line
        la $a0, prompt
        li $v0, 4
        syscall
        
        # loading base address of array
        la $a0, array
        li $a1, 0 #initialize i
        
# looping and taking input until 0 is entered
loop_input:
        li $v0, 5 #load immidiatel the user input (integer)
        syscall
        beq $v0, 0, end_loop_input #stop loopif input  == zero (0)
        sll $t0, $a1, 2 # $t1 = i * 4 (the ith position * 4 bytes to fit an integer value)
        add $t0, $t0, $a0 #move $t0 to the next insertion point of the array - > $t0 = array[current_i]
        sw $v0, 0($t0) #insert user input at array[current_i] -> more of a swap of values 
        addi $a1, $a1, 1 #increase i by 1 i = i + 1
        j loop_input # continue getting values (recursion)
        
end_loop_input:        
        #assign $a1 to global variable size
        la	$t0, size		# load address of size to $t0.
	sw	$a1, 0($t0)		#save the size into argument register
	
        # calling sort prep to begin sorting our filled array
        jal sort_prep
	
# loop to print array values
loop_print:
        beq $t0, $a1, exit
        sll $t1, $t0, 2
        addi $t0, $t0, 1
        add $t1, $t1, $s0
        # accessing and printing array value
        lw $a0, 0($t1)
        li $v0, 1
        syscall
        
        # print space
        li $a0, 32
        li $v0, 11
        syscall
        
        j loop_print
sort_prep:
	la	$t0, array		# load array to $t0.
	lw	$t1, size		# load array size to $t1.
	li	$t2, 1			# loop runner, starting from 1.
sort_xloop:
	la	$t0, array		# load array to $t0.
	bge	$t2, $t1, sort_xloop_end	# while (t2 < $t1).
	move	$t3, $t2		# copy $t2 to $t3.
sort_iloop:
	la	$t0, array		# load array to $t0.
	mul	$t5, $t3, 4		# multiply $t3 with 4, and store in $t5
	add	$t0, $t0, $t5		# add the array address with $t5, which is the index multiplied with 4.
	ble	$t3, $zero, sort_iloop_end	# while (t3 > 0).
	lw	$t7, 0($t0)		# load array[$t3] to $t7.
	lw	$t6, -4($t0)		# load array[$t3 - 1] to $t6.
	bge	$t7, $t6, sort_iloop_end	# while (array[$t3] < array[$t3 - 1]).
	lw	$t4, 0($t0)
	sw	$t6, 0($t0)
	sw	$t4, -4($t0)
	subi	$t3, $t3, 1
	j	sort_iloop		# jump back to the beginning of the sort_iloop.
sort_iloop_end:
	addi	$t2, $t2, 1		# increment loop runner by 1.
	j	sort_xloop		# jump back to the beginning of the sort_xloop.
sort_xloop_end:
	li	$v0, 4			# 4 = print_string syscall.
	la	$a0, output	# load sorted_array_string to argument register $a0.
	syscall				# issue a system call.
	li	$v0, 4			# 4 = print_string syscall.
	la	$a0, line		# load line to argument register $a0.
	syscall				# issue a system call.
	jal	print			# call print routine.
exit:
	li	$v0, 10			# 10 = exit syscall.
	syscall				# issue a system call.

print:
print_loop_prep:
	la	$t0, array
	lw	$t1, size
	li	$t2, 0
print_loop:
	bge	$t2, $t1, print_end
	li	$v0, 1
	lw	$a0, 0($t0)
	syscall
	li	$v0, 4
	la	$a0, space
	syscall
	addi	$t0, $t0, 4
	addi	$t2, $t2, 1
	j	print_loop
print_end:
	li	$v0, 4
	la	$a0, line
	syscall
	jr	$ra
