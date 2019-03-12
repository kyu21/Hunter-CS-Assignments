import random

def remove_non_alpha(w):
    """
    input: w - string representing a "word"
    output: the string with non alpha chars removed
    """
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

def build_word_chain_dict(wordlist):
    d={}
    for i in range(1,len(wordlist)):
        w1 = wordlist[i-1]
        w2 = wordlist[i]
        d.setdefault(w1,[])
        d[w1].append(w2)
        
    return d

def bwcff(f):
    """
    input: f - string representing a filename
    returns: a dictionary with keys for words and values
             of the number of times each word occursb
    """
    text = open(f).read()
    l=[]
    for w in text.split():
        w = w.lower()
        w = remove_non_alpha(w)
        l.append(w)
    d = build_word_chain_dict(l)
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


hamlet = bwcff("hamlet.txt")
psalms = bwcff("psalms.txt")
sonnets = bwcff("sonnets.txt")