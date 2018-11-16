#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);
  Answer *answer = malloc(sizeof(Answer));

  for (int i = 0; i < length; i++){
    hash_table_insert(ht, weights[i], i);
  }

  for (int j = 0; j < length; j++){
    int index = hash_table_retrieve(ht, limit-weights[j]);
    if (index != -1){
      if (j > index){
        answer->index_1 = j;
        answer->index_2 = index;
      }
      answer->index_1 = index;
      answer->index_2 = j;
      destroy_hash_table(ht);
      return answer;
    }
  }

  return NULL;
}

void print_answer(Answer *answer)
{
  if (answer != NULL) {
    printf("%d %d\n", answer->index_1, answer->index_2);
  } else {
    printf("NULL\n");
  }
}