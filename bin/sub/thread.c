#include <lpctypes.h>
#include <kernel.h>

inherit ACCESS;
inherit "basic/stack";
inherit "basic/create";

static mixed *thread_stack = ({});

varargs void thread(mixed *calls) {
  mixed h;
  h = caller_stack_depth();
  while (h--)
    if (previous_object(h) == this_object())
      break;
  if (h < 0)
    thread_stack = ({});
  while (sizeof(calls)) {
    h = top(calls);
    if (get_eval_cost() < ((sizeof(h) > 2 ? h[2] : 80000) + 2000))
      break;
    thread_stack = push(pop(calls),thread_stack);
    if (!to_object(h[0]))
      if (CLOSURE_IS_UNBOUND_LAMBDA(get_type_info(h[0],1)))
	h[0] = bind_lambda(h[0],this_object());
      else {
	calls = top(thread_stack);
	thread_stack = pop(thread_stack);
	return;
      }
    if (sizeof(h) < 2)
      h += ({ 0 });
    apply(h[0],h[1]);
    calls = top(thread_stack);
    thread_stack = pop(thread_stack);
  }
  if (sizeof(calls))
    call_out("thread",1,calls);  // 0->1, Coogan, 03-Nov-2009
}

void push_call(closure call,mixed *arg,int cost) {
  if (cost < 0)
    cost = 0;
  thread_stack = 
    push(push(({call,arg,cost}),top(thread_stack)),pop(thread_stack));
}

void create() {
  set_privilege(1);
}

