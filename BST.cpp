#include "bits/stdc++.h"
#include <stdlib.h>

using namespace std;

 
struct Node
{
    int data;
    struct Node *left, *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

struct Node *createNode()
{
    struct Node *n;
    n = (struct Node *)malloc(sizeof(struct Node));
    int val;
    cout << "Enter a data of the root node of tree\n";
    cin >> val;
    // creating a node pointer
    // Allocating memory in the heap
    n->data = val;   // Setting the data
    n->left = NULL;  // Setting the left and right children to NULL
    n->right = NULL; // Setting the left and right children to NULL
                     // Finally returning the created node
}

// INSERT A NODE IN BINARY SEARCH TREE
struct Node *Insert(struct Node *root, int key)
{
    // int key;
    // cout << "Enter the value to insert\n";
    // cin >> key;
    struct Node *newnode = new Node(key);
    struct Node *cur = root;
    struct Node *parent = NULL;

    while (cur != NULL)
    {
        parent = cur;
        if (key < cur->data)
        {
            cur = cur->left;
        }
        else
        {
            cur = cur->right;
        }
    }
    if (parent == NULL)
    {
        parent = newnode;
    }
    else if (key == parent->data)
    {
        cout << "Element " << key << " already present\n";
    }

    else if (key < parent->data)
    {
        parent->left = newnode;
    }
    else
    {
        parent->right = newnode;
    }
    cout << key << " added successfully\n";
    return parent;
}

// INSERTOIN OF NODE IN BINARY SEARCH TREE USING RECURSION METHOD
struct Node *InsertBst(struct Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }
    else if (val < root->data)
    {
        root->left = InsertBst(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = InsertBst(root->right, val);
    }
    else if (val == root->data)
    {
        cout << "Element " << val << " already present\n";
    }
    cout << val << " added successfully\n";

    return root;
}

// DELETE A NODE FROM A BINARY SERACH TREE
struct Node *Delete(struct Node *root)
{
}

// SEARCH A NODE FROM A BINARY SERACH TREE
struct Node *Search(struct Node *root, int key)
{
    if (root == NULL)
    {
        cout << "Tree is empty\n";
    }
    else
    {
        if (key == root->data)
        {
            return NULL;
        }
        else if (key < root->data)
        {

            return Search(root->left, key);
        }
        else if (key > root->data)
        {
            return Search(root->right, key);
        }
    }
}

struct Node *searchIter(struct Node *root, int key1)
{
    while (root != NULL)
    {
        if (key1 == root->data)
        {
            return root;
        }
        else if (key1 < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}

// FUNCTION TO CALCULATE THE HEIGHT OF BST
int Calculate_Height(struct Node *root)
{
    int x, y;
    if (root != NULL)
    {
        x = Calculate_Height(root->left);
        y = Calculate_Height(root->right);
        if (x > y)
            return x + 1;
        else
            return y + 1;
    }
    return -1;
}

// FUNCTION TO FIND THE DIAMETER OF BST
int Calculate_Diameter(struct Node *root)
{
    // base case where tree is empty
    if (root == NULL)
        return 0;

    // get the height of left and right sub-trees
    int lheight = Calculate_Height(root->left);
    int rheight = Calculate_Height(root->right);

    // get the diameter of left and right sub-trees
    int ldiameter = Calculate_Diameter(root->left);
    int rdiameter = Calculate_Diameter(root->right);

    // Return max of following three
    // 1) Diameter of left subtree
    // 2) Diameter of right subtree
    // 3) Height of left subtree + height of right subtree +
    // 1
    return max(lheight + rheight + 1,
               max(ldiameter, rdiameter));
}

// FUNCITON TO FIND THE RIGHT VIEW OF BINARY TREE USING ITERATIVE METHOD
struct Node *RightView_iterative(struct Node *root)
{
    if (root == NULL)
    {
        return root;
    }
    cout << "The right view of binary tree is\n\n";
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        for (int i = 1; i <= n; i++)
        {
            Node *current = q.front();
            q.pop();

            if (i == n)
            {
                cout << current->data << " ";
            }

            if (current->left != NULL)
            {
                q.push(current->left);
            }

            if (current->right != NULL)
            {
                q.push(current->right);
            }
        }
    }
}
//FUNCTION TO FIND THE RIGHT VIEW OF BINARY SEARCH TREE USING RECURSION
int max_level = 0;
void  RightView_recursive(struct Node *root, int level)
{

    // Base Case
    if (root == NULL)
        return;

    // If this is the last Node of its level
    if (max_level < level)
    {
        cout << root->data << "\t";
        max_level = level;
    }

    // Recur for right subtree first,
    // then left subtree
    RightView_recursive(root->right, level + 1);
    RightView_recursive(root->left, level + 1);
}

// FUNCITON TO FIND THE LEFT VIEW OF BINARY TREE USING ITERATIVE METHOD
struct Node *LeftView_iterative(struct Node *root)
{
    if (root == NULL)
    {
        return root;
    }
    cout << "The left view of binary tree is\n\n";
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        for (int i = 1; i <= n; i++)
        {
            Node *current = q.front();
            q.pop();
            if (i == 1)
            {
                cout << current->data << " ";
            }
            if (current->left != NULL)
            {
                q.push(current->left);
            }
            if (current->right != NULL)
            {
                q.push(current->right);
            }
        }
    }
}

// FUNCTION TO FIND THE LEFT VIEW OF BINARY TREE USING RECURSION
int maxLevel =0;
struct Node *LeftView_recursive(struct Node *root, int level)
{
    
    if (root == NULL)
    {
        return root;
    }

