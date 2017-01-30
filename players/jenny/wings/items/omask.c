#include "/players/jenny/define.h"
inherit "/obj/armor.c";
id(str) { return (::id(str) || str == "Goalie Mask" ||  str == "goalie mask" || str == "mask" || str == "face mask"); }
reset(arg) {
   ::reset(arg);
   set_name("Goalie Mask");
   set_ac(2);
   set_value(1000);
   set_weight(1);
   set_type("helmet");
   set_short("Goalie Mask");
   set_long(
      "This is a mask worn by goaltender Chris Osgood.  It is a red helmet, with\n"+
      "a white wire face mask attached to it.  Chris about the only goalie who still\n"+
      "uses this old style of mask.  It provides excellent protection to the face.\n");
}
