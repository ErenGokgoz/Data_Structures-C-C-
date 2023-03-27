#include <iostream>
#include <queue>

/*binary tree
          2
        /   \          struct Node{
       5     6             int data;
      / \   / \            Node * leftLink;
     10 20 31  9           Node * rightLink;}   at the trees RECURIONS are so important for search and insert                                        functions.
 */

//binary search tree implementation c++/c PART I
   //storing data of int tree:
struct BstNode{  //binary search tree Node:
    int data;
    BstNode * right;
    BstNode * left;
};

BstNode * createNewNode(int x){
    BstNode * temp = new BstNode();
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}

BstNode * insert(BstNode * root,int x){  //insert an element using recursion.
    if(root == NULL){BstNode * temp = createNewNode(x);root = temp;}
    else if(x<= root->data) {root->left = insert(root->left, x);}
    else{root->right = insert(root->right, x);}
    return root;
}

int sayac = 0;

bool search(BstNode * root, int data){  //searching using recursion
    sayac++;
    if(root == NULL){printf("sorry we could not find your answer"); return false;}
    else if(root->data == data){printf("we found your search."); return true;}
    else if(root->data > data){return search(root->left, data);}
    else{return search(root->right, data);}
}

     //find min and max values at the tree//
int findMin(BstNode * root){
      while (root->left != NULL) {
        root = root->left;
    }                                     //solve with using while loop.
    return root->data;
    /*if(root->left == NULL){
        return root->data;
    }
    else{
        return findMin(root->left);       //solve with using recursion.
    }*/

}

int findMax(BstNode * root){
    while (root->right != NULL) {
        root = root->right;               //solve with using while loop.
    }
    return root->data;
    /*if(root->right == NULL){
        return root->data;
    }
    else{
        return findMax(root->right);      //solve with using recursion.
    }*/
}

     //find height of the tree (with using recursion)//

int max(int x, int y){
    if(x == y){return x;}
    else if (x > y){return x;}
    else{return y;}
}

int findHeight(BstNode * root){
    if(root == NULL){ return -1;}
    return max(findHeight(root->left),findHeight(root->right)) + 1;
}

    //binary tree traversal//
          //breath-first traversal(level order traversal)//
void level_order_traversal(BstNode * root){
    if(root == NULL) return;
    std::queue <BstNode *> Q;
    Q.push(root);
    while (!Q.empty()) {
        BstNode * current = Q.front();
        std::cout<<"("<<current->data<<")-";
        if(current->left != NULL) Q.push((*current).left);
        if(current->right != NULL) Q.push((*current).right);
        Q.pop();
    }
}
          //depth-first traversal//
// root - left - right = Preorder;
void depth_traversal_preorder(BstNode * root){
    if(root == NULL) return;
    std::cout<<"("<<root->data<<")-";
    depth_traversal_preorder(root->left);
    depth_traversal_preorder(root->right);
}

//left - root - rigth = Inorder;
void depth_traversal_inorder(BstNode * root){
    if(root == NULL) return;
    depth_traversal_inorder(root->left);
    std::cout<<"("<<root->data<<")-";
    depth_traversal_inorder(root->right);
}
//left - right - root = postorder;
void depth_traversal_postorder(BstNode * root){
    if(root == NULL) return;
    depth_traversal_postorder(root->left);
    depth_traversal_postorder(root->right);
    std::cout<<"("<<(*root).data<<")-";
}
    
      //CHECKING THE BINARY TREE IS A SEARCH BINARY TREE OR NOT//

//SOLUTION 1--(MORE EXPENSIVE THAN THE OTHER SOLUTIONS)
/*bool isBinarySearchTree(BstNode * root){
    if(root == NULL) return true;
    if((root->left == NULL || findMin(root->left) <= root->data)
       && (root->right == NULL || findMax(root->right) > root->data)){
        isBinarySearchTree(root->left);
        isBinarySearchTree(root->right);
        return true;
    }
    else    return false;
}*/

//SOLUTION 2 (MORE AFFICENT THAN THE FIRST ONE)
bool isBstUtil(BstNode * root, int min, int max){
    if(root == NULL) return true;
    
    if(root->data > min && root->data < max
       && isBstUtil(root->left, min, root->data)
       && isBstUtil(root->right, root->data, max))
        return true;
    else return false;
}
bool isBST(BstNode * root){
    return isBstUtil(root, INT_MIN, INT_MAX);
}

    //delete node from binary search tree//
BstNode * findMinNode(BstNode * root){
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

BstNode * deleteNode(BstNode * root,int data){
    if(root == NULL) return root;
    else if(root->data > data) root->left = deleteNode(root->left, data);
    else if(root->data < data) root->right = deleteNode(root->right, data);
    else{
        //case 1; no any child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        //case 2; no left child
        else if(root->left == NULL){
            BstNode * temp = root;
            root = root->right;
            delete temp;
            return root;
        }
        //case 2; no right child
        else if(root->right == NULL){
            BstNode * temp = root;
            root = root->left;
            delete temp;
            return root;
        }
        //case 3; two children;
        else{
            BstNode * temp = findMinNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
            return root;
        }
    }
    return root;
}

//end of implementation

int main() {
    //pointer of root of the tree: //setting local variable:
    BstNode * root = NULL;
  
    root = insert(root,40);
    insert(root,50);
    insert(root, 100);
    insert(root, 31);
    insert(root, 1000);
    insert(root, 42);
    insert(root, 4);
    insert(root, 14);
    insert(root, 1001);
    insert(root, -4);
    insert(root, 16);
    insert(root, 15);
    search(root, 34);
    
    std::cout<<findMax(root)<<"\n";
    std::cout<<findMin(root)<<"\n";
    std::cout<<findHeight(root)<<"\n";
    
      //TRAVERS THE TREE
    depth_traversal_preorder(root);
    printf("\n");
    depth_traversal_inorder(root);
    printf("\n");
    depth_traversal_postorder(root);
    printf("\n");
    std::cout<<isBST(root)<<std::endl;
    return 0;
    
    //DELETE NODE FROM BST
    /*deleteNode(root, 31);
    depth_traversal_inorder(root);*/
}
