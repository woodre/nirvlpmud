#include "/players/puppy/define.h"
inherit "obj/weapon.c";

reset(arg) {
   ::reset(arg);
   if (arg) return;
   
   set_name("scepter ");
   set_id("scepter");
   set_type("club");
   set_short("A scepter ");
   set_long(
      "King Smurf had this scepter made for him long ago.  It's\n"+
      "most noticable feature is the topaz stone at head of it.\n");
   set_class(6);
   set_weight(1);
   set_value(125);
}
