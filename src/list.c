typedef struct list {
    size_t len;
    size_t alloc_len;
    void **data;
} list;

void list_new(list *arr)
{
    *arr = (list) {0, 0, NULL};
}

void list_append(list *arr, void *data)
{
    if (arr == NULL)
        return;

    if (arr->len >= arr->alloc_len)
    {
        size_t new_alloc = arr->alloc_len + (arr->alloc_len >> 2) + sizeof(void *);
        
        void **new_data = NULL;
        new_data = malloc(new_alloc);

        if (new_data == NULL)
        {
            fprintf(stderr, "List append error: Could not allocate heap memory");
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i < arr->len; i++)
            new_data[i] = arr->data[i];

        arr->alloc_len = (new_alloc) >> 3;
        arr->data = new_data;
    }

    arr->data[arr->len++] = data; 
}

void *list_pop(list *arr, size_t n)
{
    void *ret = NULL;

    if (arr == NULL)
        return NULL;

    if (n >= arr->len)
    {
        fprintf(stderr, "List pop error: Index OoB");
        exit(EXIT_FAILURE);
    }

    ret = arr->data[n];

    for (int i = n; i < arr->len - 1; i++)
    {
        arr->data[i] = arr->data[i + 1];
    }

    arr->len--;

    return ret;
}

void *list_get(list *arr, size_t n)
{
    if (n >= arr->len)
    {
        fprintf(stderr, "List get error: Index OoB");
        exit(EXIT_FAILURE);
    }

    return arr->data[n];
}
