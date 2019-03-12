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

def build_wc_dict(wordlist): # homework
    '''
    input: wordList - list representing words
    output: a dictionary with keys for words and values
             of the words that occur after the word
    '''
    d={}
    for i in range(0,len(wordlist)-1):
        d.setdefault(wordlist[i],list())
        d[wordlist[i]].append(wordlist[i+1])
    return d

def bwcff(f):
    """
    input: f - string representing a filename
    returns: a dictionary with keys for words and values
             of the words that occur after the word
    """
    text = open(f).read()
    l=[]
    for w in text.split():
        w = w.lower()
        w = remove_non_alpha(w)
        l.append(w)
    d = build_wc_dict(l)
    return d


d = bwcff("hamlet.txt")
k = list(d.keys())
v = list(d.values())
for i in range(len(k)):
     print(k[i], ":", v[i])

# BUG - doesn't seperate words that are seperated by hyphons and doesn't include contractions
