#include <stdio.h>
#include <malloc.h>

// Stack type
typedef struct 
{
    int top;
    int capacity;
    int *array; // element date type: char, int, float, double, ...
} Stack;

// Stack Operations
Stack *createStack(int capacity)
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));

    if (!stack)
        return NULL;    // out of space error

    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(stack->capacity * sizeof(int)); // for element data

    if (!stack->array)
        return NULL;    // out of space error

    return stack;
}

int isFull(Stack *stack)
{
    return stack->top == stack->capacity-1;
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

int peek(Stack *stack)
{
    return stack->array[stack->top];
}

int pop(Stack *stack)
{
    if (!isEmpty(stack)) // check whether the stack is empty
        return stack->array[stack->top--];
    printf ("Stack is Empty!\n");
    return 0;
}

void push(Stack *stack, int new_element)
{
    if (!isFull(stack)) // check whether the stack is full
        stack->array[++stack->top] = new_element;
    else
        printf ("Stack is full!\n");
}

// Check if it's Palindrome
int isPalindrome(Stack *stack, char word[], int length)
{
    // Push the first length/2 elements into the stack
    int i;
    for (i = 0; i < length / 2; i++)
        push(stack, word[i]);

    // Check if the length of the string is odd
    // if odd then neglect the character in the mid index
    if (length % 2 != 0)
        i++; // skip the middle character

    // pop the element from the stack and compare it with the current character
    while (i < length) // till the end of the word
    {
        if (pop(stack) != word[i]) 
            return 0; // If the characters differ then the given word is not a palindrome
        
        i++;
    }
    return 1;
}

// Check if it's a valid brackets
int isValidBrackets(Stack *stack, char brackets[], int length) // length means brackets' length
{
    // • if current character is an opening bracket (i.e., ‘(‘, ‘{‘, ‘[‘) then push it to stack.
    // • if current character is closing bracket (i.e., ‘)’, ‘}’, ‘]’) then pop from stack.
    for (int i = 0; i < length; i++) 
    {
        if (brackets[i] == '(' || brackets[i] == '{' || brackets[i] == '[')
        {
            push(stack, brackets[i]);
            continue;
        }
        if (brackets[i] == ')' || brackets[i] == '}' || brackets[i] == ']')
        {
            pop(stack);
            continue;
        }
    }

    if (stack->top == -1)
        return 1;
    else
        return 0;
}

// Postfix Expression
int calculatePostfixExpression(Stack *stack, char expression[]) // length means expression's length
{
    // 5, 3, 2, *, +, 8, -
    int A, B;
    int i = 0;
    while (expression[i] != NULL)
    {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
        {
            B = pop(stack);
            A = pop(stack);
            
            if (expression[i] == '+')
            {
                push(stack, A + B);
                i++;
                continue;
            }
            if (expression[i] == '-')
            {
                push(stack, A - B);
                i++;
                continue;
            }
            if (expression[i] == '*')
            {
                push(stack, A * B);
                i++;
                continue;
            }
            if (expression[i] == '/')
            {
                push(stack, A / B);
                i++;
                continue;
            }
        }
        else // expression[i] is a number(=operand)
        {
            push(stack, expression[i]);
            i++;
            continue;
        }
    }

    return stack->array[stack->top];
}

/*
    • if character is operand, put it in postfix expression

    • if character is operator,
        • if stack isEmpty, push it to stack
        • if operator has higher precedence than top, push it to stack
        • if operator has same or lower precedence, then pop the top

    • if character is ‘(‘, push it to stack
    • if character is ‘)’, pop the stack until we encounter ‘(‘. 
*/
void convertInfixToPostfix()
{

}

void isValidBracketsTest()
{
    int capacity = 20;
    Stack* myStack = createStack(capacity);

    char brackets[8] = { '[', '{', '(', ')', '}', ']', '[', ']' }; // valid sets of brackets
    int rc = isValidBrackets(myStack, brackets, 8);

    if (rc == 1) // true, false
        printf("isValidBrackets() works Well!\n");
    else
        printf("isValidBrackets() has some Errors!\n");
}

void calculatePostfixExpressionTest()
{
    int capacity = 20;
    Stack* myStack = createStack(capacity);

    char expression[8] = { 5, 3, 2, '*', '+', 8, '-' };
    int rc = calculatePostfixExpression(myStack, expression);

    if (rc == 3) // above expression's value is 3
        printf("calculatePostfixExpression() works Well!\n");
    else
        printf("calculatePostfixExpression() has some Errors!\n");
}

int main(void)
{
    isValidBracketsTest();
    calculatePostfixExpressionTest();

    return 0;
}