# Online Python compiler (interpreter) to run Python online.
# Write Python 3 code in this online editor and run it.


class Node:
    def __init__(self, value):
        self.value = value
        self.next = None
 
 
class Stack:
 
    # Initializing a stack.
    # Use a dummy node, which is
    # easier for handling edge cases.
    def __init__(self):
        self.head = Node("head")
        self.size = 0
 
    # String representation of the stack
    def __str__(self):
        cur = self.head.next
        out = ""
        while cur:
            out += str(cur.value) + "->"
            cur = cur.next
        return out[:-3]
 
    # Get the current size of the stack
    def getSize(self):
        return self.size
 
    # Check if the stack is empty
    def isEmpty(self):
        return self.size == 0
 
    # Get the top item of the stack
    def peek(self):
 
        # Sanitary check to see if we
        # are peeking an empty stack.
        if self.isEmpty():
            raise Exception("Peeking from an empty stack")
        return self.head.next.value
 
    # Push a value into the stack.
    def push(self, value):
        node = Node(value)
        node.next = self.head.next
        self.head.next = node
        self.size += 1
 
    # Remove a value from the stack and return.
    def pop(self):
        if self.isEmpty():
            raise Exception("Popping from an empty stack")
        remove = self.head.next
        self.head.next = self.head.next.next
        self.size -= 1
        return remove.value




HOUR_IN = 0
HOUR_OUT = 1

if __name__ == "__main__":

    number_of_drivers = 1 
    parking_size = 1
    
    while(True):
    
        number_of_drivers, parking_size = input().split(' ')
        
        number_of_drivers = int(number_of_drivers)
        parking_size = int(parking_size)
        
        if((number_of_drivers == 0) and (parking_size == 0)):
            break

        parking_stack = Stack()
        
        it_worked = True
    
        for _ in range(int(number_of_drivers)):
            hour_in, hour_out = input().split(' ')
            hour_in = int(hour_in)
            hour_out = int(hour_out)
            
            if not parking_stack.isEmpty():
                last_car = parking_stack.peek()
                need_to_remove_cars = True
                
                while(need_to_remove_cars):
                    if hour_in >= last_car[HOUR_OUT]:
                        parking_stack.pop()
                        
                        if not parking_stack.isEmpty():
                            last_car = parking_stack.peek()
                        
                        else:
                            need_to_remove_cars = False
                            last_car = [0,float('inf')]
                            break
                    else:
                        need_to_remove_cars = False
                    
                if hour_out > last_car[HOUR_OUT]:
                    it_worked = False
                
                if  parking_stack.getSize() == parking_size:
                    it_worked = False
                    

            parking_stack.push([hour_in, hour_out])

            
        if(it_worked):
            print("Sim")
        else:
            print("Nao")
        