import heapq

if __name__ == "__main__":
    number_of_cashiers, number_of_clients = input().split(' ')

    number_of_cashiers = int(number_of_cashiers)
    number_of_clients = int(number_of_clients)

    list_of_cashiers = input().split(' ')
    list_of_clients = input().split(' ')

    my_queue = []
    last_client_attended = 0

    heapq.heapify(my_queue)

    for i in range(number_of_cashiers):
        #heap - cashier_time_spent, cashier_index, cashier_velocity
        heapq.heappush(my_queue, (int(list_of_cashiers[i])*int(list_of_clients[i]), i, int(list_of_cashiers[i])))
        last_client_attended = i


    missing_clients = number_of_clients - last_client_attended - 1

    for j in range(missing_clients):
        current_client_index = last_client_attended + j + 1
        first_available_cashier = heapq.heappop(my_queue)
        heapq.heappush(my_queue, ((first_available_cashier[2]*int(list_of_clients[current_client_index])) + first_available_cashier[0], first_available_cashier[1], first_available_cashier[2]))

    largest_tuple = heapq.nlargest(1, my_queue)[0]
    print(largest_tuple[0])
        
