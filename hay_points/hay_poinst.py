def get_value_of_words_dict(number_of_words):
    value_of_words_dict = {}

    for _ in range(number_of_words):
        word, value_of_word = input().split(' ')
        value_of_words_dict[word] = int(value_of_word)

    return value_of_words_dict


def get_job_description_words_array():
    job_description_words_array = []
    end_char = "."

    while True: 
        line_description = input().split(' ')
        if (end_char == line_description[0]):
            break

        job_description_words_array.extend(line_description)

    return job_description_words_array


def get_hay_points(job_description_as_array, value_of_words_dict):
    hay_points = 0

    for word in job_description_as_array:
        if word in value_of_words_dict.keys():
            hay_points += value_of_words_dict[word]

    return hay_points


if "__main__":
    number_of_words, number_of_job_descriptions = input().split(' ')

    value_of_words_dict = get_value_of_words_dict(int(number_of_words))

    for _ in range(int(number_of_job_descriptions)):
        job_description_words_array = get_job_description_words_array()
        
        hay_points = get_hay_points(job_description_words_array, value_of_words_dict)

        print(hay_points)