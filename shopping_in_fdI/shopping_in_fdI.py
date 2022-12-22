N = 100000

tree = [0] * (2 * N)

# function to build the tree
def build(array_of_cellphone_prices, number_of_shops):

	# insert leaf nodes in tree
	for i in range(number_of_shops):
		tree[number_of_shops + i] = array_of_cellphone_prices[i]
	
	# build the tree by calculating parents
	for i in range(number_of_shops - 1, 0, -1) :
		tree[i] = tree[i << 1] + tree[i << 1 | 1]

# function to update a tree node
def updateTreeNode(shop, new_price, number_of_shops) :
	
	# set new_price at position shop
	tree[shop + number_of_shops] = new_price
	shop = shop + number_of_shops
	
	# move upward and update parents
	i = shop
	
	while i > 1 :
		
		tree[i >> 1] = tree[i] + tree[i ^ 1]
		i >>= 1

# function to get sum on interval [start, end)
def query(start, end, number_of_shops):

    answer = 0;
	
	# loop to find the sum in the range
    start += number_of_shops
    end += number_of_shops

    highest_price = 0
    lowest_price = float('inf')
	
    while start < end:
	
        if (start & 1):
            answer += tree[start]
            start += 1
	
        if (end & 1):
            end -= 1
            answer += tree[end]
            
        
        start >>= 1
        end >>= 1
	
    return answer

CHANGE_PRICE = 1
QUERY = 2

if __name__ == "__main__" :
    number_of_shops = int(input())
    array_of_cellphone_prices = [int(i) for i in input().split()]

    build(array_of_cellphone_prices, number_of_shops)

    number_of_operations = int(input())

    for i in range(number_of_operations):
        operation = [int(i) for i in input().split()]

        operation_type = operation[0]

        if operation_type == CHANGE_PRICE:
            shop = operation[1] - 1
            new_price = operation[2]
            updateTreeNode(shop, new_price, number_of_shops)

        elif operation_type == QUERY:
            start = operation[1] - 1
            end = operation[2]
            print(query(start, end, number_of_shops))






