import csv, random as r

def inverse_index(file, word):
	info_dict = {}
	index_dict = {word: []}
	try:
		with open(file, encoding="utf8") as f:
			all_ppl = csv.DictReader(f)
			for header in all_ppl.fieldnames[:-1]:
				info_dict.setdefault(header, [])
			for row in all_ppl:
				for category, info in row.items():
					if category != '':
						info_dict[category].append(info)
			for i in range(len(info_dict['Execution #'])):
				if word in info_dict['Last Statement'][i]:
					index_dict[word].append(", ".join([info_dict['Last Name'][i],info_dict['First Name'][i]]))
		return index_dict
	except FileNotFoundError as e:
		return None

words = ['hello', 'I', 'bye', 'sorry']
for word in words:
	iindex = inverse_index('offenders-clean.csv', word)
	print(''.join(iindex.keys()),":","'".join([str(i)[1:-1] for i in iindex.values()]), end = '\n'+ '='*r.randint(75,150) +'\n')