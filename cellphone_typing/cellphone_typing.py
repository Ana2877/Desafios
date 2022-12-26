from sys import stdin, stdout
import psyco
psyco.full()

class TrieNode:
    """A node in the trie structure"""

    def __init__(self, char):
        # the character stored in this node
        self.char = char

        # whether this can be the end of a word
        self.is_end = False

        # a dictionary of child nodes
        # keys are characters, values are nodes
        self.children = {}

        self.has_one_word = False


class Trie(object):
    """The trie object"""

    def __init__(self):
        """
        The trie has at least the root node.
        The root node does not store any character
        """
        self.root = TrieNode("")
        self.helper = None

    
    def insert(self, word):
        """Insert a word into the trie"""
        node = self.root
        
        # Loop through each character in the word
        # Check if there is no child containing the character, create a new child for the current node
        for char in word:
            if char in node.children:
                if (node.has_one_word):
                    node.has_one_word = False
                node = node.children[char]

            else:
                # If a character is not found,
                # create a new node in the trie
                new_node = TrieNode(char)
                new_node.has_one_word = True
                node.children[char] = new_node
                node = new_node
        
        # Mark the end of a word
        node.is_end = True

    def get_commom_prefix(self, prefix):

        node = trie.helper
        common_prefix = prefix
        added_prefix = False
        
        while(len(node.children) == 1 and not node.is_end):
            next_node = next(iter(node.children.values()))
            common_prefix += next_node.char
            node = next_node
            added_prefix = True


        self.helper = node

        if (added_prefix):
            return common_prefix
        else:
            return None

    def initialize_helper(self):
        self.helper = self.root

if "__main__":
    while True:
        try:
            number_of_words_in_dictionary = int(stdin.readline())
            trie = Trie()

            list_of_words = []

            for _ in range(number_of_words_in_dictionary):
                word = stdin.readline()
                trie.insert(word)
                list_of_words.append(word)

            number_of_typed_letters = 0

            for word in list_of_words:
                trie.initialize_helper()
                sub_word = ""
                word_index = 0
                word_size = len(word)

                while(word_index < word_size):
                    sub_word += word[word_index]
                    number_of_typed_letters += 1

                    trie.helper = trie.helper.children[word[word_index]]

                    if(trie.helper.has_one_word):
                        break

                    trie_result = trie.get_commom_prefix(sub_word)

                    word_index +=1

                    if (trie_result):
                        trie_result_len = len(trie_result)
                        word_index = trie_result_len
                        sub_word = trie_result

                        if (trie_result_len - 1 == word_size):
                            break

            average_number_of_typed_letters = round(float(number_of_typed_letters/len(list_of_words)), 2)

            stdout.write(str(average_number_of_typed_letters))

        except EOFError:
            break