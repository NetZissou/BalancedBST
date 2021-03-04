#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"

int main(void) {
  struct node** head;
  *head = NULL;
  char user_input[MAX_STRING_LENGHT];
  /*Initialize a tree */
  struct BST *tree = NULL;
  /* ====================================== */
  /* ------- Prompt 1: BST type ------------*/
  /* ====================================== */
  printf("Would you like to produce a BST or a Balanced BST?\nEnter `b` to produce a Balanced BST, otherwise a BST will be produced.\nEnter: ");
  //fgets(user_input, MAX_STRING_LENGHT, stdin);
  //user_input[strlen(user_input)-1] = '\0';
  get_user_input(user_input);
  int user_choice_BST = strcmp(user_input, "b");
  if (user_choice_BST == 0) {
    printf("A Balanced BST will be generated.\n");
  } else {
    printf("A regluar BST will be generated.\n");
  }

  /* ====================================== */
  /* ------- Prompt 2: From a file? --------*/
  /* ====================================== */

  /* ------------- User Prompt -------------*/
  printf("Would you like the input of the tree to come from a file?\nEnter `Y` or `N`: ");
  get_user_input(user_input);
  while (strcmp(user_input, "Y") != 0 && strcmp(user_input, "N") != 0) {
    printf("Invalid input! Please enter `Y` or `N`: ");
    get_user_input(user_input);
  }
  int user_choice_fileinput = strcmp(user_input, "Y");

  /* ----- Load data from file into BST ---*/

  if (user_choice_fileinput == 0) {
    FILE *treeFile = NULL;
    do{
      printf("Please provide the file: \n");
      get_user_input(user_input);
      treeFile = fopen(user_input, "r");
      if (treeFile == NULL) {
        printf("Error: Unable to read the file. Please try again\n");
      }
    } while(treeFile == NULL);

    char content;
    while (1) { 
        content = fgetc(treeFile); 

        if (feof(treeFile)) 
            break; 
        
        tree = insert_node(content, tree);

        if (user_choice_BST == 0) {
          tree = construct_balanced_BST(tree, head);
        }
    }
    /* Close the file pointer after inserting the nodes */
    fclose(treeFile);
    printf("Here's your tree built from the file: \n");
    print_tree(tree, 0); 
    printf("You can perform the operation on the tree specified below: \n");
  }

  /* ====================================== */
  /* ----- Prompt 3: General Procedure -----*/
  /* ====================================== */
  do {
    print_user_option();
    get_user_input(user_input);
    if (strcmp(user_input, "a") == 0) {
      do {
        printf("Please provide a character: ");
        get_user_input(user_input);
        if (strlen(user_input) != 1) {
          printf("Invalid input: please enter specify one character\n");
        }
      } while(strlen(user_input) != 1);
      tree = insert_node(user_input[0], tree);
      if (user_choice_BST == 0) {
          tree = construct_balanced_BST(tree, head);
      }
      /* clear the userInput */
      user_input[0] = '\0';
    } 
    else if (strcmp(user_input, "r") == 0) {
      do{
        printf("Please specify the character that you want to remove: ");
        get_user_input(user_input);
        if (strlen(user_input) != 1) {
          printf("Invalid input: please enter specify one character\n");
        }
      }while(strlen(user_input) != 1);
      tree = remove_node(user_input[0], tree);
      /* clear the userInput */
      user_input[0] = '\0';
    } 
    else if(strcmp(user_input, "p") == 0) {
      if (tree == NULL) {
          printf("The tree is empty. Please consider inserting elements in the tree.\n");
        } else {
          print_tree(tree, 0);
      }
    }
    else if(strcmp(user_input, "q") == 0) {
      printf("Have a good one!\n");
    }
    else {
      printf("Invalid input option!\n");
    }
  } while(strcmp(user_input, "q"));

  return 0;
}

