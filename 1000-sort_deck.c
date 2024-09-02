#include "deck.h"

/**
 * Instructions:
 *
 * - each node of the doubly linked list contains a card that we cannot modify;
 * - we have to swap the nodes;
 * - we can assume there is exactly 52 elements in the doubly linked list;
 * - we are free to use the sorting algorithm of our choice;
 *
 * - the deck must be ordered:
 *   ° from 'Ace' to 'King'
 *   ° from 'Spades' to 'Diamonds'.
 */


/**
 * swap_deck_nodes - program that swaps two nodes in a deck of playing cards
 *
 * this function is used to reposition nodes while maintaining the integrity of the doubly linked list;
 * this is a crucial operation in various card sorting algorithms;
 * it adjusts the links of the neighboring nodes to effectively swap the positions of the two nodes without
 * losing the list's continuity;
 * care should be taken to ensure that neither 'node1' nor 'node2' is the start or end of the deck
 * to avoid edge case errors
 *
 * @node1: a pointer to the first card node to be swapped
 * @node2: a pointer to the second card node to be swapped
 *
 * Return: nothing (void)
 */

void swap_deck_nodes(deck_node_t *node1, deck_node_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;

	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}



/**
 * sort_deck_insertion - program that sorts a deck of cards using the "Insertion sort" algorithm
 *
 * this function iteratively takes each card from the unsorted section, compares it with cards in the sorted section,
 * and inserts it in the correct position;
 * this process is repeated for all the cards in the deck
 *
 * @deck_list: a pointer to the head of the deck list of cards to be sorted (the starting point of the deck)
 *
 * Return: nothing (void)
 */

void sort_deck_insertion(deck_node_t **deck_list)
{
	deck_node_t *current_node, *compare_node;

	if (!deck_list || !*deck_list || !(*deck_list)->next)
		return;

	current_node = (*deck_list)->next;

	while (current_node)
	{
		compare_node = current_node;
		current_node = current_node->next;

		while (compare_node && compare_node->prev)
		{
			if (is_card_less_than(compare_node->prev->card, compare_node->card))
			{
				swap_deck_nodes(compare_node->prev, compare_node);

				if (!compare_node->prev)
					*deck_list = compare_node;
			}
			else
				compare_node = compare_node->prev;
		}
	}
}



/**
 * sort_deck - a wrapper program to sort a deck of cards
 *
 * this function calls the 'sort_deck_insertion' function to sort a deck of playing cards;
 * it provides an abstraction so that the sorting mechanism can be easily changed in the future without
 * altering the calling code
 *
 * @deck: a double pointer to the head of the deck list to be sorted
 *
 * Return: nothing (void)
 */

void sort_deck(deck_node_t **deck)
{
	sort_deck_insertion(deck);
}



/**
 * is_card_less_than - program that compares two cards to determine their relative order in a deck
 *
 * this function is a comparator and is used in sorting algorithms;
 * it compares two cards to determine if the first card is less than the second;
 * the comparison is based first on the kind of card and then on the value (so the kind of card takes precedence);
 * the function returns a truthy value if the first card is less than the second card;
 *
 * the function assumes standard card values and suits:
 * custom or non-standard decks may require modifications to the comparison logic
 *
 * @card1: a pointer to the first card to be compared --> should contain valid suit and value
 * @card2: a pointer to the second card to be compared --> should contain valid suit and value
 *
 * Return: 1 if 'card1' is less than 'card2' according to game rules, otherwise returns 0
 */

int is_card_less_than(const card_t *card1, const card_t *card2)
{
	char *compare_value1, *compare_value2, *card_values[] = {"King", "Queen", "Jack", "10",
								 "9", "8", "7", "6", "5",
								 "4", "3", "2", "Ace"};
	int card1_value_index = 0, card2_value_index = 0, index;

	for (index = 0; index < 13; index++)
	{
		for (compare_value1 = (char *)card1->value, compare_value2 = card_values[index];
		*compare_value1 && *compare_value1 == *compare_value2; ++compare_value1, ++compare_value2)
			;

		if (*compare_value1 == 0 && *compare_value2 == 0)
		{
			card1_value_index = index;
			break;
		}
	}
	for (index = 0; index < 13; index++)
	{
		for (compare_value1 = (char *)card2->value, compare_value2 = card_values[index];
		*compare_value1 && *compare_value1 == *compare_value2; ++compare_value1, ++compare_value2)
			;

		if (*compare_value1 == 0 && *compare_value2 == 0)
		{
			card2_value_index = index;
			break;
		}
	}
	if (card1->kind == card2->kind)
		return (card1_value_index < card2_value_index);

	return (card1->kind > card2->kind);
}
