.data

frameBuffer: .space 0x80000 # 512 wide X 256 high pixels

m : .word 40
n : .word 40

.text 
	la $t0, m
	la $t1, n
	
	lw $a0, 0($t0)		# a0 = m
	lw $a1, 0($t1)		# a1 = n
	
	# check for valid
	
	jal perform
	
	li $v0, 10	# Exit code
	syscall
	
	
	
	
perform:
	la $t1, frameBuffer
	
	li $s3, 0x000000ff	# t3 <= blue
	li $s4, 0x00ffff00	# t4 <= yellow
	
	add $t0, $t1, $zero	# t0 <= address of frameBuffer 0x10010000
	addi $t2, $t1, 0x80000	# t5 <= last byte of frame buffer
	
   backgroundLoop: sw $s4, 0($t0)	# t1[x][y]'s color = yellow
	addi $t0, $t0, 0x4		# t0 <= t0 + 4
	slt $t1, $t0, $t2		# t1 = 1 if current address < end of frame's address
	bne $t1, $zero, backgroundLoop 
	
	
	addi $sp, $sp, -16	# push...
	sw $ra, 12($sp)
	sw $t1, 8($sp)		# ... 
	sw $a0, 4($sp)
	sw $a1, 0($sp) 		# ... 

	add $a2, $a0, $a0	# a2 = 2m
	add $a2, $a2, $a1	# a2 = 2m + n
	add $a3, $zero, $a1	# a3 = n
	jal rectangle
	
	add $a3, $a0, $a0	# a2 = 2m
	add $a3, $a3, $a1	# a2 = 2m + n
	add $a2, $zero, $a1	# a3 = n
	jal rectangle
	
	lw $ra, 12($sp)
	lw $t1, 8($sp) 		# pop a0
	lw $a0, 4($sp)
	lw $a1, 0($sp) 		# pop a1
	addi $sp, $sp, 16	# deallocate
	
	jr $ra
		
rectangle: 
	la $t1, frameBuffer
	addi $t2, $zero, 0x1	# t2 = 1
	sll $t2, $t2, 8		# t2 = 256
	sll $t3, $t2, 1		# t3 = 512
	sub $t2, $t2, $a2 	# t2 = 256 - a
	
	srl $t2, $t2, 1 	# t2 = (256 - a)/2
	
	sub $t3, $t3, $a3	# t3 = 512 - n
	srl $t3, $t3, 1		# t3 = (512 - n)/2
	
	sll $t4, $t2, 9		# t4 = 512(256 - a)/2
	
	addu $t5, $t3, $a3 	# t5 = (512 - n)/2 + n
	sub $t5, $t4, $t5 	# t5 = 512(256 - a)/2 - ([512 - n]/2 + n)
	sll $t5, $t5, 2		# t5 = 4 * t5
	addu $t5, $t5, $t1 	# t5 = base address of the starting point of the rectangle
	
	sub $t6, $t4, $t3 	# t6 = 512(256 - a)/2 - [512 - n]/2
	sll $t6, $t6, 2		# t6 = 4 * t6
	addu $t6, $t6, $t1	# t6 = end address of a single row
	
	add $t7, $t2, $a2 	# t7 = (256 - a)/2 + a
	sll $t7, $t7, 9		# t7 = 512 * t7
	sub $t7, $t7, $t3	# t7 = 512[(256 - a)/2 + a] - (512 - n)/2
	sll $t7, $t7, 2		# t7 = 4* t7 for the bytes
	addu $t7, $t7, $t1 	# t7 = final position of the corner of rectangle
	
	li $t8,0x800 		# t8 has the number of display
	
 loop2: addu $s1, $zero, $t5	# s1 = base address 
	
  loop:	sw $s3, 0($s1)		# color in blue
	addi $s1, $s1, 0x4	# s1 += 4
	
	slt $t0, $s1, $t6 	# t0 = 1 if base addr < end of row addr
	bne $t0, $zero, loop
	
	addu $t5, $t5, $t8	# t5 = t5 times 512 // next column
	addu $t6, $t6, $t8	# t6 next column
	slt $t0, $s1, $t7 	# t0 = 1 if current addr is not final
	bne $t0, $zero, loop2
		
	jr $ra
