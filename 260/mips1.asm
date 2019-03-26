.data
frameBuffer: .space 0x80000 # 512 wide X 256 high pixels

.text
drawline:  la	$t1, frameBuffer
	   li	$t3, 0x0000FF00 # $t3 <- green
	   sw	$t3, 56300($t1)
	   sw	$t3, 56304($t1)
	   sw	$t3, 56308($t1)
	   sw	$t3, 76308($t1)
	   li	$v0, 10 # exit code
	   syscall