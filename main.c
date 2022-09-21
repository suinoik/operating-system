#include <stdio.h>
#include "list.h"

int main() 
{
  printf("Write your Tests for your linked list implementation\n");
  
  list_t *mylist;
  
  mylist = list_alloc();
  list_add_to_back(mylist, 3);
  list_add_to_back(mylist, 4);
  list_add_to_back(mylist, 2);
  list_add_to_back(mylist, 5);
  list_print(mylist);



  
  // printf("\nElement added is : %d\n",  mylist);


 
}
