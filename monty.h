#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
extern char *line;
extern FILE *file;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int lnum);
} instruction_t;
typedef void (*instruct_func)(stack_t **stack, unsigned int lnum);
void doNothing(stack_t **stack, unsigned int lnum);
void addToStack(stack_t **stack, unsigned int lnum);
void getMod(stack_t **stack, unsigned int lnum);
void divideStack(stack_t **stack, unsigned int lnum);
void subtract(stack_t **stack, unsigned int lnum);
void multiply(stack_t **stack, unsigned int lnum);
void swapNodes(stack_t **stack, unsigned int lnum);
void popNode(stack_t **stack, unsigned int lnum);
void pintNode(stack_t **stack, unsigned int lnum);
void pushNode(stack_t **stack, unsigned int lnum);
void printAllNodes(stack_t **stack, __attribute__((unused))unsigned int lnum);
void moveFirstToLast(stack_t **stack, unsigned int lnum);
void myPutChar(stack_t **stack, unsigned int lnum);
char *parseLine(char *str);
instruct_func getRightFunction(char *str);
void readMontyFile(char *filename, stack_t **stack);
void freeAllList(stack_t *head);
void printAll2(stack_t **head);
void printStackHead(stack_t **head, int num);
void printHeaderData(stack_t **head, int num);
void deleteStackHead(stack_t **head);
stack_t *addStackHeader(stack_t **head, int n);
void freeAndExit(stack_t **stack);
stack_t *moveFirstToLastStack(stack_t **stack);
size_t newGetLine(char **lineptr, size_t *n, FILE *stream);
int isANumber(char *str);
#endif
