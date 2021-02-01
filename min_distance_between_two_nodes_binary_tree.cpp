//
//  min_distance_between_two_nodes_binary_tree.cpp
//
//  Created by omlenka on 01/02/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

/* A binary tree node
 struct Node
 {
 int data;
 Node* left, * right;
 }; */

/* Should return minimum distance between a and b
 in a tree with given root*/
Node* getLCA(Node* root, int a, int b){
    if(root == NULL)
        return NULL;
    
    if(root->data == a || root->data == b){
        return root;
    }
    
    Node* left_lca = getLCA(root->left, a, b);
    Node* right_lca = getLCA(root->right, a, b);
    
    if(left_lca && right_lca){
        return root;
    }
    else if(left_lca){
        return left_lca;
    }
    else if(right_lca){
        return right_lca;
    }
    
    return NULL;
}

int getDistance(Node* root, int val){
    if(root == NULL)
        return -1;
    if(root->data == val)
        return 0;
    
    int left_dist = getDistance(root->left, val);
    int right_dist = getDistance(root->right, val);
    
    if(left_dist != -1){
        return 1+left_dist;
    }
    else if(right_dist != -1){
        return 1+right_dist;
    }
    
    return -1;
}

int findDist(Node* root, int a, int b) {
    // Your code here
    Node* lca = getLCA(root, a, b);
    return getDistance(lca, a) + getDistance(lca, b);
    
}
