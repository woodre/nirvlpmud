private static mapping input_to_stack;

#define STACK_KEY "simul_efun::input_to_stack"
#define ITEMS 4

private mapping get_input_to_stack()
{
  mixed h;
  if (!(h = get_extra_wizinfo(0)))
    set_extra_wizinfo(0,h = ([]));
  if (!h[STACK_KEY])
    h[STACK_KEY] = m_allocate(50,ITEMS);
  return h[STACK_KEY];
}

nomask object
query_input_pending(object user)
{
  int index, i, flags;
  mixed *stack;
  if (!input_to_stack)
    input_to_stack = get_input_to_stack();
  if (!efun::query_input_pending(user))
    return 0;
  if (m_contains(&stack,&index,&flags,input_to_stack,user) && index)
  {
    i = index - ITEMS;
    while (i >= 0)
    {
      if (stack[i] && (stringp(stack[i+1]) || to_object(stack[i+1])))
	break;
      i -= ITEMS;
    }
    if (i + ITEMS < index)
      input_to_stack[user,1] = i + ITEMS;
    if (i < 0)
    {
      m_delete(input_to_stack,user);
      return 0;
    }
    else 
      return stack[i];
  }
}

varargs void
input_to(mixed func, mixed flags_or_prompt)
{
  mixed *stack;
  int index, fl;
  object pending;
  if (!query_once_interactive(this_player()))
    return;
  if (!(stringp(func) || (closurep(func) && to_object(func))))
    raise_error("Bad argument 1 to input_to()\n");
  if (query_editing(this_player()))
    return;
  if (pending = query_input_pending(this_player()))
  {
    if (flags_or_prompt && intp(flags_or_prompt))
      return;
    m_contains(&stack,&index,&fl,input_to_stack,this_player());
  }
  if (!stack)
    stack = ({});
  else if (index > 0 && fl) // already a flagged input_to()
    return;
  
  while (get_eval_cost() < 1000); // too less time
  if (!pending)
  {
    if (stringp(flags_or_prompt))
      write(flags_or_prompt);
    funcall(bind_lambda(#'efun::input_to,this_player()),
			"evaluate_input",
			intp(flags_or_prompt) && flags_or_prompt);
  }
  if (sizeof(stack) <= index)
    stack += ({previous_object(),
	       func,
	       get_varargs(), 
	       stringp(flags_or_prompt) && flags_or_prompt});
  else 
    stack[index..index+ITEMS] = ({previous_object(),
			      func,
			      get_varargs(),
			      stringp(flags_or_prompt) && flags_or_prompt});
  input_to_stack += ([this_player() : stack; 
				      index+ITEMS; 
				      intp(flags) && flags]);
}

nomask status
catch_input_to(string input)
{
  int index, flags;
  status result;
  object p;
  mixed f, *v, *stack;
  if (previous_object() != this_interactive())
    return 0;
  if (!input_to_stack)
    input_to_stack = get_input_to_stack();
  m_contains(&stack,&index,&flags,input_to_stack,this_player());
  index -= ITEMS;
  while (index >= 0)
  {
    if ((p = stack[index]) && (stringp(f = stack[index+1]) || closurep(f)))
      break;
    index -= ITEMS;
  }
  if (index < 0)
    return 0;
  p = stack[index];
  f = stack[index+1];
  v = stack[index+2];
  if (stringp(f))
    result = apply(bind_lambda(#'call_other,p),p,f,input,v);
  else if (to_object(f))
    result = apply(bind_lambda(#'funcall,p),f,input,v);
  if (index > 0 && !query_input_pending(this_interactive()))
  {
    write(stack[index-ITEMS+3]||"");
    input_to_stack += ([this_player() : stack; index; 0]);
    apply(bind_lambda(#'efun::input_to,this_interactive()),"evaluate_input");
  }
  return result;
}

