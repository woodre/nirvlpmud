#include <stack.h>

mixed *
push(mixed what,mixed *stack)
{
  return PUSH(what,stack);
}

mixed *
pop(mixed *stack)
{
  return POP(stack);
}

mixed
top(mixed *stack)
{
  return TOP(stack);
}
