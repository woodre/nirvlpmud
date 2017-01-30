
/*
 * GENERIC TREASURE CHEST (1/19/94)
 */

#define CME capitalize(this_player()->query_name())

int locked, closed, can_get, max_weight, local_weight;
string alias, name, short_desc, long_desc;
string key_id;

reset(arg) {
   if(arg)
     return;
   closed = 1;
   local_weight = 0;
}

set_locked(l) { locked = l; }
set_closed(c) { closed = c; }
set_name(n) { name = n; }
set_alias(a) { alias = a; }
set_short(s) { short_desc = s; long_desc = s; }
set_long(l) { long_desc = l; }
set_can_get(g) { can_get = g; }
set_max_weight(w) { max_weight = w; }
set_key_id(k) { key_id = k; }
query_key_id() { return key_id; }

id(str) { return str == name || str == alias; }

get() {
   if(can_get)
     return 1;
   write("It is too heavy.\n");
   return 0;
}

can_put_and_get() { 
   if(closed) 
      return 0; 
   return 1;
}

short() { 
   if(!closed)
     return short_desc+" (open)";
   return short_desc; 
}

long() {
   write(long_desc);
   if(locked)
     write("It is locked.\n");
   else
     write("It is not locked.\n");
}

init() {
   add_action("open","open");
   add_action("unlock","unlock");
   add_action("close","close");
   add_action("lock","lock");
}

open(str) {
   if(!id(str))
     return;
   if(locked) {
     write("It is locked.\n");
     say(CME+" tries to open the "+name+".\n");
     return 1;
   }
   if(!closed) {
     write("It is already open.\n");
     return 1;
   }
   closed = 0;
   say(CME+" opens the "+name+".\n");
   write("Ok.\n");
   return 1;
}

close(str) {
   if(!id(str))
     return;
   if(closed) {
     write("It is already closed.\n");
     return 1;
   }
   closed = 1;
   say(CME+" closes the "+name+".\n");
   write("Ok.\n");
   return 1;
}

unlock(str) {
   if(!id(str))
     return;
   if(!present(key_id, this_player())) {
     write("You do not have the right key.\n");
     return 1;
   }
   if(!locked) {
     write("It is already unlocked.\n");
     return 1;
   }
   locked = 0;
   say(CME+" unlocks the "+name+".\n");
   write("Ok.\n");
   return 1;
}

lock(str) {
   if(!id(str))
     return;
   if(!present(key_id, this_player())) {
     write("You do not have the right key.\n");
     return 1;
   }
   if(locked) {
     write("It is already locked.\n");
     return 1;
   }
   if(!closed) {
     write("You must close it first.\n");
     return 1;
   }
   locked = 1;
   say(CME+" locks the "+name+".\n");
   write("Ok.\n");
   return 1;
}

add_weight(w) {
   if(!max_weight)
     return 1;
   if(local_weight + w > max_weight)
     return 0;
   local_weight += w;
   return 1;
}
