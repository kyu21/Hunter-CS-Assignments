CSCI 12700

09/11/2017

HW#1

1. Write a program named bondify.py. It should assign a string to a variable on the first line. The string will be in the form Firstname Lastname" so for example it could be "James Bond." Note-->
that there is no period in the string but grammar rules dictate that the punctuation ALWAYS goes in the quotes and I can't break the habit. The program will make a new string that transforrms the original into something in the form: "Lastname, Firstname Lastname" or in the example case "Bond, James Bond." This should work for any string value.
2. Write a program named nameify.py It should assign a string in the first line and the string will be in the form "word1 word2" where both words are lower case. The program should assign a new string where each of the two words are capitalized.
3. Create a file named answer and write down what you think this code does without running it and without looking anything up:
```number = input()-->
number = 12
i = 2
while i < number:
	if number % i == 0:
		print (i)
	i = i + 1
