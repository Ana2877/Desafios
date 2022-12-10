def get_the_queen_positions():
    x1, y1, x2, y2 = input().split(' ')
    return int(x1), int(y1), int(x2), int(y2)

def is_last_value(x1, y1, x2, y2):
    return x1 == y1 == x2 == y2 == 0

def is_the_position_equal(x1, y1, x2, y2):
    return (x1 == x2) and (y1 == y2)

def is_at_the_same_line(x1, y1, x2, y2):
    return (x1 == x2) or (y1 == y2)

def is_at_the_same_diagonal(x1, y1, x2, y2):
    return (abs(x2 - x1) - abs(y2 - y1)) == 0

def get_number_of_moves_to_switch_positions(x1, y1, x2, y2):

    if (is_the_position_equal(x1, y1, x2, y2)):
        return 0

    elif (is_at_the_same_line(x1, y1, x2, y2)):
        return 1

    elif (is_at_the_same_diagonal(x1, y1, x2, y2)):
        return 1

    return 2


if "__main__":
    

    while (True):
        x1, y1, x2, y2 = get_the_queen_positions()

        if (is_last_value(x1, y1, x2, y2)):
            break

        number_of_moves = get_number_of_moves_to_switch_positions(x1, y1, x2, y2)
        print(number_of_moves)