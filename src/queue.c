typedef struct queue 
{
    struct queue *prev;
    struct queue *next;
    void *data;
} queue;

queue *queue_new(void)
{
    return (NULL);
}

void queue_append(queue **pp_queue, void *data)
{
    if (pp_queue == NULL)
        return;

    queue *p_cur = *pp_queue;
    queue *p_new = NULL;

    p_new = malloc(sizeof(*p_new));

    if (p_new == NULL)
    {
        fprintf(stderr, "Queue append error: Could not allocate heap memory");
        exit(EXIT_FAILURE);
    }

    if (p_cur != NULL)
    {
        while (p_cur->next != NULL)
            p_cur = p_cur->next;

        p_cur->next = p_new;
    } else {
        *pp_queue = p_new;
    }

    p_new->prev = p_cur;
    p_new->next = NULL;
    p_new->data = data; 
}

void *queue_pop(queue **pp_queue)
{
    void *ret = NULL;

    if (pp_queue == NULL || *pp_queue == NULL)
        return ret;

    queue *p_cur = *pp_queue; 
    queue *p_next = p_cur->next;

    ret = p_cur->data;
    free(p_cur);
    
    if (p_next != NULL)
        p_next->prev = NULL;

    *pp_queue = p_next;
    return ret;
}
