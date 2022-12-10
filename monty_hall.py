number_of_games = int(input())
array_input = []
number_of_games_won = 0

for _ in range(number_of_games):
    new_simulation = int(input())
    array_input.append(new_simulation)

for x in array_input:
    if x != 1:
        number_of_games_won += 1

print(number_of_games_won)