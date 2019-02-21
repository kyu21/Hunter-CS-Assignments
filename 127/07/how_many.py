arr = [3,2,2,1,3,4,5,4,3,4,3]

def freq(n,l):
	count = 0
	for num in l:
		if num == n:
			count+= 1
	return count

def min(l):
	min_num = l[0]
	for i in l:
		if i < min_num:
			min_num = i
	return min_num

def mode(l):
	largest_count = -1
	for i in l:
		if freq(i,l) > largest_count:
			largest_count = freq(i,l)
			mode = i
	return mode

print("Frequency of 3:",freq(3,arr))
print("Minimum value in list:",min(arr))
print("Mode of list:",mode(arr))