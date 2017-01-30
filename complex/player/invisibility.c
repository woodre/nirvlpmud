#include <filter.h>
#include <event.h>
#include <gender.h>

#define E_IGNORE "ignore" // for testing purposes

inherit "basic/create";

private static string *filters = 
        ({ F_ID, F_NAME, F_SHORT, F_LONG, F_GENDER, F_HIDE_INV });

void
create() {
  // listen_event("feeling", -100);
}

void
receive_event(mapping e, string type, int prio) {
}

void
turn_invisible(object who) {
  if (!(who && living(who))) {
    destruct(this_object());
    return;
  }
  map (filters, "add_filter", who, FPRIO_INVISIBLE);
}

status
prevent_move(object from, object to) {
  if(!clonep() || from)
    return 1;
}

void
notify_move(object from, object to) {
  if (!from)
    turn_invisible(to);
}

mixed
do_filter(string func,mixed arg) {
  switch (func) {
    case F_ID:
      return ({ });
    case F_NAME:
      return "Someone";
    case F_SHORT:
    case F_LONG:
      return 0;
    case F_GENDER:
      return 1;
      /*invisibles are male / Someone shakes his head, Fangorn, 10.11.94*/
    case F_HIDE_INV:
      return 1;
    default: 
      return arg;
  }
}

status
drop(status silently) {
  return 1;
}

void 
self_destruct() {
  if (environment()) {
    environment()->vis();
//    environment()->set_invisibility(0);  // Coogan, 10-Jan-99
  }
  else
    destruct(this_object());
}

void
set_duration(int length) {
  if (length < 0)
    return;
  while (remove_call_out("self_destruct") != -1)
    ;
  call_out("self_destruct", length);
}

int
query_duration() {  //  Coogan, 10-Jan-99
  return find_call_out("self_destruct");
}

mixed *
query_auto_load() {
  return ({ load_name(this_object()), find_call_out("self_destruct") });
}

void
init_arg(mixed *arg) {
  set_duration(arg[0]);
}

