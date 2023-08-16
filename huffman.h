/**
 * \mainpage HUFFMANCODING
 *
 * This is a program that uses huffman coding to either encode or 
 * decode a text file. Encoding means that the the file is compressed
 * so it uses less space on the computers storage and decoding means that
 * it reverts the encoded file to readable text again. The program uses
 * three files. A frequency file, a input file and an output file.
 * The frequency file is used to make a frequency analysis that is used to 
 * determine what character is used the most. Thereafter the frequency is 
 * applied to the input file which is a longer text file that we want to
 * compress. After the input file is compressed, the result is stored in 
 * the output file.
 *
 * This program is made up of fourteen files in total six of which were premade
 * and the rest were not. Half of all the files are c-files and the other half
 * are h-files.
 * 
 * Premade files:
 * 
 * Bit_buffer - A bit buffer is the most vital part of the encoding
 * and decoding part of the program. It is what translates the characters.
 * 
 * List - The ADT of a list which is used within the program.
 * 
 * Pqueue - The ADT of a priority queue which is used in the program.
 * 
 * Non-premade files:
 *
 * Huffman - The main file.
 *
 * Freqtable - Makes the frequence analysis and creates the frequency table.
 *
 * Trienode - A module for the trie node and creates the trie tree.
 *
 * Encodedecode - Encodes or decodes the input file and prints the result in
 * the output file.
 */

/**
 * @defgroup huffman_h Huffman
 *
 * @author  Elliot Pedersen (dv20epn@cs.umu.se)
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
 * @param argc The number of arguments.
 * @param *argv[] The arguments.
 *
 * @date 2021-08-08
 * 
 * @copyright Copyright 2021 Elliot Pedersen (dv20epn@cs.umu.se).
 * @{
 */

#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "pqueue.h"
#include "list.h"
#include "bit_buffer.h"
#include "freqtable.h"
#include "trienode.h"
#include "encode.h"
#include "decode.h"

/**
 * @brief Checks if the three files the user enters are valid.
 *
 * Checks if the three files the user enters are valid. If they are valid, the 
 * function returns true. If they are not valid the function will return false,
 * and instructions on how to use the program the proper way are printed.
 *
 * @param argc The ammount of arguments.
 * @param argv The arguments.
 * @param freqFile The file that the frequency analysis will be based on.
 * @param inFile The file that is to be decoded or encoded.
 * @param outFile The file where the results will be stored.
 * @return bool.
 */

bool validationOfIndata(int argc, const char *argv[], FILE **freqFile, FILE **inFile,
                        FILE **outFile);

/**
* @brief Deallocates the tree.
*
* Deallocates the tree.
*
* @param tree The specific tree to be deallocated.
*
*/

void freeTree(struct Node *tree);

#endif
