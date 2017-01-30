
/*
 * Statue (4/30/94)
 */

string name, short_desc, long_desc, clone_path;

id(str) { return str == "statue" || str == name; }

short() { return short_desc; }

long() {
   if(!long_desc)
     write(short_desc+"\n");
   else
     write(long_desc);
}

init() {
   object guard;
   
   if("/players/molasar/rowan/drake/mansion/mt_chmbr"->query_guard() &&
       this_player()->is_player()) {
     tell_room(environment(this_object()), short_desc+" springs to life!\n");
     guard = clone_object(clone_path);
     move_object(guard, environment(this_object()));
     if(this_player())
       guard->attack_object(this_player());
     destruct(this_object());
     return 1;
   }
}

/*
 * To set the variables
 */

set_name(n) { name = n; }
set_short(s) { short_desc = s; }
set_long(l) { long_desc = l; }
set_clone_path(c) { clone_path = c; }

