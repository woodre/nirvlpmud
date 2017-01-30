#include "/players/puppy/define.h"
inherit "obj/armor";

reset(arg) {
   set_name("collar");
   set_alias("amulet");
   set_short("A leather collar");
   set_long(
      "A light collar that is used more for a handle then then for\n"+
      "any protection.  It is engraved with the letter P.\n");
   
   set_ac(1);
   set_type("amulet");
   set_weight(1);
   set_value(100);
}
