// list/list.c
//
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

#include "list.h"

list_t *list_alloc() { 
  list_t* list = (list_t*)malloc(sizeof(list_t));
  list->head = NULL;
  return list;
  }
void list_free(list_t *l) {
  node_t *current = l -> head;
  while (current){
    node_t *temp = current;
    current = current->next;
    free(temp);
  }
  free(l->head);
  l->head = NULL;

}


node_t* node_alloc() {
  node_t* list = (node_t*)malloc(sizeof(node_t));
  list->next = NULL;
  return list;
}

void node_free(node_t *n) {
  free(n);
  }
void list_print(list_t *l) {
  node_t *current = l->head;
  while (current){
    printf("%d " , current->value);
    current = current->next;
  }
}
int list_length(list_t *l) { 
  node_t *current = l->head;
  int numval = 0;
  while(current){
    numval++;
    current = current->next;
  }
  return numval;
    }

void list_add_to_back(list_t *l, elem value) {
  node_t *end = node_alloc();
  end->value = value;
  node_t *current = l->head;
  if(l->head){
    while(current ->next){
      current = current->next;
    }
    current->next = end;
  }
  else{
    l->head = end;
  }
}

void list_add_to_front(list_t *l, elem value) {
  node_t *beginning = node_alloc();
  // node_t *front = node_alloc();
  beginning->value = value;

  if(l->head == NULL){
    l->head = beginning;
  }
  else{
    beginning->next = l->head;
    // l->beginning = front;
  }

}
void list_add_at_index(list_t *l, elem value, int index) {
  node_t *pointer = node_alloc();
  pointer->value = value;

  if(index == 0){
    list_add_to_front(l, value);
  }
  else{
  int check = 0;
  node_t *start1 = l->head;
  while(check < index - 1){
    start1 = start1->next;
    check += 1;
  }
  pointer->next = start1->next;
  start1->next = pointer;
}
  }
  // else{
  //   l->head = pointer;
  // }

elem list_remove_from_back(list_t *l) {
  node_t *back = node_alloc();
  // end->value = value;
  node_t *current = l->head;
  if(l->head){
    while(current ->next){
      current = current->next;
    }
    // current->next = back;
  }
  else{
    l->head = back;
  }
}
elem list_remove_from_front(list_t *l) { 
  node_t *temp = l -> head;
  if (temp != NULL){
  l -> head = temp -> next;
  elem val = temp->value;
  free(temp);
  return temp -> value;
  }
  return -1; 
  }
elem list_remove_at_index(list_t *l, int index) { 
  node_t *temp = l -> head;
  int i;
  if (index == 0){
    temp = temp->next;
    temp->next = NULL;
    free(temp);
  }
  else{
    for(i=0; i < index - 1; i++){
      temp = temp->next;
    }
    node_t* del = temp->next;
    temp->next = temp->next->next;
    printf("\nElement deleted is : %d\n", del->value);
    del->next = NULL;
    free(del);
  }
}

bool list_is_in(list_t *l, elem value) {
   if (l->head == NULL){
    return false;
  }
  else{
    node_t *current = l->head;
    while(current){
      if (current->value == value){
        return true;
      }
      current = current->next;
    }
  }
  return false; 
  }
elem list_get_elem_at(list_t *l, int index) { int counter = 0;
  node_t *current = l->head;
  if (l->head){
    while(counter != index){
      current = current->next;
      counter++;
    }
    return current->value;
  }
  else{
    return -1;
  }
} 
int list_get_index_of(list_t *l, elem value) {
  if (l->head == NULL){
    return -1;
  }
  else{
    int counter = 0;
    node_t *current = l->head;
    while(current){
      if (current->value == value){
        return counter;
      }
      current = current->next;
      counter++;
    }
  }
  return -1;
 }
