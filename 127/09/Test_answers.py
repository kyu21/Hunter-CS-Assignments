# Problem 1
def divide(A, B, u):
    if A == 0 or B == 0 or u == 0:  # handles case where any of the numbers are 0
        return 0
    return int((u * B) // A)

print(divide(5, 10, 1))
print(divide(1, 2, 1))
print(divide(1, 3, 3.5))
print(divide(3, 2, 7))
print()

# Problem 2
def encode(s):
    if len(s) == 0:  # this if statement was added after submission to deal with empty string case
        return []
    previous_char = s[0]
    current_run = 0
    answer = []
    for char in s:
        if char != previous_char:
            if current_run == 1:
                answer.append(previous_char)
            else:
                answer.append(current_run)
                answer.append(previous_char)
            previous_char = char
            current_run = 1
        else:
            current_run += 1
    answer.append(current_run)
    answer.append(previous_char)
    return answer

print(encode("aaaaa"))
print(encode("bbaaa"))
print(encode("aabcccdeeeeaaa"))
print(encode(""))
print()

# Problem 3
def score(w):
    score = 0
    letter_value = {1: "AEIOULNRST", 2: "DG", 3: "BCMP",
                    4: "FHVWY", 5: "K", 8: "JX", 10: "QZ"}
    w = w.upper()
    for char in w:
        for value, letters in letter_value.items():
            for letter in letters:
                if char == letter:
                    score += value
    return score

print(score("hello"))
print(score("kun"))  # expect 7
print(score("computer"))  # expect 3,1,3,3,1,1,1,1 14
print(score("hunter"))  # expect 4,1,1,1,1,1 9
print(score(""))
