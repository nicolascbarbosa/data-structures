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
        if(*stack_length == 1)
            elem_minimum = value;          
    } else {
        elem_minimum = value;       
    }

    *base_min = elem_minimum;            
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
            printf("Digite 1 para inserir\n");
            printf("Digite 2 para retirar\n");
            printf("Digite 3 para mostrar o menor elemento\n");            
            printf("Digite 4 para sair\n");
            printf("Opcao: ");
            scanf("%d", &option);
            if(option < 1 || option > 4)
                printf("\nOpcao invalida, tente novamente...\n");
            break;            
        }
        
        switch(option) 
        {
            case 1:
                printf("\nDigite o valor: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();                
            break;
            case 3:
                show_min();
            break;
            case 4:
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