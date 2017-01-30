#include "/players/puppy/define.h"
inherit "obj/armor";

reset(arg) {
   set_name("spacesuit");
   set_alias("suit");
   set_short("A spacesuit");
   set_long(
      "This suit was designed exclusively for walking around in\n"+
      "other worlds.  It is made up of the most Smurfy material\n"+
      "that is available.\n");
   
   set_ac(1);
   set_type("armor");
   set_weight(1);
   set_value(150);
}
