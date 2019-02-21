def piglatinify(s):
    vowels = 'aeiou'
    if s[0] not in vowels:
        s = s[1:] + s[0]
    return s + 'ay'

print(piglatinify("latin"))