#include "hash_tables.h"

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    hash_table_t *ht;
    char *key;
    char *value;

    ht = hash_table_create(6);
    hash_table_set(ht, "c", "fun");
    hash_table_set(ht, "python", "awesome");
    hash_table_set(ht, "Bob", "and Kris love asm");
    hash_table_set(ht, "N", "queens");
    hash_table_set(ht, "Asterix", "Obelix");
    hash_table_set(ht, "Betty", "Cool");
    hash_table_set(ht, "98", "Battery Streetz");
    key = strdup("Tim");
    value = strdup("Britton");
    hash_table_set(ht, key, value);
    key[0] = '\0';
    value[0] = '\0';
    free(key);
    free(value);
    hash_table_set(ht, "98", "Battery Street"); 
    hash_table_set(ht, "hetairas", "Bob");
    hash_table_set(ht, "hetairas", "Bob Z");
    hash_table_set(ht, "mentioner", "Bob");
    hash_table_set(ht, "hetairas", "Bob Z Chu");
    hash_table_print(ht);

    printf("-----------------\n");

    printf("ht[%s] = %s\n", "c", hash_table_get(ht, "c"));
    printf("ht[%s] = %s\n", "BOb", hash_table_get(ht, "Bob"));
    printf("ht[%s] = %s\n", "NOT_HERE", hash_table_get(ht, "NOT_HERE"));
    printf("ht[%s] = %s\n", "NOT_HERE", hash_table_get(ht, "e"));
    printf("ht[%s] = %s\n", "NOT_HERE", hash_table_get(ht, "j"));
    printf("ht[%s] = %s\n", "98", hash_table_get(ht, "98"));

    hash_table_delete(ht);

    return (EXIT_SUCCESS);
}
