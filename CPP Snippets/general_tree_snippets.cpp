/* BST SEARCH */
struct node* search(struct node* root, int key) 
{ 
    // Base Cases: root is null or key is present at root 
    if (root == NULL || root->key == key) 
       return root; 
     
    // Key is greater than root's key 
    if (root->key < key) 
       return search(root->right, key); 
  
    // Key is smaller than root's key 
    return search(root->left, key); 
} 


/* BST INSERTION */
struct node* insert(struct node* node, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key); 
  
    /* Otherwise, recur down the tree */
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key);    
  
    /* return the (unchanged) node pointer */
    return node; 
}


/* BST DELETION */

struct node * minValueNode(struct node* node) 
{ 
    struct node* current = node; 
  
    /* loop down to find the leftmost leaf */
    while (current->left != NULL) 
        current = current->left; 
  
    return current; 
}


struct node* deleteNode(struct node* root, int key) 
{ 
    // base case 
    if (root == NULL) return root; 
  
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    if (key < root->key) 
        root->left = deleteNode(root->left, key); 
  
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (key > root->key) 
        root->right = deleteNode(root->right, key); 
  
    // if key is same as root's key, then This is the node 
    // to be deleted 
    else
    { 
        // node with only one child or no child 
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        struct node* temp = minValueNode(root->right);
  
        // Copy the inorder successor's content to this node 
        root->key = temp->key; 
  
        // Delete the inorder successor 
        root->right = deleteNode(root->right, temp->key); 
    } 
    return root; 
}



/* GIVEN TREE IS BST OR NOT? */
int isBST(TreeNode* root, int min_val, int max_val){
    if(root==NULL) return 1;
    if(root->val>min_val && root->val<max_val && isBST(root->left, min_val, root->val)
        && isBST(root->right, root->left, max_val)) return 1;
    return 0;
}

isBST(root, INT_MIN, INT_MAX);


/* INORDER SUCCESSOR OF BST */

TreeNode* FindNode(TreeNode* root, int data){
    if(root==NULL) return NULL;
    if(root->val==data) return root;
    else if(root->val < data) return FindNode(root->right, data);
    return FindNode(root->left, data);
}

TreeNode* FindMin(TreeNode* node){
    while(node->left!=NULL) node=node->left;
    return node;
}

TreeNode* Solution::getSuccessor(TreeNode* A, int B) {
    TreeNode* current = FindNode(A, B);
    if(current==NULL) return NULL;
    if(current->right != NULL) return FindMin(current->right);
    else{
        TreeNode* successor = NULL;
        TreeNode* ancestor = A;
        while(ancestor != current){
            if(current->val < ancestor->val){
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else{
                ancestor = ancestor->right;
            }
        }
        return successor;
    }
}

/* CHECK TREE IS BALANCED OR NOT */
int checkBalance(TreeNode* root){
    if(root==NULL) return 1;
    if(root->left==NULL && root->right==NULL) return 1;
    if(root->left!=NULL && root->right!=NULL)
        return min(checkBalance(root->left), checkBalance(root->right));
    else if(root->left==NULL){
        if(root->right->right!=NULL || root->right->left!=NULL) return 0;
        return 1;
    }
    else{
        if(root->left->left!=NULL || root->left->right!=NULL) return 0;
        return 1;
    }
}

/* Two Sum in BST  */
int fn(TreeNode* A, int B { // B is Target
    if(A==NULL) return 0;
    stack<TreeNode* > s1, s2;
    TreeNode* temp1 = A;
    TreeNode* temp2 = A;
    while(temp1){
        s1.push(temp1);
        temp1 = temp1->left;
    }
    while(temp2){
        s1.push(temp2);
        temp2 = temp2->right;
    }
    temp1 = s1.top();
    temp2 = s2.top();
    while(temp1 && temp2 && temp1->val < temp2->val){
        if(temp1->val + temp2->val == B) return 1;
        if(temp1->val+ temp2->val < B){
            s1.pop();
            temp1 = temp1->right;
            while(temp1){
                s1.push(temp1);
                temp1 = temp1->left;
            }
            temp1 = s1.top();
        }
        else{
            s2.pop();
            temp2 = temp2->left;
            while(temp2){
                s2.push(temp2);
                temp2 = temp2->right;
            }
            temp2 = s2.top();
        }
    }
    return 0;
}


/* Inorder Traversal Iterative */
vector<int> inorderTraversal(TreeNode* A) {
    stack<TreeNode*> stk;
    TreeNode* temp = A;
    vector<int> ans;
    while(temp or !stk.empty()){
        while(temp){
            stk.push(temp);
            temp = temp->left;
        }
        temp = stk.top();
        stk.pop();
        ans.push_back(temp->val);
        temp = temp->right;
    }
    return ans;
}

/* Preorder Traversal Iterative */
vector<int> preorderTraversal(TreeNode* A){
    stack<TreeNode*> stk;
    TreeNode* temp = A;
    vector<int> ans;
    stk.push(temp);
    while(!stk.empty()){
        temp = stk.top();
        stk.pop();
        ans.push_back(temp->val);
        if(temp->right) stk.push(temp->right);
        if(temp->left) stk.push(temp->left);
    }
    return ans;
}

/* Postorder Traversal Iterative */
vector<int> postorderTraversal(TreeNode* A){
    stack<TreeNode*> stk;
    TreeNode* temp = A;
    vector<int> ans;
    stk.push(temp);
    while(!stk.empty()){
        temp = stk.top();
        stk.pop();
        ans.push_back(temp->val);
        if(temp->left) stk.push(temp->left);
        if(temp->right) stk.push(temp->right);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

/* Trie Boilerplate */
struct TrieNode{
    map<char, TrieNode*> children;
    bool isEnd;
    int prefix_count = 0;
}*head;

void init(){
    head = new TrieNode();;
    head->isEnd = false;
    head->prefix_count = 0;
}

void insert(string word){
    TrieNode* current = head;
    for(int i=0; i<word.size(); i+=1){
        char letter = word[i];
        if(current->children.find(letter) == current->children.end())
            current->children[letter] = new TrieNode();
        current = current->children[letter];
    }
    current->prefix_count += 1;
    current->isEnd = true;
}

int isSearch(string word){
    TrieNode* current = head;
    for(int i=0; i<word.size(); i+=1){
        char letter = word[i];
        if(current->children.find(letter) == current->children.end())
            return -1;
        current = current->children[letter];
    }
    if(current->isEnd) return current->prefix_count;
    return -1;
}