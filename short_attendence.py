number_of_test_cases = int(input())

for _ in range(number_of_test_cases):
    number_of_students = int(input())
    students = input()
    presence_list = input()


    students_array = students.split()
    presence_list_array = presence_list.split()

    frequency_list = ""

    for index, presence in enumerate(presence_list_array):
        present = 0
        absent = 0
        total = 0

        for letter in presence:
            if letter == 'P':
                present += 1
                total += 1
            elif letter == 'A':
                absent += 1
                total += 1

        frequency = (present * 100)/total
        
        if frequency < 75:
            frequency_list += students_array[index] + ' '


    print(frequency_list[:-1])