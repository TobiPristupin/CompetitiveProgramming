import string

def rotate(string, rotation):
    return "".join([alphabet[(alphabet.index(char) + rotation) % len(alphabet)] for char in string])

def sum_chars(string):
    return sum([alphabet.index(char)for char in string])


alphabet = list(string.ascii_uppercase)
message = input()
half1, half2 = message[:len(message) // 2], message[len(message) // 2:] 
half1, half2 = rotate(half1, sum_chars(half1)), rotate(half2, sum_chars(half2))
output = "".join([rotate(c1, sum_chars(c2)) for c1, c2 in zip(half1, half2)])
print(output)



