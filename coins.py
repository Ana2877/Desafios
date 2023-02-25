def countCurrency(amount_integer, amount_coin):
    notes = [100, 50, 20, 10, 5, 2]
    coins = [100, 50, 25, 10, 5, 1]
    notesCount = {}
    coinsCount = {}
	
    for note in notes:
        if amount_integer >= note:
            notesCount[note] = amount_integer//note
            amount_integer = amount_integer % note
        else:
            notesCount[note] = 0

    amount_coin += amount_integer*100

    print ("NOTAS:")
    for key, val in notesCount.items():
        formated_key = "{:.2f}".format(key)
        print(f"{val} nota(s) de R$ {formated_key}")

    for coin in coins:
        if amount_coin >= coin:
            coinsCount[coin] = amount_coin//coin
            amount_coin = amount_coin % coin
        else:
            coinsCount[coin] = 0

			
    print ("MOEDAS:")
    for key, val in coinsCount.items():
        formated_key = "{:.2f}".format(key/100)
        print(f"{val} moeda(s) de R$ {formated_key}")

# Driver code
amount = float(input())
amount += 0.001

amount_integer = int(amount);

amount_coin = int((amount*100) - (amount_integer*100))

countCurrency(amount_integer, amount_coin)
