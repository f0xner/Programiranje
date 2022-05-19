import sys
targer_points=0
games_played = 0
sUm = 0
try:
    target_points = int(sys.argv[3])
    games_played = int(sys.argv[1])
    sUm = int(sys.argv[2])
except:
    print("Target points: ",end="")
    target_points = int(input(""))
    print("Games played: ",end="")
    games_played = int(input(""))
    print("Current sum  played: ",end="")
    sUm = int(input(""))
def calc_num_iters(games_played,sUm,target_points):
    c_sum = sUm
    iters = 0
    point = 2**games_played
    while c_sum <= target_points:
        iters+=1
        c_sum += point
        point*=2
    print(f"Games to play {iters}")
    print(f"Total points {c_sum}")
calc_num_iters(games_played,sUm,target_points)
