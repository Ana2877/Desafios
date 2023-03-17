string_input = input()
string_list = string_input.split()
result = ""

for string in string_list:
  if len(string) >= 4 and string.startswith(string[0] + string[1] + string[0] + string[1]):
    result += string[2:] + " "
  else:
    result += string + " "

print(result[:-1])