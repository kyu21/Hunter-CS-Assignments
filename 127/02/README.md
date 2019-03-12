CSCI 12700

09/14/2017

HW#2

1. Given a string and a non-negative int n, return a larger string that is n copies of the original string.
```
string_times('Hi', 2) → 'HiHi'
string_times('Hi', 3) → 'HiHiHi'
string_times('Hi', 1) → 'Hi'
```
http://codingbat.com/prob/p193507

2. Given a string and a non-negative int n, we'll say that the front of the string is the first 3 chars, or whatever is there if the string is less than length 3. Return n copies of the front;
```
front_times('Chocolate', 2) → 'ChoCho'
front_times('Chocolate', 3) → 'ChoChoCho'
front_times('Abc', 3) → 'AbcAbcAbc'
```
http://codingbat.com/prob/p165097

3. Given a string, return a new string made of every other char starting with the first, so "Hello" yields "Hlo".
```
string_bits('Hello') → 'Hlo'
string_bits('Hi') → 'H'
string_bits('Heeololeo') → 'Hello'
```
http://codingbat.com/prob/p113152

4. Given 3 int values, a b c, return their sum. However, if one of the values is the same as another of the values, it does not count towards the sum.
```
lone_sum(1, 2, 3) → 6
lone_sum(3, 2, 3) → 2
lone_sum(3, 3, 3) → 0
```
http://codingbat.com/prob/p143951

5. Given a non-empty string like "Code" return a string like "CCoCodCode".
```
string_splosion('Code') → 'CCoCodCode'
string_splosion('abc') → 'aababc'
string_splosion('ab') → 'aab'
```
http://codingbat.com/prob/p118366

6. When squirrels get together for a party, they like to have cigars. A squirrel party is successful when the number of cigars is between 40 and 60, inclusive. Unless it is the weekend, in which case there is no upper bound on the number of cigars. Return True if the party with the given values is successful, or False otherwise.
```
cigar_party(30, False) → False
cigar_party(50, False) → True
cigar_party(70, True) → True
```
http://codingbat.com/prob/p195669

7. You are driving a little too fast, and a police officer stops you. Write code to compute the result, encoded as an int value: 0=no ticket, 1=small ticket, 2=big ticket. If speed is 60 or less, the result is 0. If speed is between 61 and 80 inclusive, the result is 1. If speed is 81 or more, the result is 2. Unless it is your birthday -- on that day, your speed can be 5 higher in all cases.
```
caught_speeding(60, False) → 0
caught_speeding(65, False) → 1
caught_speeding(65, True) → 0
```
http://codingbat.com/prob/p137202
