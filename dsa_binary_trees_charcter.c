#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<time.h>
FILE *File;

struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};



struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, char data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

void preorderTraversal(struct Node* root, FILE* file) {
    FILE* File = fopen("array.txt", "a+");
    double total;
    clock_t start,end;
    start=clock();
    if (root != NULL) {
        fprintf(file, "%c ", root->data);
        preorderTraversal(root->left, file);
        preorderTraversal(root->right, file);
    }
      end=clock();
    total =(double)(end-start)/CLOCKS_PER_SEC;
    fprintf(File," preorder time %f \n ",total);
}


void inorderTraversal(struct Node* root, FILE* file) {
    FILE* File = fopen("array.txt", "a+");
    double total;
    clock_t start,end;
    start=clock();
    if (root != NULL) {
        inorderTraversal(root->left, file);
        fprintf(file, "%c ", root->data);
        inorderTraversal(root->right, file);
    }
    end=clock();
    total =(double)(end-start)/CLOCKS_PER_SEC;
   fprintf(File," inorder time %f \n ",total);
}
void postorderTraversal(struct Node* root, FILE* file)
 {
    FILE* File = fopen("array.txt", "a+");
    double total;
    clock_t start,end;
    start=clock();
    if (root != NULL) {
        postorderTraversal(root->left, file);
        postorderTraversal(root->right, file);
        fprintf(file, "%c ", root->data);
    }
    end=clock();
    total =(double)(end-start)/CLOCKS_PER_SEC;
    fprintf(File," postorder time %f \n ",total);
}

int main() {
    srand(time(NULL));
     FILE* insertFile = fopen("randomoutput.txt", "w");
    FILE* preorderFile = fopen("preorder.txt", "w");
    FILE* postorderFile = fopen("postorder.txt", "w");
    FILE* inorderFile = fopen("inorder.txt", "w");


    int numCharacters;
    printf("Enter the number of random characters to generate: ");
    scanf("%d", &numCharacters);

    struct Node* root = NULL;
      int i;
    for (i = 0; i < numCharacters; i++)
        {
        char randomCharacter = 'a' + (rand() % 26);
        fprintf(insertFile," %c ",randomCharacter);
        root = insert(root, randomCharacter);
    }


    if (insertFile == NULL ||preorderFile == NULL  ||postorderFile == NULL || inorderFile == NULL)
        {
        printf("Error opening file. Make sure you have write permissions.\n");
        return 1;
    }


    fprintf(preorderFile, "Preorder traversal: ");
    fprintf(postorderFile, "Postorder traversal: ");
    fprintf(inorderFile, "Inorder traversal: ");


    preorderTraversal(root, preorderFile);
    postorderTraversal(root, postorderFile);
    inorderTraversal(root, inorderFile);

    fprintf(insertFile, "\n");
    fprintf(preorderFile, "\n");
    fprintf(postorderFile, "\n");
    fprintf(inorderFile, "\n");

    fclose(insertFile);
    fclose(preorderFile);
    fclose(postorderFile);
    fclose(inorderFile);

    printf("Traversals saved to files: insert.txt, preorder.txt, postorder.txt, inorder.txt\n");

    return 0;
}
