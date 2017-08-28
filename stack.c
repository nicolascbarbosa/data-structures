#include <stdio.h>
#include <stdlib.h>

#define STACK_MAX_LENGTH 10

int *base, *base_min, stack[STACK_MAX_LENGTH], stack_min[STACK_MAX_LENGTH], *stack_length, elem_minimum = 0;

void push(int value)
{
    if(*stack_length == STACK_MAX_LENGTH)
    {
        printf("\nImpossivel inserir o elemento!\nA pilha esta cheia!\n");
        return;
    }

    base++;
    base_min++;   
    *stack_length = *stack_length + 1;    

    if(value >= elem_minimum) 
    {
        if(*stack_length == 1) {
            elem_minimum = value;          
        }

        *base_min = elem_minimum;        
    } else {
        elem_minimum = value;       
        *base_min = elem_minimum;
    }

    printf("\nElemento: %d\n", elem_minimum);

    *base = value; 
    printf("\nelemento inserido!\n");
}

void pop()
{
    if(*stack_length == 0)
    {
        printf("\nA pilha esta vazia!!\n");
        return;
    }
    base--;
    base_min--;
    *stack_length = *stack_length - 1;
    printf("\nelemento removido!\n");
}

void show_min() 
{
    if(*stack_length == 0)
        printf("\nA pilha esta vazia!!\n");
    else
        printf("\nmenor elemento: %d\n", *base_min);
}

void show_stack()
{
    if(*stack_length == 0)
        printf("\nA pilha esta vazia!!\n");
    else
    {
        int * aux;
        int i, len;

        len = *stack_length;
        aux = base;
        printf("\nElementos da pilha:\n");
        for(i = len - 1; i >= 0; i--)
        {
            printf("%d\n", *aux);
            aux--;
        }
    }
}

int main()
{
    int value, option, option_exit = 0, len = 0;

    stack_length = &len; 
    base = stack;
    base_min = stack_min;

    do
    {
        while(1)
        {
            printf("Digite 1 para mostrar todos os elementos\n");
            printf("Digite 2 para inserir\n");
            printf("Digite 3 para retirar\n");
            printf("Digite 4 para mostrar o menor elemento\n");            
            printf("Digite 5 para sair\n");
            printf("Opcao: ");
            scanf("%d", &option);
            if(option < 1 || option > 5)
                printf("\nOpcao invalida, tente novamente...\n");
            break;            
        }
        
        switch(option) 
        {
            case 1: 
                show_stack();
                break;
            case 2:
                printf("\nDigite o valor: ");
                scanf("%d", &value);
                push(value);
                break;
            case 3:
                pop();                
            break;
            case 4:
                show_min();
            break;
            case 5:
                option_exit = 1;
            break;
        }

        if(option_exit == 1)
            break;
    }

    while(1);

    printf("\nPrograma finalizado!\n");
    return 0;
}