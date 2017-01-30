#include "/players/francesco/univ/ansi.h"
#define max_weight  10
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

set_ac(1);
set_type("shield");  /* armor,helmet,boots,ring,amulet,shield,misc  */
set_weight(1);
set_value(350);
set_arm_light(0);  
local_weight = 1;

}
init() {
  ::init();
  add_action("carrier","carrier");
}

carrier() {
          
          bacpack = clone_object("/players/francesco/univ/items/backpack1.c");
          move_object(bacpack,this_player());
	  if (worn) 
          {
              call_other(worn_by, "stop_wearing",this_object(), type, silently);
          worn_by = 0;
          worn = 0;
          }
	  destruct(this_object());
	  return 1;
}
