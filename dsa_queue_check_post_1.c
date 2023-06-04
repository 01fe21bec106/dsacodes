#include <stdio.h>
 #include <string.h>
  #include <stdlib.h>
   #include <stdbool.h>
   #define MAX 6
   int intArray[MAX];
    int front = 0;
     int rear = -1;
      int itemCount = 0;
       bool isFull()
       { return
       itemCount == MAX;
        }
        bool isEmpty()
        {
            return
            itemCount == 0;
            }
            void insert(int data)
            { if(!isFull())
            { if(rear == MAX-1)
             { rear = -1;
             } intArray[++rear] = data;
              itemCount++;
              } }
              int removeData()
              { int data = intArray[front++];
               if(front == MAX)
                    { front = 0;
               } itemCount--;
               return data;
               } int main()
               { int i;
                insert(3);
                 insert(5);
                 insert(9);
                 insert(1);
                 insert(12);
                 insert(15);
                 printf("Queue: ");
                  for(i = 0; i < MAX; i++)
                    printf("%d ", intArray[i]);
               }
