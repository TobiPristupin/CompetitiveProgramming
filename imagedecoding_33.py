inp = input()

while True:
    if inp == "0":
        break
    
    for j in range((int(inp))):
        line = input()
        char = line[0]
        runs = list(map(int, line[1:].split()))

        if j == 0:
            length = sum(runs)
            error = False
        elif length != sum(runs):
            error = True


        for i in runs:
            for p in range(i):
                print(char, end="")
            char = "." if char == "#" else "#"
        print()

    print("Error decoding image") if error else None
    inp = input()
    print() if inp != "0" else None

            