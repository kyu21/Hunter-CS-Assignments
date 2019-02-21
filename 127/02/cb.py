def string_times(str, n):
  return str*n
def front_times(str, n):
  return str[:3]*n
def string_bits(str):
    newStr= ''
    for x in range(0,len(str),2):
        newStr += str[x]
    return newStr
def lone_sum(a,b,c):
    if (a==b):
        if (a==c):
            return 0
        return c
    if (a==c):
        return b
    if (b==c):
        return a
    return a+b+c
def string_splosion(str):
  newStr=''
  for i in range(1,len(str)+1):
    newStr += str[0:i]
  return newStr
def caught_speeding(speed, is_birthday):
  limit1,limit2=61,80
  if is_birthday:
    limit1+=5
    limit2+=5
  if speed < limit1:
    return 0
  if speed > limit2:
    return 2
  return 1
def cigar_party(cigars, is_weekend):
  if cigars < 40:
    return False
  elif not is_weekend and cigars > 60:
    return False
  return True

print(string_times('Hi', 2) + "\n" +
front_times('Chocolate', 2) + "\n" +
string_bits('Hello') + "\n" +
str(lone_sum(1, 2, 3)) + "\n" +
string_splosion('Code') + "\n" +
str(cigar_party(30, False)) + "\n" +
str(caught_speeding(60, False)))