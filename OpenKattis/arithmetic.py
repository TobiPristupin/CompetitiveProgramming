import sys

for line in sys.stdin:
    line = line.replace("\n", "")
    if line == "--":
        break
    print(hex(int(line, 8))[2:])
