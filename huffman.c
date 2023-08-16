/**
 * @author Elliot Pedersen (dv20epn@cs.umu.se)
 * 
 * @brief This is the main file of the huffman coding program.
 *
 * The user can either choose to encode or decode a file by entering either
 * "-encode" or "-decode" as the second argument. In total the program uses
 * three files to work, the frequency file which it bases it's frequency on,
 * the input file which is to be encoded or decoded, and lastly the output file
 * which is the input file in either encoded or decoded form.
 *
 * If the user chooses to encode a file, a frequency analysis will be performed
 * based on the first file that is entered. After that, the second file is encoded
 * based on the frequency analysis done on the first file. When all that is done
 * the result is stored in the last file that is entered. These are the
 * frequency file, input file and output file.
 * 
 * If the user chooses to decode a file, it will do about the same as when it
 * encodes a file only that it decodes the second file instead of encoding it.
 * So it reverses what is made when it encodes a file.
 * 
 * @date 2021-08-08
 * 
 * @copyright Copyright 2021 Elliot Pedersen (dv20epn@cs.umu.se).
 */

#include "huffman.h"

int main(int argc, const char *argv[])
{
  FILE *freqFile;
  FILE *inFile;
  FILE *outFile;

  if (validationOfIndata(argc, argv, &freqFile, &inFile, &outFile))
  {
    int *freq = frequencyCount(freqFile);

    struct pqueue *pq = createPqueue(freq);
    struct Node *tree = createTrie(pq);
    struct Table *table = createTable(tree);

    if (strncmp(argv[1], "-encode", 8) == 0)
    {
      encode(table, inFile, outFile);
    }

    if (strncmp(argv[1], "-decode", 8) == 0)
    {
      decode(tree, inFile, outFile);
    }

    free(freq);
    freeTree(tree);

    for (int i = 0; i < 256; i++)
    {
      bit_buffer_free(table[i].bit);
    }

    free(table);
  }

  fclose(freqFile);
  fclose(inFile);
  fclose(outFile);

  return 0;
}

void freeTree(struct Node *tree)
{
  if (tree == NULL)
  {
    return;
  }

  freeTree(tree->children[0]);
  freeTree(tree->children[1]);
  free(tree);
}

bool validationOfIndata(int argc, const char *argv[], FILE **freqFile, FILE **inFile,
                        FILE **outFile)
{
  if (argc != 5 || (strncmp(argv[1], "-encode", 8) != 0 && strncmp(argv[1], "-decode", 8) != 0) ||
      (*freqFile = fopen(argv[2], "r")) == NULL ||
      (*inFile = fopen(argv[3], "r")) == NULL ||
      (*outFile = fopen(argv[4], "w")) == NULL)
  {

    //Explains how the program is used.

    fprintf(stderr, "\nUSAGE:\nhuffman [OPTION] [FILE0] [FILE1] [FILE2]\nOptions: \n");
    fprintf(stderr, "-encode encodes FILE1 according to frequence analysis done on FILE0. Stores the result in FILE2\n");
    fprintf(stderr, "-decode decodes FILE1 according to frequence analysis done on FILE0. Stores the result in FILE2\n");

    fclose(*freqFile);
    fclose(*inFile);
    fclose(*outFile);

    return false;
  }

  return true;
}
