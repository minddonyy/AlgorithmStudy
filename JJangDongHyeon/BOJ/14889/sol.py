import sys
sys.stdin = open('input.txt')

def comb(idx, selected):

    if len(selected) == one_team_count:
        global min_synergy
        if 0 not in selected: return #중복 제거
        a_team = selected
        b_team = [i for i in range(person_count) if i not in a_team]
        # print('a_team :', a_team, 'b_team :', b_team)
        a_synergy, b_synergy = get_synergy(a_team), get_synergy(b_team)
        final_synergy = abs(a_synergy - b_synergy)
        min_synergy = min(min_synergy, final_synergy)

    for i in range(idx, person_count):
        comb(i + 1, selected + [i])

def get_synergy(team):
    synergy = 0
    for i in range(len(team)):
        for j in range(len(team)):
            if i == j : continue
            synergy += board[team[i]][team[j]]
    return synergy

person_count = int(input())

one_team_count = person_count // 2
board = [list(map(int, input().split())) for _ in range(person_count)]
# print(board)
min_synergy = 99999999
comb(0, [])
print(min_synergy)