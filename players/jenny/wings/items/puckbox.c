#include "/players/jenny/define.h"
inherit "obj/treasure.c";
#define MAX_WEIGHT      12
int local_weight;

reset(arg) {
   if(arg) return;
   set_id("box");
   set_alias("cardboard box");
   set_short("A small cardboard box");
   set_weight(1);
   set_save_flag(1);
   set_value(10);
   MOCO("/players/jenny/wings/items/puck.c"),TO);
   MOCO("/players/jenny/wings/items/puck.c"),TO);
   MOCO("/players/jenny/wings/items/puck.c"),TO);
   MOCO("/players/jenny/wings/items/puck.c"),TO);
   MOCO("/players/jenny/wings/items/puck.c"),TO);
   MOCO("/players/jenny/wings/items/puck.c"),TO);
   MOCO("/players/jenny/wings/items/puck.c"),TO);
   MOCO("/players/jenny/wings/items/puck.c"),TO);
   MOCO("/players/jenny/wings/items/puck.c"),TO);
   local_weight = 1; } 
long() {
   write("This is a small cardboard box.  It is brown, and has the word\n"+
      "'PUCKS' written in black marker.\n");
   if (first_inventory(this_object()))
      write("There is stuff in it.\n");
   else
      write("You can put things in it.\n");
}
add_weight(w) {
   if (local_weight + w > MAX_WEIGHT)
      return 0;
   local_weight += w;
   return 1;
}
can_put_and_get() { return 1; }
prevent_insert() {
   if (local_weight > 1) {
      write("You can't when there are things in the bag.\n");
      return 1;
   }
   return 0;
}
