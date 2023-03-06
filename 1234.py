while True:
    try:
        sentence = input()

        dancing_sentence = ""

        should_be_upper = True

        for letter in sentence:
            if letter.isspace():
                dancing_sentence += letter
            elif should_be_upper:
                dancing_sentence += letter.upper()
                should_be_upper = False
            else:
                dancing_sentence += letter.lower()
                should_be_upper = True

        print(dancing_sentence)
    
    except EOFError:
        break
