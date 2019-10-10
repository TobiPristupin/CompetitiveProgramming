m = int(input())
ops = ["+", "-", "//", "*"]
for _ in range(m):
    n = int(input())
    found = False
    for a in ops:
        for b in ops:
            for c in ops:
                expr = "4 " + a + " 4 " + b + " 4 " + c + " 4 "
                if not found and eval(expr) == n:
                    expr = expr.replace("//", "/")
                    print(expr + "= " + str(n))
                    found = True
    if not found:
        print("no solution")
