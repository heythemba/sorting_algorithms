#ifndef DECK_H
#define DECK_H


#include <stdio.h>


/**
 * enum kind_e - enumeration representing the suit of a playing card
 *
 * @SPADE: denotes the spade suit (0)
 * @HEART: denotes the heart suit (1)
 * @CLUB: denotes the club suit (2)
 * @DIAMOND: denotes the diamond suit (3)
 */

typedef enum kind_e
{
    SPADE = 0,
    HEART,
    CLUB,
    DIAMOND
} kind_t;



/**
 * struct card_s - structure representing a playing card
 *
 * @value: the value of the card (from "Ace" to "King")
 * @kind: the suit of the card, as defined in enum kind_e
 */

typedef struct card_s
{
    const char *value;
    const kind_t kind;
} card_t;



/**
 * struct deck_node_s - structure that represents a node in a doubly linked list, used to model a deck of playing cards
 *
 * each node contains a card and pointers to the previous and next nodes in the list,
 * allowing for bidirectional traversal
 *
 * @card: a pointer to the card data, which includes the card's value and suit
 * @prev: a pointer to the previous node in the deck (if this is the first node, 'prev' will be NULL)
 * @next: a pointer to the next node in the deck (if this is the last node, 'next' will be NULL)
 */

typedef struct deck_node_s
{
    const card_t *card;
    struct deck_node_s *prev;
    struct deck_node_s *next;
} deck_node_t;



void swap_deck_nodes(deck_node_t *node1, deck_node_t *node2);
void sort_deck_insertion(deck_node_t **deck_list);
void sort_deck(deck_node_t **deck);
int is_card_less_than(const card_t *card1, const card_t *card2);


#endif /* DECK_H */
