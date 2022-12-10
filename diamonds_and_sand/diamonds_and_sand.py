DIAMOND_LEFT = '<'
DIAMOND_RIGHT = '>'

def get_number_of_diamonds_from(list_of_diamonds_and_sand):
    diamond_left_count = 0
    diamond_right_count = 0

    for diamond_and_sand in list_of_diamonds_and_sand:
        if diamond_and_sand == DIAMOND_LEFT:
            diamond_left_count += 1

        elif diamond_and_sand == DIAMOND_RIGHT and diamond_right_count < diamond_left_count:
            diamond_right_count += 1

   
    return diamond_left_count if diamond_left_count < diamond_right_count else diamond_right_count


if "__main__":
    number_of_test_cases = input()

    for _ in range(int(number_of_test_cases)):
        list_of_diamonds_and_sand = input()
        number_of_diamonds = get_number_of_diamonds_from(list_of_diamonds_and_sand)

        print(number_of_diamonds)