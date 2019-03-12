import math, random
real_stats = [0.08167,0.01492,0.02782,0.04253,0.12702,0.02228,0.02015,0.06094,0.06966,0.00153,0.00772,0.04025,0.02406,0.06749,0.07507,0.01929,0.00095,0.05987,0.06327,0.09056,0.02758,0.00978,0.02360,0.00150,0.01974,0.00074] # data retrieved from internet

def rotate_char(c, n):
	rotated_c = ord(c) - 97 # shifts numbering down so that 'a' is 0
	rotated_c = (rotated_c + n) % 26 # rotates character, wrapping if past z
	return chr(rotated_c + 97) # converts ascii value back into char
	# return chr(((ord(c)-97+r)%26)+97) One-liner

def encode_string(str, n):
	result = ''
	for letter in str:
		if letter in "abcdefghijklmnopqrstuvwxyz":
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
	for letter in "abcdefghijklmnopqrstuvwxyz":
		v.append(str.count(letter) / num_letters) # fills in list with frequencies of each letter
	return v

# everything above this point was developed in class by Professor Zamansky

def decode(str):
	smallest_distance = distance(build_frequency_vector(encode_string(str,25)), real_stats) # sets smallest distance to that of last rotation before wrapping
	smallest_distance_rotations = 25
	for x in range(26):
		shifted_str = encode_string(str, x)
		letter_freq = build_frequency_vector(shifted_str)
		dist = distance(letter_freq, real_stats)
		if dist < smallest_distance:
			smallest_distance = dist
			smallest_distance_rotations = x
	return encode_string(str, smallest_distance_rotations)

shift_amount = random.randint(0,25)
s = "this is a longer sentencce with more letters so hopefully it will be closer to the real distribution"
r = encode_string(s,shift_amount)

print("Original String:",s)
print("Shifted String:",r)
print("Decoded String:",decode(r))


'''
Sample Output

Original String: this is a longer sentencce with more letters so hopefully it will be closer to the real distribution
Shifted String: sghr hr z knmfdq rdmsdmbbd vhsg lnqd kdssdqr rn gnodetkkx hs vhkk ad bknrdq sn sgd qdzk chrsqhatshnm
Decoded String: this is a longer sentencce with more letters so hopefully it will be closer to the real distribution
'''