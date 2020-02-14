digit = {
    "YYYYYYN": 0,
    "NYYNNNN": 1,
    "YYNYYNY": 2,
    "YYYYNNY": 3,
    "NYYNNYY": 4,
    "YNYYNYY": 5,
    "YNYYYYY": 6,
    "YYYNNNN": 7,
    "YYYYYYY": 8,
    "YYYYNYY": 9
}

found = False
lights = []
possibly_burnt = []

def solve(prev=-1, i=-1, j=0):
    global found, lights, possibly_burnt
    if found:
        return

    if i == len(lights) - 1:
        print("MATCH")
        found = True
        return

    if j == 7:
        code = "".join(lights[i+1])
        if code in digit:
            if prev == -1 or digit[code] == prev - 1:
                solve(digit[code], i + 1, 0)
        return

    if possibly_burnt[j][i + 1]:
        initial = lights[i + 1][j]
        lights[i + 1][j] = "Y"
        solve(prev, i, j + 1)
        lights[i + 1][j] = "N"
        solve(prev, i, j + 1)
        lights[i + 1][j] = initial
    else:
        solve(prev, i, j + 1)


n = int(input())
while n != 0:
    lights = [list(input()) for _ in range(n)]
    found = False
    possibly_burnt = []

    for c in range(len(lights[0])):
        last_y = -1
        for r in range(len(lights)):
            if lights[r][c] == "Y":
                last_y = r

        arr = [False if i <= last_y else True for i in range(len(lights))]
        possibly_burnt.append(arr)

    solve()
    if not found:
        print("MISMATCH")

    n = int(input())