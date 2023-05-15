def is_safe(board, row, col):
    N = len(board)    
    # Check the same column and diagonals
    for i in range(row):
        if board[i] == col or board[i] - i == col - row or board[i] + i == col + row:
            return False
    return True

def solve_n_queens_util(board, row, solutions):
    # Base case: all queens have been placed
    N = len(board)
    if row == N:
        solutions.append(board.copy())
        return
    
    # Recursive case: try placing a queen in each column of the current row
    for col in range(N):
        if is_safe(board, row, col):
            board[row] = col
            solve_n_queens_util(board, row + 1, solutions)

def solve_n_queens(N):
    board = [-1] * N
    solutions = []
    solve_n_queens_util(board, 0, solutions)
    return solutions

# Driver code
N = 4
solutions = solve_n_queens(N)

print(f"Number of solutions for N = {N}: {len(solutions)}")
for idx, solution in enumerate(solutions):
    print(f"Solution {idx + 1}:")
    for row, col in enumerate(solution):
        print(f"Queen at ({row}, {col})")
    print()
