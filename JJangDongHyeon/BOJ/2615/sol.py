import sys

sys.stdin = open('input.txt')


def check_five(start_x, start_y, number):
    global winner, winner_x, winner_y
    for i in range(len(dx)):
        count = 1  # 자기 자신 포함
        x, y = start_x, start_y
        for j in range(1, 5):
            nx = x + dx[i] * j
            ny = y + dy[i] * j
            if not (0 <= nx < N and 0 <= ny < N): break
            if board[nx][ny] != number: break
            count += 1

        if count == 5:
            prev_x, prev_y = start_x - dx[i], start_y - dy[i]
            next_x, next_y = start_x + dx[i] * 5, start_y + dy[i] * 5

            if (0 <= prev_x < N and 0 <= prev_y < N and board[prev_x][prev_y] == number):
                continue
            if (0 <= next_x < N and 0 <= next_y < N and board[next_x][next_y] == number):
                continue

            winner = number
            winner_x, winner_y = start_x + 1, start_y + 1
            print(winner)
            print(winner_x, winner_y)
            exit()


N = 19
board = [list(map(int, input().split())) for _ in range(N)]

dx = [0, 1, 1, -1]
dy = [1, 0, 1, 1]

winner = 0
winner_x, winner_y = 0, 0
for i in range(N):
    for j in range(N):
        if board[i][j] != 0:
            check_five(i, j, board[i][j])

print(winner)