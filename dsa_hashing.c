
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct DataItem {
    int key;
    int data;
};

struct DataItem* hashArray[SIZE];
struct DataItem* dummyItem;
struct DataItem* item;

int hashCode(int key) {
    return key % SIZE;
}

struct DataItem* search(int key) {
    // get the hash
    int hashIndex = hashCode(key);

    // search for the item
    while (hashArray[hashIndex] != NULL) {
        if (hashArray[hashIndex]->key == key) {
            return hashArray[hashIndex];
        }

        // go to the next cell
        ++hashIndex;

        // wrap around the table
        hashIndex %= SIZE;
    }

    return NULL;
}

void insert(int key, int data) {
    struct DataItem* item = (struct DataItem*)malloc(sizeof(struct DataItem));
    item->key = key;
    item->data = data;

    // get the hash
    int hashIndex = hashCode(key);

    // find an empty position or a deleted position
    while (hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
        // go to the next cell
        ++hashIndex;

        // wrap around the table
        hashIndex %= SIZE;
    }

    hashArray[hashIndex] = item;
}

struct DataItem* delete(struct DataItem* item) {
    int key = item->key;

    // get the hash
    int hashIndex = hashCode(key);

    // search for the item
    while (hashArray[hashIndex] != NULL) {
        if (hashArray[hashIndex]->key == key) {
            struct DataItem* temp = hashArray[hashIndex];

            // mark the position as deleted
            hashArray[hashIndex] = dummyItem;
            return temp;
        }

        // go to the next cell
        ++hashIndex;

        // wrap around the table
        hashIndex %= SIZE;
    }

    return NULL;
}

void display() {
    int i;
    for (i = 0; i < SIZE; i++) {
        if (hashArray[i] != NULL) {
            printf(" (%d,%d)", hashArray[i]->key, hashArray[i]->data);
        } else {
            printf(" --");
        }
    }
    printf("\n");
}

int main() {
    dummyItem = (struct DataItem*)malloc(sizeof(struct DataItem));
    dummyItem->key = -1;
    dummyItem->data = -1;

    int key, data;

    // User input for insertion
    printf("Enter key and data to insert (separated by a space): ");
    scanf("%d %d", &key, &data);
    insert(key, data);

    display();

    // User input for searching
    printf("Enter key to search: ");
    scanf("%d", &key);
    item = search(key);
    if (item != NULL) {
        printf("Element found: (%d,%d)\n", item->key, item->data);
    } else {
        printf("Element not found\n");
    }

    // User input for deletion
    printf("Enter key to delete: ");
    scanf("%d", &key);
    item = search(key);
    if (item != NULL) {
        delete(item);
        printf("Element deleted\n");
    } else {
        printf("Element not found\n");
    }

    display();

    return 0;
}
