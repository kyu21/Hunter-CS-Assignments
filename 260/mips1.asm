# Important: do not put any other data before the frameBuffer
# Also: the Bitmap Display tool must be connected to MARS and set to
#   display width in pixels: 512
#   display height in pixels: 256
#   base address for display: 0x10010000 (static data)
.data
frameBuffer:  .space 0x80000 # 256 X 512 wide pixel
wide: .word 50

.text

	la          $t1,frameBuffer       
	li           $t3,0x00FFFF00   #$t3 <- yellow     
	addi     $t2, $t2,0         #t2 <- 0
	
loop: 
	sw       $t3,0($t1)       
	addi     $t1,$t1, 4      #$t1 <- 
	addi     $t2, $t2, 1     #$t2 <- 
	bne      $t2, 0x80000, loop  #if t2 != last pixel, loop

li $a0,256
lw $a1, wide($zero)
move $t5,$a1
srl $t6, $a1, 1
sub $a0, $a0, $t6
li $a2,128
li $a3,150
srl $t6, $a3, 1
sub $a2, $a2, $t6
jal rectangle

li $v0,10
syscall

rectangle:

beq $a1,$zero,rectangleReturn # zero width: draw nothing
beq $a3,$zero,rectangleReturn # zero height: draw nothing

li $t0,0x000000FF # color: blue
la $t1,frameBuffer
add $a1,$a1,$a0 # simplify loop tests by switching to first too-far value
add $a3,$a3,$a2
sll $a0,$a0,2 # scale x values to bytes (4 bytes per pixel)
sll $a1,$a1,2
sll $a2,$a2,11 # scale y values to bytes (512*4 bytes per display row)
sll $a3,$a3,11
addu $t2,$a2,$t1 # translate y values to display row starting addresses
addu $a3,$a3,$t1
addu $a2,$t2,$a0 # translate y values to rectangle row starting addresses
addu $a3,$a3,$a0
addu $t2,$t2,$a1 # and compute the ending address for first rectangle row
li $t4,0x800 # bytes per display row

rectangleYloop:
move $t3,$a2 # pointer to current pixel for X loop; start at left edge

rectangleXloop:
sw $t0,($t3)
addiu $t3,$t3,4
bne $t3,$t2,rectangleXloop # keep going if not past the right edge of the rectangle

addu $a2,$a2,$t4 # advace one row worth for the left edge
addu $t2,$t2,$t4 # and right edge pointers
bne $a2,$a3,rectangleYloop # keep going if not off the bottom of the rectangle

rectangleReturn:
jr $ra
