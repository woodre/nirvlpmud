/*
 * /basic/handle.c (C) by Ugh written Nov-1994 for Tubmud
 *
 * Coogan, 02/14-Feb-1998: messages simplified using the message system
 * Coogan, 24-Mar-1998: added more flexibility for opening/closing with handles
 *
 */

#pragma strong_types

#include <describe.h>
#include <event.h>
#include <message.h>

#define NO_KEY         -1
#define CANCEL_PRIO    300
#define FAIL(who,mess) with_player(who,#'notify_fail,({mess,1}))

virtual inherit "basic/create";
inherit "basic/open";

private mixed open_text, 
              close_text, 
              already_open_text,
              already_closed_text,
              not_openable_without_handle_text,
              not_closeable_without_handle_text,
              open_handle_not_right_text,
              close_handle_not_right_text,
              default_open;

private status handle = 1,
               openable_without_handle = 0,
               closeable_without_handle = 0;

private mixed open_handle_test_function,
              close_handle_test_function;

// fixed next two prototypes, Coogan, 12-Sep-2000
varargs mixed query_open_text(object handle, mapping args);
varargs mixed query_close_text(object handle, mapping args);
varargs mixed query_already_open_text(mapping args);
varargs mixed query_already_closed_text(mapping args);
varargs mixed query_not_openable_text(mapping args);
varargs mixed query_not_closeable_text(mapping args);
varargs mixed query_not_openable_without_handle_text(mapping args);
varargs mixed query_not_closeable_without_handle_text(mapping args);
varargs mixed query_open_handle_not_right_text(object handle, mapping args);
varargs mixed query_close_handle_not_right_text(object handle, mapping args);

string query_open_state_description() {
  return query_open() ? "open" : "closed";
}

void set_default_open(mixed o) {  // Coogan, 01-Dec-2001
  default_open = o;
}

status query_default_open() {  // Coogan, 01-Dec-2001  // Coogan, 01-Dec-2001
  return funcall(default_open);
}

void set_handle(status h) {
  handle = h;
}

status query_handle() {
  return handle;
}

void set_openable_without_handle(status o) {
  openable_without_handle = o;
}

status query_openable_without_handle() {
  return openable_without_handle;
}

void set_closeable_without_handle(status c) {
  closeable_without_handle = c;
}

status query_closeable_without_handle() {
  return closeable_without_handle;
}

status query_openable() {
  return query_handle() || query_openable_without_handle();
}

status query_closeable() {
  return query_handle() || query_closeable_without_handle();
}

varargs void set_open_handle_test_function(mixed func, object handler) {
  if (stringp(func)) {
    if (handler)
      open_handle_test_function = symbol_function(func, handler);
    else
      open_handle_test_function = symbol_function(func) ||
                                  symbol_function(func, previous_object());
  }
  else if (closurep(func))
    open_handle_test_function = func;
}

varargs void set_close_handle_test_function(mixed func, object handler) {
  if (stringp(func)) {
    if (handler)
      close_handle_test_function = symbol_function(func, handler);
    else
      close_handle_test_function = symbol_function(func) ||
                                   symbol_function(func, previous_object());
  }
  else if (closurep(func))
    close_handle_test_function = func;
}

status test_open_handle(object handle) {
  if (!handle)
    return 0;
  if (!accessible(handle, this_player()))
    return 0;
  if (open_handle_test_function)
    return funcall(open_handle_test_function, handle, this_object());
  return 0;  // Coogan, 28-Mar-2011
}

status test_close_handle(object handle) {
  if (!handle)
    return 0;
  if (!accessible(handle, this_player()))
    return 0;
  if (close_handle_test_function)
    return funcall(close_handle_test_function, handle, this_object());
  return 0;  // Coogan, 28-Mar-2011
}

object search_open_handle(object who) {
  object *handles;
  int i;

