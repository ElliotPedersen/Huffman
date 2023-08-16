/**
 * @defgroup trienode_h Trienode
 *
 * @author Elliot Pedersen (dv20epn@cs.umu.se)
 * 
 * @brief The trie node is a datatype that represents a trie that stores nodes.
 * The nodes contain a name that is represented by an ascii numver and also
 * the frequency of the character that the name represents.
 * 
 * @date 2021-08-08
 *
 * @copyright Copyright 2021 Elliot Pedersen (dv20epn@cs.umu.se).
 * @{
 */

#ifndef TRIE_NODE_H
#define TRIE_NODE_H

#include <stdio.h>
#include <stdlib.h>

#include "huffman.h"
#include "pqueue.h"
#include "list.h"
#include "bit_buffer.h"
#include "freqtable.h"
#include "encode.h"
#include "decode.h"

/**
 * @brief             Function used for comparing two elements.
 */
int lessThan(void *val1, void *val2);

/**
 * @brief             Reads the file and counts the frequence of each element
 *                    and stores it in an array where its index is their ascii
 *                    number.
 *
 * @param *freqFile   The file that will be read.
 * @return            The array with the frequence count.
 */
int *frequencyCount(FILE *freqFile);

/**
 * @brief             Creates a priority queue which will be prioritied so the
 *                    first element has the least value.
 *
 * @param *freq       The array with the frequence count.
 * @return            The new allocated pqueue.
 */
struct pqueue *createPqueue(int *freq);

/**
 * @brief             Creates a trie tree of of the frequence data from the
 *                    pqueue which priorities the element with highest frequency
 *                    to be closest to the root.
 *
 * @param *pq         The pqueue where the input data is stored.
 * @return            The new allocated trie.
 */
struct Node *createTrie(struct pqueue *pq);

#endif
