def encode_letter(c,r):
	newVal = ord(c) + r # stores shifted value of letter
	if c.islower(): # determines if letter is uppercase or lowercase
		if newVal > ord('z'): # if shifted value is greater than z, loop it back to a 
			newVal -= 26
		elif newVal < ord('a'): # if shifted value is less than a, loop back to z (supports negative r values)
			newVal += 26
	elif c.isupper():
		if newVal > ord('Z'):
			newVal -= 26
		elif newVal < ord('A'):
			newVal += 26
	return chr(newVal)

def encode_string(s,r):
	newStr = ''
	for char in s:
		if char.isalpha(): # checks if the character is a letter
			char = encode_letter(char,r) # calls previous function to encode each letter
		newStr += char
	return newStr

def full_encode(s):
	newStr = ''
	for x in range(26): # encodes string 26 times since there are 26 letters, hence all valid rotations
		newStr += (encode_string(s,x) + "\n")
	return newStr

print(encode_letter('a',3))
print("")
print(encode_string('abcd',-3))
print("")
print(full_encode('abcd'))