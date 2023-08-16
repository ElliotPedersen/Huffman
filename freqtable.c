/**
 * @author Elliot Pedersen (dv20epn@cs.umu.se)
 * 
 * @brief The frequency table is a datatype that can store all the elements and their
 * corresponding frequencies and therefore give them a fitting bitsequence.
 *
 * @date 2021-08-08
 *
 * @copyright Copyright 2021 Elliot Pedersen (dv20epn@cs.umu.se).
 * @{
 */

#include "freqtable.h"

struct Table *createTable(struct Node *tree)
{
  struct Table *table = calloc(256, sizeof(struct Table));

  struct bit_buffer *bb = bit_buffer_empty();
  fillTable(tree, bb, table);

  bit_buffer_free(bb);
  return table;
}

void fillTable(struct Node *tree, struct bit_buffer *bb, struct Table *table)
{

  if (tree->children[1] == NULL && tree->children[0] == NULL)
  {
    table[tree->name].bit = bit_buffer_copy(bb);
  }

  else
  {
    if (tree->children[0] != NULL)
    {

      struct bit_buffer *bb_0 = bit_buffer_copy(bb);
      bit_buffer_insert_bit(bb_0, 0);

      fillTable(tree->children[0], bb_0, table);
      bit_buffer_free(bb_0);
    }

    if (tree->children[1] != NULL)
    {

      struct bit_buffer *bb_1 = bit_buffer_copy(bb);
      bit_buffer_insert_bit(bb_1, 1);

      fillTable(tree->children[1], bb_1, table);
      bit_buffer_free(bb_1);
    }
  }
}

void printTable(struct Table *table)
{
  for (int i = 0; i < 256; i++)
  {
    printf("%c: %s\n", i, bit_buffer_to_string(table[i].bit));
  }
}
