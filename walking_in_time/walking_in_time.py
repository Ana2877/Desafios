def can_go_back_to_present(a, b, c):
    if (a - b == 0): return "S" 
    if (a - c == 0): return "S" 
    if (c - b == 0): return "S" 
    if (a - b - c == 0): return "S" 
    if (b - a - c == 0): return "S" 
    if (c - a - b == 0): return "S"

    return "N" 


if "__main__":
    input_string = input()
    a, b, c = input_string.split(' ')
    print(can_go_back_to_present(int(a), int(b), int(c)))
