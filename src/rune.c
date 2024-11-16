typedef struct String {
    size_t len;
    size_t alloc_len;
    rune *data;
} String;

void String_new(String *str)
{
    *str = (String) {0, 0, NULL};
}

void String_add(String *str, rune data)
{
    if (str == NULL)
        return;

    if (str->len >= str->alloc_len)
    {
        size_t new_alloc = str->alloc_len + (str->alloc_len >> 2) + 2;
        
        rune *new_data = NULL;
        new_data = malloc(new_alloc * sizeof(rune));

        if (new_data == NULL)
        {
            fprintf(stderr, "String add error: Could not allocate heap memory");
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i < str->len; i++)
            new_data[i] = str->data[i];

        if (str->data != NULL)
            free(str->data);

        str->alloc_len = new_alloc - 1;  
        str->data = new_data;
        str->data[str->alloc_len] = (rune) 0; // Make sure String is null terminated
    }

    str->data[str->len++] = data;
}

bool rune_in_arr(rune *str, rune c)
{
    int i = 0;

    while (str[i] != 0) 
    {
        if (str[i] == c)
            return TRUE;

        i++;
    }

    return FALSE;
}

rune String_get(String *str, size_t n)
{
    if (n >= str->len)
    {
        fprintf(stderr, "List get error: Index OoB");
        exit(EXIT_FAILURE);
    }

    return str->data[n];
}

void String_put(String *str)
{
    write(1, str->data, str->len << 2);
}

void putrune(rune *c)
{
    write(1, c, 4);
}

size_t rune_strlen(rune *str)
{
    size_t len = 0;
    while (*(str++) != 0)
        len += 1;

    return len;
}

rune fgetrune(FILE *fd)
{
    short unsigned len = 0;
    char c = fgetc(fd);
    rune ru = c & 0xFF;
    if (c == EOF)
        return ru;
        

    if ((c & 0xF0) == 0xF0)
        len = 3;
    else if ((c & 0xE0) == 0xE0)
        len = 2;
    else if ((c & 0xC0) == 0xC0)
        len = 1; 

    short unsigned charNum = 1;
    while (len-- > 0 && (c = fgetc(fd)) != EOF)
            ru |= (c & 0xFF) << (charNum++ << 3);

    return ru;
}