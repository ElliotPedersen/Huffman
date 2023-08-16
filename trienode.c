/**
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

#include "trienode.h"

int *frequencyCount(FILE *freqFile)
{
  int total = 0;
  int *freq;
  freq = (int *)calloc(256, sizeof(int));

  int c;
  while ((c = fgetc(freqFile)) != EOF)
  {
    total++;
    freq[c]++;
  }

  return freq;
}

struct pqueue *createPqueue(int *freq)
{
  struct pqueue *pq = pqueue_empty(lessThan);

  int count = 0;
  for (int i = 0; i < 256; i++)
  {
    struct Node *trie_node = (struct Node *)calloc(3, sizeof(*trie_node));
    trie_node->freq = freq[i];
    trie_node->name = i;
    trie_node->children[0] = NULL;
    trie_node->children[1] = NULL;

    pqueue_insert(pq, trie_node);
    count++;
  }
  return pq;
}

struct Node *createTrie(struct pqueue *pq)
{
  struct Node *child1;
  struct Node *child2;
  struct Node *parent;
  int count = 0;

  while (!pqueue_is_empty(pq))
  {
    child1 = (struct Node *)pqueue_inspect_first(pq);
    pqueue_delete_first(pq);

    if (!pqueue_is_empty(pq))
    {
      child2 = (struct Node *)pqueue_inspect_first(pq);
      pqueue_delete_first(pq);

      parent = (struct Node *)calloc(3, sizeof(*parent));
      parent->children[0] = child1;
      parent->children[1] = child2;
      parent->freq = (child1->freq + child2->freq);

      pqueue_insert(pq, parent);
      count++;
    }
  }
  pqueue_kill(pq);
  return parent;
}

int lessThan(void *val1, void *val2)
{
  struct Node *v1 = val1, *v2 = val2;

  return v1->freq - v2->freq;
}
