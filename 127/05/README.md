CSCI 12700

09/28/2017

HW#5

1. Encode Letter
>Write a routine encode_letter(c,r) which takes a letter (a-z) and returns a letter that is it rotated by r positions. So, rotate_letter('a',3) would return 'd' and roate_letter('y',3) would return 'b'.

2. Encode String
>Write a routine encode_string(s,r) which return a new string which is the original string with each letter rotated. It should not rotate non-letters, those should just be copied over to the new string. Upper case letters should be rotated. You can convert them to lower case, rotate then convert back or you could make your rotate_letter routine handle it directly.

3. Full Encode
>Write a routine full_encode(s) which takes a string and returns a string representing all the valid rotations, one per line (embed the \n to get a newline).