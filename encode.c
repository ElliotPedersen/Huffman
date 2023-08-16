/**
 * @author Elliot Pedersen (dv20epn@cs.umu.se)
 * 
 * @brief Encodes the input file given by the user and prints
 * the result in the output file.
 *
 * @date 2021-08-08
 *
 * @copyright Copyright 2021 Elliot Pedersen (dv20epn@cs.umu.se).
 * @{
 */

#include "encode.h"

void encode(struct Table *table, FILE *inFile, FILE *outFile)
{
  int c = fgetc(inFile);
  
  struct bit_buffer *temp = bit_buffer_empty();

  while (c != EOF)
  {
    int size = bit_buffer_size(table[c].bit);

    for (int i = 0; i < size; i++)
    {
      bit_buffer_insert_bit(temp, bit_buffer_inspect_bit(table[c].bit, i));

      if (bit_buffer_size(temp) == 9)
      {
        fprintf(outFile, "%c", bit_buffer_remove_byte(temp));
      }
    }
    c = fgetc(inFile);
  }

  fprintf(outFile, "%c", 4);

  fseek(inFile, 0L, SEEK_END);
  int inFileSize = ftell(inFile);

  fseek(outFile, 0L, SEEK_END);
  int outFileSize = ftell(outFile);

  printf("\n%d bytes read from infil.txt.\n", inFileSize);
  printf("%d bytes used in encoded form.\n", outFileSize);

  bit_buffer_free(temp);
}