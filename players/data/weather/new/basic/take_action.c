virtual inherit "/basic/synonym";

private mapping take_actions;

/*
 * do_take_action() will be called if the player tries to take a
 * fakeitem in the room which inherits this (with the fakeitem as argument).
 * If, and only if, it returns 0, the normal message 
 * "You can't take." will displayed. Otherwise not.
 * Thus, you can easily give another message to the player or 
 * to the whole room, if you like.
 */
mixed
do_take_action(string item)
{
  mixed action;
  if (!(take_actions && 
        (action = take_actions[get_synonym(item)]))) 
    return 0;
  if (closurep(action))
    action = funcall(action, item);
  if (intp(action)) 
    return action;
  else if (action) {
    // Carador, Mar-1996, break the result if it is a string.
    if (stringp(action)) write(break_string(action));
    else message(action);
  }
  return 1;
}

void 
set_take_action(mixed item, mixed action)
{
  if (pointerp(item))
  {
    item = m_indices(mkmapping(map(item, #'get_synonym)));
    map(item, #'set_take_action, action);
    return;
  }
  else if (!stringp(item)) return;
  if (!take_actions)
    take_actions = ([]);
  if (!action) 
    m_delete(take_actions, item);
  else 
    take_actions[item] = action;
}

void 
set_take_actions(mixed items) 
{
  map(items, lambda(({'r}), ({#'apply, #'set_take_action, 'r})));
}

void
remove_take_action(mixed item)
{
  set_take_action(item, 0);
}
