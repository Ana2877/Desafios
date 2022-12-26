from sys import stdin, stdout

N = 100000

tree = [0] * (2 * N)

def min_value(value1, value2):
    return value1 if value1 < value2 else value2

def max_value(value1, value2):
    return value1 if value1 > value2 else value2

# function to build the tree
def build(array_of_cellphone_prices, number_of_shops):

	# insert leaf nodes in tree
    for i in range(number_of_shops):
        tree[number_of_shops + i] = (array_of_cellphone_prices[i], array_of_cellphone_prices[i])
	
	# build the tree by calculating parents
    for i in range(number_of_shops - 1, 0, -1):
        
        min_price = min_value(tree[i << 1][0], tree[i << 1 | 1][0])
        max_price = max_value(tree[i << 1][1], tree[i << 1 | 1][1])

        tree[i] = (min_price, max_price)

# function to update a tree node
def updateTreeNode(shop, new_price, number_of_shops) :
	
	# set new_price at position shop
    tree[shop + number_of_shops] = (new_price, new_price)
    shop = shop + number_of_shops
	
	# move upward and update parents
    i = shop
	
    while i > 1 :

        min_price = min_value(tree[i][0], tree[i ^ 1][0])
        max_price = max_value(tree[i][1], tree[i ^ 1][1])
		
        tree[i >> 1] = (min_price, max_price)
        i >>= 1

# function to get sum on interval [start, end)
def query(start, end, number_of_shops):
	
	# loop to find the sum in the range
    start += number_of_shops
    end += number_of_shops

    highest_price = 0
    lowest_price = float('inf')
	
    while start < end:
	
        if (start & 1):
            highest_price = max_value(highest_price, tree[start][1])
            lowest_price = min_value(lowest_price, tree[start][0])
            start += 1
	
        if (end & 1):
            end -= 1
            highest_price = max_value(highest_price, tree[end][1])
            lowest_price = min_value(lowest_price, tree[end][0])
            
        
        start >>= 1
        end >>= 1
	
    return highest_price - lowest_price

CHANGE_PRICE = 1
QUERY = 2

if __name__ == "__main__" :
    while True:
        try:
            number_of_shops = int(stdin.readline())
            array_of_cellphone_prices = [int(x) for x in stdin.readline().split()]

            build(array_of_cellphone_prices, number_of_shops)

            number_of_operations = int(stdin.readline())

            for i in range(number_of_operations):
                operation = [int(x) for x in stdin.readline().split()]

                operation_type = operation[0]

                if operation_type == CHANGE_PRICE:
                    shop = operation[1] - 1
                    new_price = operation[2]
                    updateTreeNode(shop, new_price, number_of_shops)

                elif operation_type == QUERY:
                    start = operation[1] - 1
                    end = operation[2]
                    result = query(start, end, number_of_shops)
                    stdout.write(str(result))
                    stdout.flush()

        except EOFError:
            break