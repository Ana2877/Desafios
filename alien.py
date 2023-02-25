while True:
    try:
        user_input = input()

        possible_sequences = ["BS", "CF", "FC", "SB"]

        connections = 0
        should_continue = True
        count = 0

        while (should_continue and len(user_input) > 1):
            should_continue = False
            for sequence in possible_sequences:
                count = user_input.count(sequence)
                connections += count
                if count > 0:
                    should_continue = True
                user_input = user_input.replace(sequence, "")

        print(connections)

    except EOFError:
        break
