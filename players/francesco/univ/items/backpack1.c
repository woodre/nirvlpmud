#include "/players/francesco/univ/ansi.h"
#define max_weight 10
int local_weight;
object bacpack;
inherit "obj/armor";

reset(arg) {
set_name("backpack");
set_alias("backpack");
set_short("A leather backpack");
set_long(
   "This backpack is manufactured with strong leather and is both nice looking\n"+
   "and resistant.  It should mainly be used as a stuff 'carrier',  yet it is \n"+
   "sometimes used also as a protective 'shield' if properly worn.  Please,\n"+
   "acknowledge that if you use it one way, then you cant use it the other\n"+
   "way at the same time.\n");

   local_weight = 0;
}
init() {
  ::init();
  add_action("shield","shield");
}

shield() {
          bacpack = clone_object("/players/francesco/univ/items/backpack.c");
          move_object(bacpack,this_player());
	  destruct(this_object());
	  return 1;
}
query_value() {
    return 50;
}

can_put_and_get() { return 1; }

get() {
    return 1;
}

prevent_insert() {
    if (local_weight > 0) {
        write("You can't when there are things in the bag.\n");
        return 1;
    }
    return 0;
}
add_weight(w) {
    if (local_weight + w > max_weight)
        return 0;
    local_weight += w;
    return 1;
}
