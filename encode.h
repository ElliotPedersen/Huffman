/**
 * @defgroup encode.h Encode
 * 
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

#ifndef ENCODE_H
#define ENCODE_H

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
 * @brief            Encodes file 2 with the frequence analysis stored in
 *                   file 1 and stores the result in file 3.
 *
 * @param Table      The table containing the elements and their bitsequences.
 * @param in_file    File 2, input file.
 * @param out_file   File 3,, output file.
 *
 */
void encode(struct Table *table, FILE *inFile, FILE *outFile);

#endif