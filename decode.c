/**
 * @author Elliot Pedersen (dv20epn@cs.umu.se)
 * 
 * @brief Decodes the input file given by the user and prints
 * the result in the output file.
 *
 * @date 2021-08-08
 *
 * @copyright Copyright 2021 Elliot Pedersen (dv20epn@cs.umu.se).
 * @{
 */

#include "decode.h"

void decode(struct Node *tree, FILE *inFile, FILE *outFile)
{
  int character;

  struct Node *temp;

  struct bit_buffer *bb = bit_buffer_empty();

  // Get the size of the input file

  fseek(inFile, 0L, SEEK_END);
  long int size = ftell(inFile);
  rewind(inFile);

  for (int i = 0; i < size; i++)
  {
    character = fgetc(inFile);
    bit_buffer_insert_byte(bb, character);
  }

  while (bit_buffer_size(bb) > 0)
  {
    temp = tree;
    while (!(temp->children[0] == NULL && temp->children[1] == NULL))
    {
      int bit = bit_buffer_inspect_bit(bb, 0);

      if (bit == 0)
      {
        temp = temp->children[0];
        bit_buffer_remove_bit(bb);
      }

      if (bit == 1)
      {
        temp = temp->children[1];
        bit_buffer_remove_bit(bb);
      }

      if (bit == '\4')
      {
        break;
      }
    }

    if (temp->name == '\4' && bit_buffer_size(bb) == 0)
    {
      break;
    }

    if (fputc(temp->name, outFile) == EOF)
    {
      break;
    }
  }

  printf("File decoded successfully.\n");
  bit_buffer_free(bb);
}