
/*
 * GEM OF SEEING  (3/19/94)
 * Allows player to see the location of a player.
 */

id(str) { return str == "gem"; }

reset(arg) {
   if(arg)
     return;
}

get() { return 1; }

query_value() { return 300; }

short() { return "A gem of seeing"; }

long() {
   write("A magnificent jade gem.\n");
   write("Type 'gaze <player>' to see their location.\n");
}

init() {
   add_action("gaze","gaze");
}

gaze(str) {
   object target;
   if(!str)
     return 0;
   target = find_player(str);
   if(!target || target->query_invis() > 0) {
      write(capitalize(str)+" is not on.\n");
      return 1;
   }
   if(target->query_level() > 20) {
     write(capitalize(str)+" is too powerful to be spied upon.\n");
     return 1;
   }
   write(capitalize(str)+"'s location:\n");
   write(target->look());
   write("\n");
   return 1;
}

