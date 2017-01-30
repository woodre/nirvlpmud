#include "/players/jareel/define.h"
inherit "obj/treasure.c";
#define MAX_WEIGHT      10

reset(arg) {
   if(arg) return;
   set_id("bag");
   set_alias("small bag");
   set_short("A small leather bag");
   set_weight(1);
   set_save_flag(1);
   set_value(10);
   MOCO("/players/jareel/heals/aura.c"),TO);
   MOCO("/players/jareel/heals/aura.c"),TO);
   MOCO("/players/jareel/heals/aura.c"),TO);
   local_weight = 1; }
long() {
   write("This is a small leather bag.\n");
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
