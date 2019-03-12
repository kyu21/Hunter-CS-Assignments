TRIPLE_WORD_SCORE = ((0, 0), (7, 0), (14, 0), (0, 7),
                     (14, 7), (0, 14), (7, 14), (14, 14))
DOUBLE_WORD_SCORE = ((1, 1), (2, 2), (3, 3), (4, 4), (1, 13), (2, 12), (3, 11), (4, 10),
                     (13, 1), (12, 2), (11, 3), (10, 4), (13, 13), (12, 12), (11, 11), (10, 10), (7, 7))
TRIPLE_LETTER_SCORE = ((1, 5), (1, 9), (5, 1), (5, 5), (5, 9),
                       (5, 13), (9, 1), (9, 5), (9, 9), (9, 13), (13, 5), (13, 9))
DOUBLE_LETTER_SCORE = ((0, 3), (0, 11), (2, 6), (2, 8), (3, 0), (3, 7), (3, 14), (6, 2), (6, 6), (6, 8), (6, 12), (
    7, 3), (7, 11), (8, 2), (8, 6), (8, 8), (8, 12), (11, 0), (11, 7), (11, 14), (12, 6), (12, 8), (14, 3), (14, 11))


def make_scrabble_board():
    board = []
    for i in range(15):
        line = []
        for i in range(15):
            line.append('_')
        board.append(line)

    for r, c in TRIPLE_WORD_SCORE:
        board[r][c] = 'T'

    for r, c in DOUBLE_WORD_SCORE:
        board[r][c] = 'D'

    for r, c in TRIPLE_LETTER_SCORE:
        board[r][c] = 't'

    for r, c in DOUBLE_LETTER_SCORE:
        board[r][c] = 'd'
    return board


def print_board(b):
    for line in b:
        print(' '.join(line))


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


def add_word_across(board, word, r, c):
    answer = 0
    cur_col = c
    word_multipler = 1
    if ((len(board[r]) - c) < len(word)):
        print("''''''''''Invalid Word'''''''''''")
        print_board(board)
        return 0
    for char in word:
        letter_multipler = 1
        if board[r][cur_col] == 'T':
            word_multipler *= 3
        if board[r][cur_col] == 'D':
            word_multipler *= 2
        if board[r][cur_col] == 't':
            letter_multipler = 3
        if board[r][cur_col] == 'd':
            letter_multipler = 2
        board[r][cur_col] = char
        answer += (score(char) * letter_multipler)
        cur_col += 1
    answer *= word_multipler
    print("'''''''''''''''''''''''''''''''''''")
    print_board(board)
    return answer


def add_word_down(board, word, r, c):
    answer = 0
    cur_row = r
    word_multipler = 1
    if ((len(board) - r) < len(word)):
        print("''''''''''Invalid Word'''''''''''")
        print_board(board)
        return 0
    for char in word:
        letter_multipler = 1
        if board[cur_row][c] == 'T':
            word_multipler *= 3
        if board[cur_row][c] == 'D':
            word_multipler *= 2
        if board[cur_row][c] == 't':
            letter_multipler = 3
        if board[cur_row][c] == 'd':
            letter_multipler = 2
        board[cur_row][c] = char
        answer += (score(char) * letter_multipler)
        cur_row += 1
    answer *= word_multipler
    print("'''''''''''''''''''''''''''''''''''")
    print_board(board)
    return answer


def print_score_word(direction, word, r, c):
    board = make_scrabble_board()
    if direction == 'across':
        print("Word:", word, "\t", "Score:",
              add_word_across(board, word, r, c), "\n")
    if direction == 'down':
        print("Word:", word, "\t", "Score:",
              add_word_down(board, word, r, c), "\n")


print_score_word('across', "hello", 7, 7)
print_score_word('across', "hi", 7, 7)
print_score_word('down', "hello", 7, 7)
print_score_word('down', "hi", 7, 7)
print_score_word('across', "asdqwessd", 7, 7)
print_score_word('down', "asdqwessd", 7, 7)
print_score_word('across', 'hunter', 1, 5)
