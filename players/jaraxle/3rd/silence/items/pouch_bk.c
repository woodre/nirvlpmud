#include "/players/jaraxle/define.h"
inherit "obj/treasure.c";
#define MAX_WEIGHT      10
int local_weight, i, x;

reset(arg) {
   if(arg) return;
   set_id("bag");
   set_alias("pouch");
   set_short(YEL+"A leather pouch"+NORM);
   set_weight(1);
   set_save_flag(1);
   set_value(10);
   for(i = 0; i < 1 + random(4); i++)
   {
 MOCO("/players/jaraxle/closed/heals/amplee.c"),TO);
}
   for(x = 0; x < 1 + random(2); x++)
{
 MOCO("/players/jaraxle/closed/heals/roht.c"),TO);
}
   local_weight = 1; }
long() {
   write("This is a small leather pouch.\n");
   if (first_inventory(this_object()))
    write("\n");
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
