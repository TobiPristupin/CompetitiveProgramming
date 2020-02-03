import sys
from copy import deepcopy

def alive_neighbors(board, r, c):
    count = 0
    pos = [(r+1, c), (r-1, c), (r, c+1), (r, c-1), (r+1, c+1), (r-1, c-1), (r+1, c-1), (r-1, c+1)]
    for (row, col) in pos:
        if row >= 0 and row < 10 and col >= 0 and col < 10:
            count += board[row][col] == "A"
    return count

for line in sys.stdin:
    state = [
        list("ADDDDDDDDD"),
        list("ADDDDDDDDD"),
        list("DDDADDDDDD"),
        list("DDDDADDDDD"),
        list("DDADDADDDA"),
        list("DADAADDADD"),
        list("DDADDDDDAA"),
        list("DADDDDDDDA"),
        list("ADDDDDDDDA"),
        list("DDDDDDDDDA")
    ]

    line = list(map(int, line.split(",")))
    births = line.pop(0)
    birth = [line.pop(0) for i in range(births)]
    alives = line.pop(0)
    alive = [line.pop(0) for i in range(alives)]
    gens = line.pop(0)
    r, c = (line.pop(0)-1, line.pop(0)-1)
    
    print(state[r][c], end="")
    prev_state = state

    for g in range(gens):
        board = deepcopy(prev_state)
        for row in range(10):
            for col in range(10):
                if prev_state[row][col] == "A":
                    if alive_neighbors(prev_state, row, col) not in alive:
                        board[row][col] = "D"
                elif prev_state[row][col] == "D":
                    if alive_neighbors(prev_state, row, col) in birth:
                        board[row][col] = "A"

        print(board[r][c], end="")
        prev_state = board

    print()
    