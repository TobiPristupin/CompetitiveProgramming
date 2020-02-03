grids = [
    {(0, 0), (0, 1), (0, 2), (1, 0), (1, 1), (1, 2), (2, 0), (2, 1), (2, 2)},
    {(3, 0), (3, 1), (3, 2), (4, 0), (4, 1), (4, 2), (5, 0), (5, 1), (5, 2)},
    {(6, 0), (6, 1), (6, 2), (7, 0), (7, 1), (7, 2), (8, 0), (8, 1), (8, 2)},
    {(0, 3), (0, 4), (0, 5), (1, 3), (1, 4), (1, 5), (2, 3), (2, 4), (2, 5)},
    {(3, 3), (3, 4), (3, 5), (4, 3), (4, 4), (4, 5), (5, 3), (5, 4), (5, 5)},
    {(6, 3), (6, 4), (6, 5), (7, 3), (7, 4), (7, 5), (8, 3), (8, 4), (8, 5)},
    {(0, 6), (0, 7), (0, 8), (1, 6), (1, 7), (1, 8), (2, 6), (2, 7), (2, 8)},
    {(3, 6), (3, 7), (3, 8), (4, 6), (4, 7), (4, 8), (5, 6), (5, 7), (5, 8)},
    {(6, 6), (6, 7), (6, 8), (7, 6), (7, 7), (7, 8), (8, 6), (8, 7), (8, 8)}
]

def possible_values(board, row, col):
    values = {i for i in range(1, 10)}
    for x in range(9):
        values.discard(board[x][col])
        values.discard(board[row][x])
    for grid in grids:
        if (row, col) in grid:
            for (r, c) in grid:
                values.discard(board[r][c])
            break
    return values

def solve(board, queries, col=0, query=0):
    if query == len(queries):
        for i in range(len(queries)):
            print("".join(map(str, board[queries[i]])))
        exit()
    
    if col == 9:
        solve(board, queries, 0, query+1)

    row = queries[query]
    if board[row][col] != 0:
        solve(board, queries, col+1, query)
    elif board[row][col] == 0:
        for value in possible_values(board, row, col):
            board[row][col] = value
            solve(board, queries, col+1, query)
            board[row][col] = 0

board = [list(map(int, input().split(","))) for _ in range(9)]
queries = [int(input()) - 1 for _ in range(5)]
solve(board, queries)