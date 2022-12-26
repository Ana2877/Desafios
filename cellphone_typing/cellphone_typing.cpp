// C++ implementation of search and insert
// operations on Trie
#include <bits/stdc++.h>
using namespace std;
#include <cstdio>
#include <string>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <cmath>
#include <iomanip>
 
const int ALPHABET_SIZE = 26;
 
// trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
 
    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
};
 
// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;
 
    pNode->isEndOfWord = false;
 
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;
 
    return pNode;
}

bool hasOnlyOneChild(struct TrieNode *pNode){
    int children_number = 0;
    
    for (int i = 0; i < ALPHABET_SIZE; i++){
        if(pNode->children[i]){
            children_number += 1;
            if (children_number>1){
                return false;
            }
        }
    }
        
    return true;
}
 
// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;
 
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
 
        pCrawl = pCrawl->children[index];
    }
 
    // mark last node as leaf
    pCrawl->isEndOfWord = true;
}
 
// Returns true if key presents in trie, else
// false
bool search(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;
 
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return false;
 
        pCrawl = pCrawl->children[index];
    }
 
    return (pCrawl->isEndOfWord);
}

//Return an index where the search can continue
int get_typed_letters(struct TrieNode *root, string key)
{
    int typed_letters = 0;
    struct TrieNode *pCrawl = root;
    
    int klen = key.length();
 
    for (int i = 0; i < key.length(); i++)
    {
        
        int index = key[i] - 'a';
        
        if (!pCrawl->children[index])
            return typed_letters;
            
        if(!hasOnlyOneChild(pCrawl) || pCrawl->isEndOfWord){
            typed_letters +=1;
        }
 
        pCrawl = pCrawl->children[index];
    }
 
    return typed_letters;
}
 
// Driver
int main()
{
    int number_of_words;
    string word;
    vector<string> words;
    int number_of_typed_letters = 0;
    float average_of_typed_letters = 0;
    
    while(scanf("%d", &number_of_words) != EOF){
        number_of_typed_letters = 0;
        words.clear();
     
        struct TrieNode *root = getNode();
     
        // Construct trie
        for (int i = 0; i <= number_of_words; i++){
            getline(cin, word);
            words.push_back(word);
            insert(root, word);
        }
        
        for(int i = 0; i<=number_of_words; i++) {
            number_of_typed_letters += get_typed_letters(root, words[i]);
        }
       
        average_of_typed_letters = float(number_of_typed_letters)/float(number_of_words);
       
        printf("%.2f", average_of_typed_letters);
        
    }
    return 0;
}