#include <stdio.h>

#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_SIZE 10
#define STR_ARRAY_LEN 50
#define SENTINAL_CHAR '~'
#define IS_GREATER 1
#define IS_LESSER -1
#define IS_EQUAL 0

typedef struct doc_
{
    char doc_name[MAX_WORD_SIZE];
    struct doc_ *next_doc;
} doc;
typedef struct node_tag
{
    struct node_tag *prev;
    char word[MAX_WORD_SIZE];
    doc *docs;
    struct node_tag *next;
} node;
void format_doc(FILE *fp, char *name)
{
    FILE *f_new = fopen(name, "w");
    fseek(fp, 0, SEEK_SET);
    char c = '\0';
    while (!feof(fp))
    {
        char str[MAX_WORD_SIZE] = "\0";
        int str_index = 0;
        while (isalnum(c = fgetc(fp)))
        {
            if (c >= 'A' && c <= 'Z')
                c = c - 'A' + 'a';
            str[str_index++] = c;
        }
        while (str_index > 0 && str_index < MAX_WORD_SIZE - 1)
            str[str_index++] = SENTINAL_CHAR;
        str[str_index] = '\0';
        if (str_index != 0)
        {
            // printf("In format_doc we're writing ::
            //  %s\n",str);
            fwrite(str, sizeof(char), MAX_WORD_SIZE, f_new);
        }
    }
    fclose(f_new);
    return;
}
void sort_strings(char str[STR_ARRAY_LEN][MAX_WORD_SIZE])
{
    for (int i = MAX_WORD_SIZE - 1; i >= 0; i--)
    {
        int count[37] = {0};
        for (int j = 0; j < STR_ARRAY_LEN; j++)
        {
            if (isdigit(str[j][i]))
                count[str[j][i] -
                      '0' + 27]++;
            else if (isalpha(str[j][i]))
                count[str[j][i] -
                      'a' + 1]++;
            else if (str[j][i] == SENTINAL_CHAR)
                count[0]++;
        }
        int pos[37] = {0};
        for (int m = 1; m < 37; m++)
        {
            pos[m] = pos[m - 1] + count[m - 1];
        }
        char temp[STR_ARRAY_LEN][MAX_WORD_SIZE];
        for (int k = 0; k < STR_ARRAY_LEN; k++)
        {
            if (isdigit(str[k][i]))
                strcpy(temp[pos[str[k][i] - '0' + 27]++], str[k]);
            else if (isalpha(str[k][i]))
                strcpy(temp[pos[str[k][i] - 'a' + 1]++], str[k]);
            else
                strcpy(temp[pos[0]++], str[k]);
        }
        for (int l = 0; l < STR_ARRAY_LEN; l++)
            strcpy(str[l], temp[l]);
    }
    return;
}
int comp_strings(char str1[MAX_WORD_SIZE], char
                                               str2[MAX_WORD_SIZE])
{
    for (int i = 0; i < MAX_WORD_SIZE - 1; i++)
    {
        if (str1[i] == SENTINAL_CHAR || str2[i] ==
                                            SENTINAL_CHAR)
        {
            if (str2[i] != SENTINAL_CHAR)
                return IS_LESSER;
            else if (str1[i] != SENTINAL_CHAR)
                return IS_GREATER;
            else
                continue;
        }
        else if (isalpha(str1[i]) && isalpha(str2[i]))
        {
            if (str1[i] > str2[i])
                return IS_GREATER;
            else if (str1[i] < str2[i])
                return IS_LESSER;
            else
                continue;
        }
        else if (isdigit(str1[i]) || isdigit(str2[i]))
        {
            if (!isdigit(str2[i]))
                return IS_GREATER;
            else if (!isdigit(str1[i]))
                return IS_LESSER;
            else
                continue;
        }
    }
    return IS_EQUAL;
}
doc *create_doc(const char doc_name[MAX_WORD_SIZE])
{
    doc *doc_head = (doc *)malloc(sizeof(doc));
    strcpy(doc_head->doc_name, doc_name);
    doc_head->next_doc = NULL;
    return doc_head;
}
void append_doc(node *elem, char doc_name[MAX_WORD_SIZE])
{
    doc *doc_tmp = elem->docs;
    while (doc_tmp != NULL)
    {
        if (strcmp(doc_tmp->doc_name, doc_name) == IS_EQUAL)
            return;
        if (doc_tmp->next_doc != NULL)
            doc_tmp = doc_tmp->next_doc;
        else
            break;
    }
    doc_tmp->next_doc = create_doc(doc_name);
}
node *create_node(const char str[MAX_WORD_SIZE], const char
                                                     doc_name[MAX_WORD_SIZE])
{
    node *temp = (node *)malloc(sizeof(node));
    temp->prev = NULL;
    strcpy(temp->word, str);
    temp->docs = create_doc(doc_name);
    temp->next = NULL;
    return temp;
}
void insert_front(node **head, char str[MAX_WORD_SIZE], char doc_name[MAX_WORD_SIZE])
{
    node *temp = create_node(str, doc_name);
    (*head)->prev = temp;
    temp->next = *head;
    *head = temp;
}
void insert_after(node *elem, char str[MAX_WORD_SIZE], char doc_name[MAX_WORD_SIZE])
{
    node *temp = create_node(str, doc_name);
    temp->next = elem->next;
    temp->prev = elem;
    if (temp->next != NULL)
        temp->next->prev = temp;
    elem->next = temp;
    return;
}
void place_elem(node **head, char str[STR_ARRAY_LEN][MAX_WORD_SIZE], char doc_name[MAX_WORD_SIZE])
{
    char duplicate[MAX_WORD_SIZE] = "\0";
    strcpy(duplicate, str[0]);
    int start_index = 0;
    while (str[start_index][0] == SENTINAL_CHAR)
        start_index++;
    if (*head == NULL)
    {
        *head = create_node(str[start_index], doc_name);
        node *curr = *head;
        for (int i = start_index + 1; i < STR_ARRAY_LEN; i++)
        {
            if (comp_strings(duplicate, str[i]) != IS_EQUAL)
            {
                insert_after(curr, str[i], doc_name);
                strcpy(duplicate, str[i]);
                curr = curr->next;
            }
            else
                continue;
        }
    }
    else
    {
        if (comp_strings(str[start_index], (*head)->word) ==
            IS_LESSER)
            insert_front(head, str[start_index++], doc_name);
        node *curr = *head;
        for (int i = start_index; i < STR_ARRAY_LEN; i++)
        {
            while (comp_strings(str[i], curr->word) ==
                   IS_GREATER)
            {
                if (curr->next != NULL)
                    curr = curr->next;
                else
                    break;
            }
            if (comp_strings(str[i], curr->word) == IS_GREATER)
                insert_after(curr, str[i], doc_name);
            else if (comp_strings(str[i], curr->word) == IS_EQUAL)
                append_doc(curr, doc_name);
            else
                insert_after(curr->prev, str[i], doc_name);
        }
    }
    return;
}
void print_dict(node *head)
{
    while (head != NULL)
    {
        for (int i = 0; i < MAX_WORD_SIZE; i++)
            if (head->word[i] != SENTINAL_CHAR)
                printf("%c", head->word[i]);
            else
                printf(" ");
        printf("\t");
        doc *tmp = head->docs;
        while (tmp != NULL)
        {
            printf("<---->%s", tmp->doc_name);
            tmp = tmp->next_doc;
        }
        printf("\n");
        head = head->next;
    }
    return;
}