    if (maxLevel < level)
    {
        cout << root->data<<"\t";
        maxLevel = level;
    }

    LeftView_recursive(root->left, level + 1);
    LeftView_recursive(root->right, level + 1);
}

struct Node *TrimBST(struct Node *root, int low_value, int high_value)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data >= low_value && root->data <= high_value)
    {
        root->left = TrimBST(root->left, low_value, high_value);
        root->right = TrimBST(root->right, low_value, high_value);
    }
    else if (root->data > high_value)
    {
        return TrimBST(root->left, low_value, high_value);
    }
    else if (root->data < low_value)
    {
        return TrimBST(root->right, low_value, high_value);
    }
    return root;
}
// FUNCTION TO FIND THE PREORDER
void PreOrder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

void PostOrder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}

struct Node *LevelOrder(struct Node *root)
{
    if (root == NULL)
    {
        return root;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        struct Node *queue_node;
        queue_node = q.front();
        q.pop();
        if (queue_node != NULL)
        {
            cout << queue_node->data << "->";
            if (queue_node->left != NULL)
                q.push(queue_node->left);
            if (queue_node->right != NULL)
                q.push(queue_node->right);
        }
        // check if queue is empty or not and queueData is null
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
}
struct Node *Graphical_2DD_View(struct Node *root, int space)
{
    int COUNT = 10;
    // Base case
    if (root == NULL)
        return root;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    Graphical_2DD_View(root->right, space);

    // Print current node after space

    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->data << "\n";

    // Process left child
    Graphical_2DD_View(root->left, space);
}

// Wrapper overGraphical_2D_View()
void Graphical_2D_View(Node *root)
{
    // Pass initial space count as 0
    Graphical_2DD_View(root, 0);
}

int main(int argc, char const *argv[])
{

    int choice, i, data, n;

    struct Node *root = createNode();
    while (1)
    {

        cout << "\nWELCOME TO BINARY SEARCH TREE";
        cout << "\n01. Insertion.";
        cout << "\n02. Insertion using recursion";
        cout << "\n03. Delete.";
        cout << "\n04. Search the element in the binary_search_tree recursively";
        cout << "\n05. Search the element in the binary_search_tree interatively";
        cout << "\n06. Display the number of leaves, internal nodes";

        cout << "\n07. Height of binary search tree";
        cout << "\n08. Diameter of binary search tree";

        cout << "\n09. Right view of bianry search tree using iterative method";
        cout << "\n10. Right view of bianry search tree using recursive method";
        cout << "\n11. Left view of bianry search tree  using iterative method";
        cout << "\n12. Left view of bianry search tree  using recursion method";

        cout << "\n13. Mirror or invert of binary search tree";
        cout << "\n14. Merge two binary serach tree";

        cout << "\n15. Identical binary search tree";
        cout << "\n16. Identical binary search tree without building the trees";

        cout << "\n17. Trim the binary search tree";

        cout << "\n100. Preorder";
        cout << "\n101. Inorder";
        cout << "\n102. Postorder";
        cout << "\n103. LevelOrder";
        cout << "\n104. 2D Grpah view";
        cout << "\n105. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {

        case 1:
            cout << "Enter the numbers of nodes you want to insert:\n ";
            cin >> n;
            cout << "Enter the values of nodes\n";
            for (i = 0; i < n; i++)
            {
                cin >> data;
                Insert(root, data);
            }
            break;

        case 2:
            int key3;
            cout << "Enter the value to insert in  binary search tree\n";
            cin >> key3;
            InsertBst(root, key3);
            break;

        case 3:
            Delete(root);
            break;

        case 4:
            int key5;
            cout << "Enter the data to be searhed\n";
            cin >> key5;
            if (searchIter(root, key5))
            {
                cout << key5 << " is  present in tree\n";
            }
            else
            {
                cout << key5 << " is not present in tree";
            }
            break;

        case 5:
            int key1;
            cout << "Enter the data to be searhed\n";
            cin >> key1;
            if (searchIter(root, key1))
            {
                cout << key1 << " is  present in tree\n";
            }
            else
            {
                cout << key1 << " is not present in tree";
            }
            break;

        case 7:

            cout << "The height of binary search tree is" << Calculate_Height(root) << endl;
            break;

        case 8:

            cout << "The diameter of binary search tree is " << Calculate_Diameter(root) << "\n";
            break;

        case 9:
            RightView_iterative(root);
            break;

        case 10:
            int level1;
            cout << "Enter the level of BST\n";
            cin >> level1;
            RightView_recursive(root, level1);
            break;

        case 11:
            LeftView_iterative(root);
            break;

        case 12:
            int level;
            cout << "Enter the level of BST\n";
            cin >> level;
            LeftView_recursive(root, level);
            break;

        case 17:
            int low_value, high_value;
            cout << "Enter the range\n";
            cin >> low_value >> high_value;
            TrimBST(root, low_value, high_value);
            break;

        case 100:
            cout << "Preorder transversal of tree is" << endl;
            PreOrder(root);
            cout << "\n";
            break;

        case 101:

            cout << "Inorder transversal of tree is\n"
                 << endl;
            InOrder(root);
            cout << "\n";
            break;

        case 102:
            cout << "PostOrder transversal of tree is\n"
                 << endl;
            PostOrder(root);
            cout << "\n";
            break;

        case 103:
            cout << "Levelorder transversal of tree is\n"
                 << endl;
            LevelOrder(root);
            cout << "\n";
            break;
        case 104:
            Graphical_2D_View(root);

            break;
        case 105:
            exit(0);
            break;
        default:
            cout << "WRONG CHOICE";
            break;
        }
    }

    return 0;
}
