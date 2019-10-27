import math

r, c = map(int, input().split())

total = math.pi * (r**2)
cheese = math.pi * ((r-c)**2)
print(cheese / total * 100)