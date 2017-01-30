#include "/players/jenny/define.h"
inherit "/obj/armor.c";
id(str) { return ::id(str) || str=="hockey gloves" || str =="gloves"; }
reset(arg) {
   ::reset(arg);
   set_name("gloves");
   set_ac(2);
   set_value(800);
   set_weight(1);
   set_type("gloves");
   set_short("Hockey Gloves");
   set_long(
      "This is a pair hockey gloves.  They are red, with the letters CCM\n"+
      "printed on them.  These gloves are very thick, and padded with foam,\n"+
      "giving maximum protection to the hands.\n");
}
