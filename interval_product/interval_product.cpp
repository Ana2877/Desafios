#include <iostream>
#include <vector>

using namespace std;

#define PRODUCT 'P'

int get_value(int value1, int value2){
    if(value1 == 0 || value2 == 0)
        return 0;
    else if(value1 < 0 && value2 > 0)
        return -1;
    else if(value1 > 0 && value2 < 0)
        return -1;
        
    return 1;
}


struct SegmentTree {  
    int product;
    int from;
    int to;
    SegmentTree *left;
    SegmentTree *right;
    // optional constructor
    SegmentTree(int from, int to, int product, SegmentTree* left=NULL,SegmentTree* right=NULL): 
       from(from),to(to),product(product),left(left),right(right) {}
};

SegmentTree* buildTree(vector<int>& nums, int from, int to) {
    if (from == to) {
        return new SegmentTree(from, to, nums[from]);
    }
    int mid = from + (to - from) / 2;
    auto left = buildTree(nums, from, mid);
    auto right = buildTree(nums, mid + 1, to);
    return new SegmentTree(from, to, get_value(left->product, right->product), left, right);
}

int queryTree(SegmentTree* root, int from, int to) {
    if (from == root->from && to == root->to) {
        return root->product;
    }
    int mid = root->from + (root->to - root->from) / 2;
    if (to <= mid) {
        return queryTree(root->left, from, to);
    } 
    if (from > mid) {
        return queryTree(root->right, from, to);
    }
    return get_value(queryTree(root->left, from, mid),
        queryTree(root->right, mid + 1, to));
}

void updateTree(SegmentTree* root, int index, int value) {
    if ((root->from == index) && (root->to == index)) {
        root->product = value;
        return;
    }
    int mid = root->from + (root->to - root->from) / 2;
    if (index <= mid) {
        updateTree(root->left, index, value);
    } else {
        updateTree(root->right, index, value);
    }
    root->product = get_value(root->left->product, root->right->product);
}

string get_result_as_string(int result){
    if(result == 0){
        return  "0";
    } else if (result < 0) {
        return "-";
    } else {
        return "+";
    }
}

int main()
{
    int number_of_elements, number_of_rounds;
    
    while(cin>>number_of_elements>>number_of_rounds){
        vector<int> elements;
        SegmentTree* seg_tree;
        int result, num_1, num_2, element;
        char command;
        string result_as_string = "";
        
        for(int i = 0; i < number_of_elements; i++){
            cin>>element;
            elements.push_back(element);
        }
        
        seg_tree = buildTree(elements, 0, number_of_elements);
        
        for(int i = 0; i < number_of_rounds; i++){
            cin>>command>>num_1>>num_2;
            
            if (command == PRODUCT){
                result = queryTree(seg_tree, num_1-1, num_2-1);
                result_as_string += get_result_as_string(result);
            } else {
                updateTree(seg_tree, num_1-1, num_2);
            }
        }
        
        cout<<result_as_string<<endl;
        
    }
    
    return 0;
}