Name: Net Zhang

I certify that I completed all of the work myself with no aid from anyone from the instuctor or the undegraduate graders.
# Program Instructions

## Step 1): Type of Balanced BST
In the begining of the program, it will prompt the user with the following message: 

  *Would you like to produce a BST or a Balanced BST?*
  *Enter `b` to produce a Balanced BST, otherwise a BST will be produced.*  

By entering the single character `b`, the user tells the program that he/she wants to construct a balanced BST with this program. Otherwise, a regular BST will be implemented as the default choice, that is every input including empty input will be considered as choosing the regular BST.

## Step 2): Construct BST from An Existing File
After specifying the type of tree they want construct, the program will ask the user whether they want to build their BST from an existing file. Here's the prompt message:

*Would you like the input of the tree to come from a file?*
*Enter `Y` or `N`:*
### Step 2.1): User Choices
* Invalid inputs

  Here, the user must enter either `Y` or `N` as an input. Empty input and other input will be treated as invalid input the user will be asked to enter their choices again.

### Step 2.2): File Inputs
The user will be asked for a file input if they specified `Y` from the above prompt.

*Please provide the file:*

* Invalid Files

  After recieving the name or path of the file, the program will try to open it and use the content as the elements of the BST. However, if the program failed to open the file, it will prompt an error message and ask for a valid file input again.

Once the program has the access to a valid input file, it will build their BST from that existing file. The type of the tree will be determined by the previous user options. After constructing the tree, the program will print out the result and ask the user whether he/she wants to perform more operations.

## Step 3): Type of Balanced BST
Now the user can perform some operations related to the Binary Search Tree. 

*Please selection from the following options: *
*- Enter 'a' to add a node*
*- Enter 'r' to remove a node*
*- Enter 'p' to print the tree*
*- Enter 'q' to quit*

### Step 3.1): Insert a Node
### Step 3.2): Remove a Node
### Step 3.3): Print BST
### Step 3.4): Quit

# Part 1:

## Q1:
The linked structures contains an int type data and a pointer to a linked list. In this lab, the binary search tree that we are implementing contains three elements, a char and two pointers to two binary search trees. 
## Q2:
In the program we initialize the BST with a null pointer. Hence, before we print the tree we will check whether the pointer to the tree is NULL. The tree is empty when the pointer is null then we print a message that prompt the user to insert the element into the tree.
## Q3:
Yes, it is possible to operate "terse" insertion and deletion functions on the BST structures we declared here. I choose to develop functions that return a BST pointers that requires assignment for updating. If we are using "terse" insertion and deletion here, we could change our method into void method and pass the pointer to a pointer of BST instead of a pointer of BST. 

# Part 2:

## Q1:
1. Traverse the current BST in inorder and store it in a linked list.
2. Build a balanced binary search tree from a sorted linked list.
  
  2.1 Make the n/2 element the root
  
  2.2 Recursively do the same for the left half and the right half. Make the middle of the left half the left child of the root, and the middle of the right half as the right child of the root.
## Q2:
What you can mostly find on the internet is to store the current BST into an array and build a balanced BST on top of that. I didn't choose that method because I think dynamic array is prone to trigger errors. Linked list is a great candidate for this kind of task because it's flexibility of length. That's why I implemented the algorithm with linked list. 
## Q3:
Yes. I implementated the algorithm relying heavily on the "terse" insertion. Since when transferring the elements from a BST to a linked list, we need to append the element to the end of that linked list. Therefore we'll pass the a pointer of pointer of Linked list to our `store_BST_to_list`  method for dynamic allocation. 
It is also safer and simpler this way to avoid any NULL or out of range special cases. 