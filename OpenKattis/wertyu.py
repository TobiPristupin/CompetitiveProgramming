import fileinput

keyboard = list("`1234567890-=QWERTYUIOP[]\ASDFGHJKL;'ZXCVBNM,./")

for line in fileinput.input():
    line = line.replace("\n", "")
    s = "".join([keyboard[keyboard.index(char) - 1] if char != " " else char for char in line])
    print(s)
