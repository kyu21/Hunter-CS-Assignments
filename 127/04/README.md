CSCI 12700

09/25/2017

HW#4

1. Madlibs
>Create a story and put breaks in between the story for random nouns, verbs or and adjectives.
>1. Replace all NOUNS, VERB, and NAME with a random element from a given list
>2. As a challenge, try to keep the NAME same throughout
>3. Don't have to worry about punctuation

2. Collatz Sequence
>Write a function named collatz() that has one parameter named number. If number is even, then collatz() should print number / 2 and return this value. If number is odd, then collatz() should print and return 3 * number + 1. Then write a program that lets the user type in an integer and that keeps calling collatz() on that number until the function returns the value 1.

3. Comma Code
>Write a function that takes a list value as an argument and returns a string with all the items separated by a comma and a space, with and inserted before the last item. For example, passing the previous spam list to the function would return 'apples, bananas, tofu, and cats'. But your function should be able to work with any list value passed to it.

4. Character Picture Grid
>Say you have a list of lists where each value in the inner lists is a one-character string, like this:
```python
grid = [['.', '.', '.', '.', '.', '.'],
        ['.', 'O', 'O', '.', '.', '.'],
        ['O', 'O', 'O', 'O', '.', '.'],
        ['O', 'O', 'O', 'O', 'O', '.'],
        ['.', 'O', 'O', 'O', 'O', 'O'],
        ['O', 'O', 'O', 'O', 'O', '.'],
        ['O', 'O', 'O', 'O', '.', '.'],
        ['.', 'O', 'O', '.', '.', '.'],
        ['.', '.', '.', '.', '.', '.']]
```
>You can think of grid[x][y] as being the character at the x- and y-coordinates of a “picture” drawn with text characters. The (0, 0) origin will be in the upper-left corner, the x-coordinates increase going right, and the y-coordinates increase going down.
>Copy the previous grid value, and write code that uses it to print the image.
```
..OO.OO..
.OOOOOOO.
.OOOOOOO.
..OOOOO..
...OOO...
....O....
```