import random

# creates a madlib sentence
sen = "NAME VERB to the park. NAME and I played NOUN and VERB. Then, we VERB to my house and we VERB."

# creates the keywords that will fill in the gaps
nouns = ['basketball', 'soccer', 'tag']
verbs = ['walked', 'ran', 'biked', 'crawled']
names = ['Bob', 'Sabrina', 'Jason']
punc = ['.',',']
wordbank = [names, verbs, nouns]
keywords = ['NAME', 'VERB', 'NOUN']

def madlibify(str):
	complete_str = ''
	elements = str.split(" ") # splits the sentence into individual strings
	name = None # variable for if a random name has already been generated
	for index in elements:
		str_punc = ''
		# checks if the current element is a keyword (includes case where current element has punctuation)
		if index in keywords or index[0:-1] in keywords:
			# checks if the current element has punctuation
			if index[-1] in punc:
				str_punc = index[-1] # stores the punctuation
				index = index[0:-1] # stores the string without the punctuation
			# determines which keyword the current element is
			for y in range(len(keywords)-1,-1,-1):
				if index == keywords[y]:
					index = random.choice(wordbank[y]) # randomly selects a word from the appropriate list
					# checks if the keyword is "NAME"
					if y == 0:
						if not name:
							name = index # if name hasn't been stored, store it
						index = name
					break
		complete_str += (index + str_punc + ' ')
	return complete_str

print(madlibify(sen))