/**
 * @defgroup freqtable_h Freqtable
 * 
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

#ifndef FREQTABLE_H
#define FREQTABLE_H

#include <stdio.h>
#include <stdlib.h>

#include "huffman.h"
#include "pqueue.h"
#include "list.h"
#include "bit_buffer.h"
#include "trienode.h"
#include "encode.h"
#include "decode.h"

/**
 * @brief               A structure used to store the frequence information.
 */
/*
 * @elem freq           The frequence of a certain symbol.
 * @elem name           The tag for the symbol. Which is the same as their
 *                      ascii number.
 * @elem *children[2]   An array with "pointers" to the left and right child
 *                      node.
 */
struct Node
{
  int freq;
  int name;
  struct Node *children[2];
};

/**
 * @brief              A structure used to store the bitsequences for a symbol
 *                     within a table.
 */
/*
 * @elem *bit          Stores the bitsekquence in a bit_buffer.
 */
struct Table
{
  struct bit_buffer *bit;
};

/**
 * @brief             Creates a frequency table which will contain 256
 *                    bitsequences for each element.
 *
 * @param *tree       The trie where the input data is stored.
 * @return            The new allocated table.
 */
struct Table *createTable(struct Node *tree);

/**
 * @brief             Fills the table with the elements and gives them their
 *                    bitsequences.
 *
 * @param *tree       The trie where the input data is stored.
 * @param *bb         The bitsequences
 * @param *table      The table to be filled.
 *
 */
void fillTable(struct Node *tree, struct bit_buffer *bb, struct Table *table);

#endif
