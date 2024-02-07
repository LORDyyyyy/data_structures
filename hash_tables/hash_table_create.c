#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table
 * @size: the size of the hash table
 *
 * Return: the address of the hash table
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	unsigned long int i = 0;
	hash_table_t *htable = NULL;
	hash_node_t **arr = NULL;

	htable = (hash_table_t *)malloc(sizeof(hash_table_t));
	if (!htable)
		return (NULL);

	arr = (hash_node_t **)malloc(sizeof(hash_node_t *) * size);
	if (!arr)
		return (NULL);

	for (; i < size; ++i)
		arr[i] = NULL;

	htable->size = size;
	htable->array = arr;

	return (htable);
}
