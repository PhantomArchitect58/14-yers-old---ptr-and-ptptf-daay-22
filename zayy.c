#include "cs50.h"
#include <stdio.h>
#include <stdlib.h>

void attack()
{
    printf("АТАКУЮ ЦЕЛЬ!!! ");
}

void grab()
{
    printf("ЗАХВАТ ЦЕЛИ.... ");
}

typedef struct node{
    int id;
    int priority;
    int s;
    struct node *next;
    struct node *prev;
    void (*mission)();
    unsigned char status;
} node;

node *create_malloc(node **p, node **v, int data, int status_id)
{
    node *n = malloc(sizeof(node));
    n->next = NULL;
    n->prev = NULL;
    n->id = data;
    n->status = status_id;
    n->mission = grab;
    unsigned char s;
    if(*p == NULL)
    {
        *p = n;
        *v = n;
    }
    else{
        (*v)->next = n;
        n->prev = *v;
        *v = n;
    }
}

void (**get_control(node **p, int target_id))()
{
    node *curr = *p;
    while(curr != NULL)
    {
        if(curr->id != target_id)
        {
            return &curr->mission;
        }
        curr =curr->next;
    }
}

void panel_ypr(node **p, int min_priorioty)
{
    node *curr = *p;
    while(curr != NULL)
    {
        if(curr->priority <= min_priorioty && curr->status == 1)
        {
            curr->mission();
        }
        curr =curr->next;
    }
}

node *clear_all(node **p)
{
    node *temp;
    node *curr = *p;
    while(curr != NULL)
    {
        temp = curr->next;
        free(curr);
        curr = temp;
    }
    *p = NULL;
}

node *print_list(node **p)
{
    node *curr = *p;
    while(curr != NULL)
    {
        printf("Id: %i // Status %i\n", curr->id, curr->status);
        curr = curr->next;
    }
}

void switches_status(node **p, int tarr_id, int statusss)
{
    node *curr = *p;
    while(curr != NULL)
    {
        if(curr->id == tarr_id)
        {
            curr->status = statusss;
        }
        curr = curr->next;
    }
}

int main(void)
{
    node *perviy = NULL;
    node *vtoroy = NULL;
    create_malloc(&perviy, &vtoroy, 10, 0);
    create_malloc(&perviy, &vtoroy, 20, 0);
    create_malloc(&perviy, &vtoroy, 30, 0);
    create_malloc(&perviy, &vtoroy, 40, 0);
    create_malloc(&perviy, &vtoroy, 50, 0);
    // void (*playlist[]) = {attack, grab};
    // void (**cabel)();
    // cabel = get_control(&perviy, 40);
    // *cabel = playlist[0];
    // (**cabel)();
    switches_status(&perviy, 20, 1);
    panel_ypr(&perviy, 50);
    print_list(&perviy);
    clear_all(&perviy);
}