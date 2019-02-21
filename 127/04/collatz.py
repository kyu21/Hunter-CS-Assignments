def collatz(number):
	print(int(number))
	if number == 1: # base case
		return number
	elif number % 2 == 0: # recursive call for if number is even (divide by 2)
		return collatz(number/2)
	else: # recursive call for if number is odd (times 3 add 1)
		return collatz((3*number)+1)

while True:
	try:
		num = int(input("Enter a positive integer: "))
		collatz(num)
		break
	except Exception as e:
		print(e) # prints the error
		print("Please enter a valid number.")