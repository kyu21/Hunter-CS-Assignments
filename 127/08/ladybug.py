import sys

def solve(str):
	hasEmpty = False
	unhappy = False
	enoughColors = True
	colorCount = {}

	for index, value in enumerate(str):
		if value == "_":
			hasEmpty = True
		else:
			if ((index == 0 or str[index-1]) != value ) and ((index == len(str)-1 or str[index+1]) != value):
				unhappy = True
			if (value not  in colorCount.keys()):
				colorCount[value] = 0
			colorCount[value] = colorCount.get(value) + 1
	for count in colorCount.values():
		if count < 2:
			enoughColors = False
	return (not unhappy) or (hasEmpty and enoughColors)

Q = int(input().strip())
for a0 in range(Q):
    n = int(input().strip())
    b = input().strip()
    if solve(b):
    	print("YES")
    else:
    	print("NO")