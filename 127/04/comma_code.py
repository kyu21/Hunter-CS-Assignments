def stringify(list):
	str = ''
	for elem in list:
		if elem == list[-1]: #checks if the current element is the last element
			str += ('and ' + elem)
		else:
			str += (elem + ', ')
	return str

spam = ['apples', 'bananas', 'tofu', 'cats']
print(stringify(spam))