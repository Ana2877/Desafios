import re

while True:
  
  try:
    string_to_be_replaced = input()
    insensitive_string  = re.compile(string_to_be_replaced, re.IGNORECASE)
    string_to_replace_to = input()
    string_input = input()
    string_result = ""
    index = 0
    
    while(index < len(string_input)):
      if(string_input[index] == "<"):
        new_string = string_input[index]
        while(string_input[index] != ">"):
          index+=1
          new_string += string_input[index]
    
        result_insensitive = insensitive_string.sub(string_to_replace_to, new_string)        
        string_result+=result_insensitive
      else:
        string_result+= string_input[index]
      index+=1

    print(string_result)
    
  except EOFError:
    break