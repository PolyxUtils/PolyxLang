#include "stack.h"
#include "queue.h"
//#include "list.h" This does not work yet !
#include "rune.h"
#include "bool.h"

#include <unistd.h>

typedef enum token_def {
    NONE = 0b000,
    OPERAND = 0b001,
} token_def;

typedef struct token {
    String value;
    token_def def;
} token;

queue *file_to_queue(char *fd_str)
{
    rune c;
    rune *ptr_c;
    FILE *fd;

    queue *file_q = queue_new();

    fd = fopen(fd_str, "r");

    if (fd == NULL) 
    {
        fprintf(stderr, "Error opening file");
        exit(EXIT_FAILURE);
    }

    while ((c = fgetrune(fd)) != WEOW)
    {
        ptr_c = malloc( sizeof(rune)/* =4 */ );
        *ptr_c = c;
        queue_append(&file_q, (void *) ptr_c);
    }

    fclose(fd); 

    return file_q;
}

queue *create_tokens(queue *file_q)
{
    rune *ptr_c;
    token_def cur_type = NONE;
    size_t cur_token;

    queue *token_q = queue_new();

    token *cur_tk = malloc(sizeof(token));
    cur_tk->def = NONE;
    String_new(&cur_tk->value);

    while ((ptr_c = queue_pop(&file_q)) != NULL)
    {        
        if (rune_in_arr(token_separator_String, *ptr_c))
        {
            queue_append(&token_q, (void *) cur_tk);

            cur_tk = malloc(sizeof(token));
            cur_tk->def = NONE;
            String_new(&cur_tk->value);

            if 
        }
        
        String_add(&cur_tk->value, *ptr_c);
        free(ptr_c);
    }

    queue_append(&token_q, (void *) cur_tk);

    return token_q;
}

queue *merge_tokens(queue *token_q)
{
    token *cur_tk;
    token *new_tk;

    queue ret_q = queue_new();

    while ((cur_tk = queue_pop(&token_q)) != NULL)
    {
        String_put(&ptr_tk->value);
        puts("");        
    }
}

int main()
{
    rune *ptr_c;

    queue *file_q = file_to_queue("ressources/cactus.txt");

    token *ptr_tk;
    queue *token_q = create_tokens(file_q);

    while ((ptr_tk = queue_pop(&token_q)) != NULL)
    {
        switch 
    }

    return 0;
}