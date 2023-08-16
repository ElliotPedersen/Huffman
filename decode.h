/**
 * @defgroup decode.h Decode
 * 
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

#ifndef DECODE_H
#define DECODE_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "huffman.h"
#include "pqueue.h"
#include "list.h"
#include "bit_buffer.h"
#include "freqtable.h"
#include "trienode.h"

/**
 * @brief            Decodes file 2 with the frequence analysis stored in
 *                   file 1 and stores the result in file 3.
 *
 * @param Table      The table containing the elements and their bitsequences.
 * @param in_file    File 2, input file.
 * @param out_file   File 3,, output file.
 *
 */
void decode(struct Node *tree, FILE *inFile, FILE *outFile);

#endif