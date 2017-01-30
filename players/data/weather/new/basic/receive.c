#include <event.h>

private static mapping handle_map;
private static mapping modify_map;

static int set_handle_event(string type,closure code)
{
  closure *list;
  int n;
  if (!handle_map)
    handle_map = ([ ]);
  if (!(list = handle_map[type]))
  {
    handle_map[type] = ({ code });
    return 0;
  }
  if ((n=member(list, 0))>=0)
  {
    list[n] = code;
    return n;
  }
  handle_map[type] = list + ({ code });
  return sizeof(list);
}

static void unset_handle_event(string type,int key)
{
  handle_map[type][key] = 0;
}

static int set_modify_event(string type,closure code)
{
  closure *list;
  int n;
  if (!modify_map)
    modify_map = ([ ]);
  if (!(list = modify_map[type]))
  {
    modify_map[type] = ({ code });
    return 0;
  }
  if ((n=member(list, 0))>=0)
  {
    list[n] = code;
    return n;
  }
  modify_map[type] = list + ({ code });
  return sizeof(list);
}

static void unset_modify_event(string type,int key)
{
  modify_map[type][key] = 0;
}

void handle_event(mapping event)
{
  closure *list;
  int i;
  if (list = handle_map[event[E_TYPE]])
  {
    for (i=0;i<sizeof(list);i++)
      if (list[i])
	funcall(list[i],event);
  }
}

void modify_event(mapping event)
{
  closure *list;
  int i;
  if (list = modify_map[event[E_TYPE]])
  {
    for (i=0;i<sizeof(list);i++)
      if (list[i])
	funcall(list[i],event);
  }
}

static void set_handler(mapping event,mixed handler,int priority)
{
  if (priority <= event[E_HANDLER_PRIORITY])
    return;
  event[E_HANDLER] = handler;
  event[E_HANDLER_PRIORITY] = priority;
}