  handles = all_inventory(who);
  for (i = sizeof(handles); i--; )
    if (with_player(who, #'test_open_handle, handles[<i+1]))
      return handles[<i+1];
  return 0;  // Coogan, 26-Mar-2011
}

object search_close_handle(object who) {
  object *handles;
  int i;

  handles = all_inventory(who);
  for (i = sizeof(handles); i--; )
    if (with_player(who, #'test_close_handle, handles[<i+1]))
      return handles[<i+1];
  return 0;  // Coogan, 26-Mar-2011
}

void refresh() {  // Coogan, 01-Dec-2001
  create::refresh();
  if (query_default_open())
    open();
  else
    close();
}

void create() {
  create::create();
  listen_event("open",  CANCEL_PRIO);
  listen_event("close", CANCEL_PRIO);
}

void receive_event(mapping e, string type, int prio) {
  if (this_object() != e[E_TARGET])
    return;
  if (prio == CANCEL_PRIO) {
    switch (type) {
    case "open":
      if (e[E_KEY])
        break;
      e[E_KEY] = search_open_handle(e[E_AGENT]) || NO_KEY;
      if (objectp(e[E_KEY]))
        e[E_KEY, 1] = describe(e[E_KEY], ARTICLE_NONE);
      break;
    case "close":
      if (e[E_KEY])
        break;
      e[E_KEY] = search_close_handle(e[E_AGENT]) || NO_KEY;
      if (objectp(e[E_KEY]))
        e[E_KEY, 1] = describe(e[E_KEY], ARTICLE_NONE);
      break;
    }
  }
}

status do_open(mapping action) {
  object who;
  mixed h;

  if (!action)
    action = ([ E_AGENT : this_player(); this_player()->query_name(),
                E_TARGET: this_object(); describe(this_object(),ARTICLE_NONE)]);
  h = action[E_KEY];
  if (h == NO_KEY)
    h = 0;
  who = action[E_AGENT];
  if (query_open()) {
    if (who)
      FAIL(who,query_already_open_text(action));
    return 0;
  }
  if (!query_handle()) {
    if (!query_openable_without_handle()) {
      if (!h)
        h = search_open_handle(who);
      if (!h) {
        if (who)
          FAIL(who,query_not_openable_without_handle_text(action));
        return 0;
      }
      if (!test_open_handle(h)) {
        if (who)
          FAIL(who,query_open_handle_not_right_text(h, action));
        return 0;
      }
#if 0  // Coogan, 02-Jun-1998
      return 0;
#endif
    }
  }
  if (h) {
    if (!test_open_handle(h)) {
      if (who)
        FAIL(who,query_open_handle_not_right_text(h, action));
      return 0;
    }
  }
  message(query_open_text(h, action), who);
  open();
  return 1;
}

status do_close(mapping action) {
  object who;
  mixed h;

  if (!action)
    action = ([ E_AGENT : this_player(); this_player()->query_name(),
                E_TARGET: this_object(); describe(this_object(),ARTICLE_NONE)]);
  h = action[E_KEY];
  if (h == NO_KEY)
    h = 0;
  who = action[E_AGENT];
  if (!query_open()) {
    if (who)
      FAIL(who,query_already_closed_text(action));
    return 0;
  }
  if (!query_handle()) {
    if (!query_closeable_without_handle()) {
      if (!h)
        h = search_close_handle(who);
      if (!h) {
        if (who)
          FAIL(who,query_not_closeable_without_handle_text(action));
        return 0;
      }
      if (!test_close_handle(h)) {
        if (who)
          FAIL(who,query_close_handle_not_right_text(h, action));
        return 0;
      }
#if 0  // Coogan, 03-Jun-1998
      return 0;
#endif
    }
  }
  if (h) {
    if (!test_close_handle(h)) {
      if (who)
        FAIL(who,query_close_handle_not_right_text(h, action));
      return 0;
    }
  }
  message(query_close_text(h, action), who);
  close();
  return 1;
}

int apply_action(string action,int level,mixed arg) {
  if (!mappingp(arg))
    return 0;
  if (this_object() != arg[E_TARGET])
    return 0;
  switch (action) {
  case "open":
    return do_open(arg);
  case "close":
    return do_close(arg);
  }
  return 0;  // Coogan, 26-Mar-2011
}

void set_open_text(mixed text) {
  open_text = text;
}

varargs mixed query_open_text(object handle, mapping args) {
  if (closurep(open_text))
    return funcall(open_text, handle, args);
  return open_text ||
         ({({ M_PL_THE, M_PL_VERB, "open", M_ME_THE, }) +
              (handle ? ({ " with ", M_THE, M_OBJECT, handle, }) : ({ })) +
           ({ "." })});
}

void set_close_text(mixed text) {
  close_text = text;
}

varargs mixed query_close_text(object handle, mapping args) {
  if (closurep(close_text))
    return funcall(close_text, handle, args);
  return close_text ||
         ({({ M_PL_THE, M_PL_VERB, "close", M_ME_THE, }) +
              (handle ? ({ " with ", M_THE, M_OBJECT, handle, }) : ({ })) +
           ({ "." })});
}

void set_already_open_text(mixed text) {
  already_open_text = text;
}

varargs mixed query_already_open_text(mapping args) {
  return funcall(already_open_text,args) ||
         ({({ M_WRITE, "But ", M_THE, M_OBJECT, this_object(),
              " is already open!" })});
}

void set_already_closed_text(mixed text) {
  already_closed_text = text;
}

varargs mixed query_already_closed_text(mapping args) {
  return funcall(already_closed_text,args) ||
         ({({ M_WRITE, "But ", M_THE, M_OBJECT, this_object(),
              " is already closed!" })});
}

void set_not_openable_without_handle_text(mixed text) {
  not_openable_without_handle_text = text;
}

varargs mixed query_not_openable_without_handle_text(mapping args) {
  return funcall(not_openable_without_handle_text, args) ||
         ({({ M_WRITE, "But you have nothing to open ", M_THE, M_OBJECT,
              this_object(), " with." })});
}

void set_not_closeable_without_handle_text(mixed text) {
  not_closeable_without_handle_text = text;
}

varargs mixed query_not_closeable_without_handle_text(mapping args) {
  return funcall(not_closeable_without_handle_text, args) ||
         ({({ M_WRITE, "But you have nothing to close ", M_THE, M_OBJECT,
              this_object(), " with." })});
}

void set_open_handle_not_right_text(mixed text) {
  open_handle_not_right_text = text;
}

varargs mixed query_open_handle_not_right_text(object handle, mapping args) {
  if (closurep(open_handle_not_right_text))
    return funcall(open_handle_not_right_text, handle, args);
  return open_handle_not_right_text ||
         ({({ M_WRITE, "You can't open ", M_THE, M_OBJECT, this_object(), }) +
              (handle ? ({ " with ", M_THE, handle, }) : ({ })) +
           ({ "." })});
}

void set_close_handle_not_right_text(mixed text) {
  close_handle_not_right_text = text;
}

varargs mixed query_close_handle_not_right_text(object handle, mapping args) {
  if (closurep(close_handle_not_right_text))
    return funcall(close_handle_not_right_text, handle, args);
  return close_handle_not_right_text ||
         ({({ M_WRITE, "You can't close ", M_THE, M_OBJECT, this_object(), }) +
              (handle ? ({ " with ", M_THE, handle, }) : ({ })) +
           ({ "." })});
}

/*
 * the following remains for compatibility
 *
 */

void set_found_no_handle_text(mixed t) {
  set_not_openable_without_handle_text(t);
}

varargs mixed query_found_no_handle_text(mapping m) {
  return query_not_openable_without_handle_text(m);
}

