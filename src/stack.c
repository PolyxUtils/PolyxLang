typedef struct stack {
    struct stack *prev;
    void *data;
} stack;

stack *stack_new (void) 
{
    return NULL;
}

void stack_push(stack **pp_stack, void *data)
{
    if (pp_stack == NULL)
        return;

    stack *p_cur = *pp_stack;
    stack *p_new = NULL;
    
    p_new = malloc(sizeof(*p_new));

    if (p_new == NULL)  
    {
        fprintf(stderr, "Stack push error: Could not allocate heap memory");
        exit(EXIT_FAILURE);
    }

    p_new->data = data;
    p_new->prev = p_cur;
    
    *pp_stack = p_new;
}

void *stack_pop(stack **pp_stack)
{
    void *ret = NULL;
    
    if (pp_stack == NULL || *pp_stack == NULL)
        return ret;

    stack *p_top = *pp_stack;
    stack *p_pre = p_top->prev;

    ret = p_top->data;

    free(p_top);

    *pp_stack = p_pre;

    return ret;
}

void stack_delete(stack **pp_stack)
{
    if (pp_stack == NULL || *pp_stack == NULL)
        return;

    while (pp_stack != NULL)
        stack_pop(pp_stack);
}