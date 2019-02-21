import math, random

alphabet = "abcdefghijklmnopqrstuvwxyz"
alphabet += alphabet.upper()
name = 'text.txt'

def rotate_char(c, n):
	rotated_c = ord(c) - 97 # shifts numbering down so that 'a' is 0
	rotated_c = (rotated_c + n) % 26 # rotates character, wrapping if past z
	return chr(rotated_c + 97) # converts ascii value back into char
	# return chr(((ord(c)-97+r)%26)+97) One-liner

def encode_string(str, n):
	result = ''
	for letter in str:
		if letter in alphabet:
			letter = rotate_char(letter,n)
		result += letter
	return result

def distance(l1, l2):
	length = len(l1)
	if length > len(l2): # Checks if lists are different lengths, if so, use the shorter length
		length = len(l2)
	sum = 0
	for i in range(length):
		sum += ((l1[i] - l2[i]) * (l1[i] - l2[i])) # distance formula
	return math.sqrt(sum)

def build_frequency_vector(str):
	spaces = str.count(" ")
	num_letters = len(str) -  spaces # count the letters in the string
	v = []
	for letter in alphabet:
		v.append(str.count(letter) / num_letters) # fills in list with frequencies of each letter
	return v

real_freq = build_frequency_vector(open(name).read())

def decode(str):
	smallest_distance = distance(build_frequency_vector(encode_string(str,len(alphabet)//2)), real_freq) # sets smallest distance to that of last rotation before wrapping
	smallest_distance_rotations = len(alphabet)//2
	for x in range(1,len(alphabet)//2):
		shifted_str = encode_string(str, x)
		letter_freq = build_frequency_vector(shifted_str)
		dist = distance(letter_freq, real_freq)
		if dist < smallest_distance:
			smallest_distance = dist
			smallest_distance_rotations = x
	return encode_string(str, smallest_distance_rotations)

s = "this is a longer sentencce with more letters so hopefully it will be closer to the real distribution"
r = encode_string(s,random.randint(0,len(alphabet)//2))

print("Original String:",s)
print("Shifted String:",r)
print("Decoded String:",decode(r))