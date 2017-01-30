#include "../defs.h"

status flag;

string short() { return "A small magical fire"; }
status id(string str) { return str == "light" || str == "fire"; }
void long() { write("A small magical fire.\n"); }
status get() { return 0; }
status drop() { return 1; }

void extinguish() {
  tell_room(environment(this_object()), "The small magical fire goes out.\n");
  destruct(this_object());
}

void init() { 
  if (flag) return;
  call_out("extinguish", CAST_DURATION);
  flag = 1;
}

void reset(status arg) { 
  if (arg) return;
  set_light(1);
  flag = 0;
}
