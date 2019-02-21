import random

def remove_non_alpha(w):
    result=""
    for l in w:
        if l.isalpha():
            result = result + l
    return result

def bwcd(wordlist):
    d={}
    for w in wordlist:
        d.setdefault(w,0)
        d[w] = d[w] + 1
    return d

def build_word_chain_dict(wordlist, length):
    d={}
    for i in range(0,len(wordlist)-length):
        key = (" ".join(wordlist[i:i+length]))
        value = wordlist[i+length]
        d.setdefault(key,[])
        d[key].append(value)
    return d

def bwcff(f, length):
    text = open(f).read()
    l=[]
    for w in text.split():
        w = w.lower()
        w = remove_non_alpha(w)
        l.append(w)
    d = build_word_chain_dict(l, length)
    return d

def generate_text(d,start_word,length=50):
    wordlist = []
    next = start_word
    for i in range(length):
        if next not in d:
            break
        wordlist.append(next)
        next = random.choice(d[next])
    return " ".join(wordlist)


hamlet2 = bwcff("hamlet.txt" , 2)
hamlet3 = bwcff("hamlet.txt", 3)
# psalms = bwcff("psalms.txt")
# sonnets = bwcff("sonnets.txt")

for key, value in hamlet2.items():
    print (key, ":", value)

print("\n===============================================================\n")

for key, value in hamlet3.items():
    print (key, ":", value)