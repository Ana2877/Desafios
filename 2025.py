number_of_texts = input()
SUBSTRING = "oulupukk"

for _ in range(int(number_of_texts)):
  text = input()
  text_as_list = text.split()
  result = ""

  for string in text_as_list:
    if SUBSTRING in string:
      string = "J" + string[1:]
      if string[-1] == ".":
        string = string[:-2] + "i." 
      else:
        string = string[:-1] + "i"

    result += string + " "

  print(result[:-1])