#include <stdio.h>
#include <stdlib.h>
#define COUNT 5 
#define MAX_STRING_LENGHT 100
/* ---------------------------------------------------*/
/* ============ User Option I/O ======================*/
/* ---------------------------------------------------*/
/* TODO: address invalid option */
void print_user_option() {
  printf("Please selection from the following options: \n");
  printf("- Enter 'a' to add a node\n");
  printf("- Enter 'r' to remove a node\n");
  printf("- Enter 'p' to print the tree\n");
  printf("- Enter 'q' to quit\n");
}


void get_user_input(char user_input[]) {
  fgets(user_input, MAX_STRING_LENGHT, stdin);
  user_input[strlen(user_input)-1] = '\0';
}

/* ----------------------------------------------------*/
/* ===================== BST ==========================*/
/* ----------------------------------------------------*/
struct BST {
  char root;
  struct BST *left;
  struct BST *right;
};

struct list {
  char data;
  struct list *next;
};

struct BST* construct_tree(char data) {
  struct BST *tree;
  tree = malloc(sizeof(struct BST));
  tree -> root = data;
  tree -> left = NULL;
  tree -> right = NULL;

  return tree;
}

/* ------------------------------------------------------*/
/* ========= User Option Implementatio ==================*/
/* ------------------------------------------------------*/

/* When using terse void methods, always getting the complain about exited, segmentation fault */
struct BST* insert_node(char newdata, struct BST *tree) {
  if (tree == NULL) {
    return(construct_tree(newdata));
  }
  if (newdata <= tree->root) {
    tree->left = insert_node(newdata, tree->left);
  } else {
    tree->right = insert_node(newdata, tree->right);
  }
  return tree;
}

char search_smallest(struct BST *tree) {
  char smallest = tree->root;
  if(tree->left != NULL) 
    smallest = search_smallest(tree->left);
  return smallest;
}

struct BST* remove_node(char target, struct BST *tree) {
  if (target == tree->root) {
    if (tree->right == NULL) {
      tree = tree->left;
    } else {
      char right_smallest = search_smallest(tree->right);
      tree->root = right_smallest;
      tree->right = remove_node(right_smallest, tree->right);
    }
  } else if (target < tree->root) {
    tree->left = remove_node(target, tree->left);
  } else if (target > tree->root) {
    tree->right = remove_node(target, tree->right);
  }
  return tree;
}


void print_tree(struct BST *tree, int space) 
{ 
    // Base case 
    if (tree == NULL) 
        return; 

    space += COUNT; 

    print_tree(tree->right, space); 
  
    printf("\n"); 
    for (int i = COUNT; i < space; i++) 
        printf(" "); 
    printf("%c\n", tree->root); 

    print_tree(tree->left, space); 
}

/* ---------------------------------------------------*/
/* ================= Linked List =====================*/
/* ---------------------------------------------------*/

struct node {
    char dval;
    struct node *next;
};

int lenOfList(struct node *head) {
  struct node* current = head;
  int i = 0;
    while (current != NULL) {
        i++;
        current = current->next;
    }
  return i;
}
void print_list(struct node* head) {
    struct node* current = head;

    while (current != NULL) {
        printf("%c\n", current->dval);
        current = current->next;
    }
}

void push_end(struct node ** head, int val) {
  if (*head == NULL) {
    struct node * new_node;
    new_node = (struct node *) malloc(sizeof(struct node));

    new_node->dval = val;
    new_node->next = *head;
    *head = new_node;
  } else {
    struct node **current = head;
    while ((*current)->next != NULL) {
      current = &((**current).next);
    }
    /*End of the list where current->next is NULL*/
    (*current)->next = (struct node*) malloc(sizeof(struct node));
    (*current)->next->dval = val;
    (*current)->next->next = NULL;
  }
}

char get_val_at(int pos, struct node *head) {
  struct node* current = head;
  int i = 0;
    while (current != NULL && i < pos) {
        i++;
        current = current->next;
    }
  return current->dval;
}
/* -------------------------------------------------*/
/* ============== Balanced BST =====================*/
/* -------------------------------------------------*/
void store_BST_to_list(struct BST* tree, struct node** head) {
  if (tree == NULL) {
    return;
  }

  /*Store the tree in order*/
  store_BST_to_list(tree->left, head);
  push_end(head, tree->root);
  store_BST_to_list(tree->right, head);
}

struct BST* sorted_list_to_BST(struct node** head, int start, int end){
  /*Check if the length of the array is greater than one */
  if (start > end) {
    return NULL;
  }
  /* Make the middle element as the root */
  int mid = (start + end)/2;
  char midChar = get_val_at(mid, *head);
  struct BST *tree = construct_tree(midChar);
  tree->left = sorted_list_to_BST(head, start, mid-1);
  tree->right = sorted_list_to_BST(head, mid+1, end);

  return tree;
}

struct BST* construct_balanced_BST(struct BST *tree, struct node** head){
  store_BST_to_list(tree, head);
  int len = lenOfList(*head);
  struct BST *balanced_tree = sorted_list_to_BST(head, 0, len-1);
  *head = NULL;
  return balanced_tree;
}


