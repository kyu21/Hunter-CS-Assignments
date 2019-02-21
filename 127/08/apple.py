import sys

s,t = input().strip().split(' ') # inclusive range
s,t = [int(s),int(t)]
a,b = input().strip().split(' ') # position of trees - a is apple, b is orange
a,b = [int(a),int(b)]
m,n = input().strip().split(' ') # number of fruits fallen
m,n = [int(m),int(n)]
apple = [int(apple_temp) for apple_temp in input().strip().split(' ')] # position of apples
orange = [int(orange_temp) for orange_temp in input().strip().split(' ')] # positions of oranges

def num_fruit_on_house(s, t, tree_pos, fruit_dist):
	num_fruit = 0 
	for fruit in fruit_dist:
		if (tree_pos + fruit) >= s and (tree_pos + fruit) <= t:
			num_fruit += 1
	return num_fruit

apple_num = num_fruit_on_house(s,t,a,apple)
orange_num = num_fruit_on_house(s,t,b,orange)

print(apple_num)
print(orange_num)