void i_STR_list(char str_arr[STR_ARRAY_LEN][MAX_WORD_SIZE])
{
    for (int i = 0; i < STR_ARRAY_LEN; i++)
    {
        for (int j = 0; j < MAX_WORD_SIZE - 1; j++)
            str_arr[i][j] = SENTINAL_CHAR;
        str_arr[i][MAX_WORD_SIZE - 1] = '\0';
    }
    return;
}
void dict_add_from(char doc_name[MAX_WORD_SIZE], node **
                                                     head)
{
    FILE *fp;
    fp = fopen(doc_name, "r");
    if (fp == NULL)
    {
        printf("No such file exists, skipping....\n");
        return;
    }
    format_doc(fp, "formatted");
    fclose(fp);
    fp = fopen("formatted", "r");
    char str[MAX_WORD_SIZE] = "\0";
    char str_arr[STR_ARRAY_LEN][MAX_WORD_SIZE];
    int i = 0;
    int fread_c = 0;
    i_STR_list(str_arr);
    while ((fread_c = fread(str, sizeof(char), MAX_WORD_SIZE, fp)))
    {
        strcpy(str_arr[i % STR_ARRAY_LEN], str);
        i++;
        if (i % STR_ARRAY_LEN == 0 && i != 0)
        {
            sort_strings(str_arr);
            place_elem(head, str_arr, doc_name);
            i_STR_list(str_arr);
        }
    }
    if (i % STR_ARRAY_LEN != 0 && i != 0)
    {
        sort_strings(str_arr);
        place_elem(head, str_arr, doc_name);
        i_STR_list(str_arr);
    }
    return;
}
void search_rec(char query[MAX_WORD_SIZE], node *head)
{
    static node *prev_req = NULL;
    if (prev_req == NULL)
        prev_req = head;
    char formatted_q[MAX_WORD_SIZE];
    int encountered = 0;
    for (int i = 0; i < MAX_WORD_SIZE - 1; i++)
    {
        if (query[i] == '\0')
            encountered = 1;
        if (!encountered)
            formatted_q[i] = query[i];
        else
            formatted_q[i] = SENTINAL_CHAR;
    }
    if (comp_strings(formatted_q, prev_req->word) ==
        IS_LESSER)
    {
        while (comp_strings(formatted_q, prev_req->word) !=
               IS_EQUAL)
        {
            if (prev_req->prev != NULL)
                prev_req = prev_req->prev;
            else
            {
                printf("Your query cannot be found in DB\n");
                return;
            }
        }
    }
    else if (comp_strings(formatted_q, prev_req->word) ==
             IS_GREATER)
    {
        while (comp_strings(formatted_q, prev_req->word) !=
               IS_EQUAL)
        {
            if (prev_req->next != NULL)
                prev_req = prev_req->next;
            else
            {
                printf("Your query cannot be found in DB\n");
                return;
            }
        }
    }
    doc *temp = prev_req->docs;
    int i = 1;
    printf("%s\n", query);
    while (temp != NULL)
    {
        printf("%d. %s\n", i++, temp->doc_name);
        temp = temp->next_doc;
    }
}
int main(int argc, char **argv)
{
    node *head = NULL;
    for (int i = 1; i < argc; i++)
    {
        dict_add_from(argv[i], &head);
    }
    print_dict(head);
    search_rec("orange", head);
    search_rec("moon", head);
    return 0;
}