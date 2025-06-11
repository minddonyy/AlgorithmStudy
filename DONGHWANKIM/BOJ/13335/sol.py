import sys
sys.stdin = open("input.txt", "r")

TC = int(input())

for tc in range(TC) :
    n, w, L = map(int, input().split())
    trucks = list(map(int, input().split()))
    
    result = 1
    passtruck = 0
    
    for tnum in range(len(trucks)): 
        if tnum == passtruck :
            time = 1
            onbidge = trucks[tnum]
            passtruck += 1
        
            for more in range(tnum + 1, len(trucks)):
                if onbidge + trucks[more] <= w :
                    onbidge += trucks[more]
                    time += 1
                    passtruck += 1
                else:
                    break
        result += time + (L - 1)
    
    print(result)