# Assignment 2
Miguel Acero
Professor Stamos
4/7/18


## Background

     This assignment was coded by Miguel Acero for CSCI335. The main purpose of this assigment is to learn and compare AVL Trees as compared with the binary search trees we have already learned. There were many issues writing this code, so i commented out a lot of the cout debugging codes I wrote. 

## OUTPUT/Concerns
This is my Linux Lab results.
for part 2a, it properly parallels the intended results as indicated in output_part2a.tdxt
however in part2b there is a slight deviance. I believe there should be an error margin but
the calculations should be correct!

```
Miguel.Acero81@cslab2:~/DNA-Trees$ ./query_tree rebase210.txt BST < input_part2a.txt 
Input filename is rebase210.txt
Type of tree is BST
AbsI 
AanI PsiI 
Not Found
Miguel.Acero81@cslab2:~/DNA-Trees$ ./test_tree rebase210.txt sequences.txt AVL
Input file is rebase210.txt, and sequences file is sequences.txt
Type of tree is AVL
2: 566
3a: 7.38
3b: 0.807
4a: 420
4b: 8.15
5a: 161
5b: 9.2
6a: 405
6b: 6.9
6c: 0.8
Miguel.Acero81@cslab2:~/DNA-Trees$ ./test_tree rebase210.txt sequences.txt BST
Input file is rebase210.txt, and sequences file is sequences.txt
Type of tree is BST
2: 566
3a: 11.3
3b: 1.23
4a: 420
4b: 11
5a: 161
5b: 12
6a: 405
6b: 11
6c: 1.3
```

## Code
As indicated by the assignment PDF, I role modeled most of my functions as reflected by the pseudo code
```cpp
while(getline(inFile, db_line)) {
    string enzymeAcronym = GetEnzymeAcronym(db_line);
    string recogSequence;
    // cout << enzymeAcronym << endl;
    while (GetNextRecognitionSequence(db_line, recogSequence)) {
    // cout << db_line << endl << recogSequence;
      SequenceMap seqMap (recogSequence, enzymeAcronym);
      a_tree.insert(seqMap);
    }
  }
```

## Compilation

Tested and compiled on Linux Lab Computers on 4/7/18

Compilation process is pretty simple, as instructed I inputed
```
make all
```
or if you want to compile seperately
```
make test_query
make test_tree
```
and then 

## Bugs

1.  Sometimes