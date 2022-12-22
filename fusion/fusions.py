OPERATION_FUSION = 'F'
OPERATION_CONSULT = 'C'

class DisJointSets():
    def __init__(self,N):
        # Initially, all elements are single element subsets
        self._parents = [node for node in range(N)]
        self._ranks = [1 for _ in range(N)]
    
    def find(self, u):
        while u != self._parents[u]: 
            # path compression technique
            self._parents[u] = self._parents[self._parents[u]]
            u = self._parents[u]
        return u
    
    def connected(self, u, v):
        return self.find(u) == self.find(v)
    
    def union(self, u, v):
        # Union by rank optimization
        root_u, root_v = self.find(u), self.find(v)
        if root_u == root_v:
            return True
        if self._ranks[root_u] > self._ranks[root_v]:
            self._parents[root_v] = root_u
        elif self._ranks[root_v] > self._ranks[root_u]:
            self._parents[root_u] = root_v
        else:
            self._parents[root_u] = root_v
            self._ranks[root_v] += 1
        return False

def fuse_first_and_second_banks(array_of_banks, first_bank, second_bank):
    array_of_banks.union(first_bank, second_bank)

def first_and_second_banks_are_equal(array_of_banks, first_bank, second_bank):
    return array_of_banks.connected(first_bank, second_bank)

if "__main__":
    # the bank codes are the number of 1 - number_of_banks
    number_of_banks, number_of_operations = input().split(' ')
    array_of_banks = DisJointSets(int(number_of_banks)+1)

    for _ in range(int(number_of_operations)):
        operation, first_bank, second_bank = input().split(' ')   

        if(operation == OPERATION_FUSION):
            fuse_first_and_second_banks(array_of_banks, int(first_bank), int(second_bank))

        elif(operation == OPERATION_CONSULT):
            if (first_and_second_banks_are_equal(array_of_banks, int(first_bank), int(second_bank))):
                print('S')
            else:
                print('N')

