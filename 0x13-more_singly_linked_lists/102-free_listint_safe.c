/**
 * free_listint_safe - Frees a listint_t list safely (i.e., it can free lists containing loops)
 * @h: A pointer to the address of the head of the listint_t list.
 *
 * Return: The size of the list that was freed.
 *
 * Description: The function sets the head to NULL.
 */
size_t free_listint_safe(listint_t **h)
{
    listint_t *tmp;
    size_t nodes = 0;

    while (*h != NULL)
    {
        nodes++;
        if (*h <= (*h)->next)
        {
            free(*h);
            break;
        }
        tmp = (*h)->next;
        free(*h);
        *h = tmp;
    }
    *h = NULL;

    return (nodes);
}
