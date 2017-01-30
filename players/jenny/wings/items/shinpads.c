#include "/players/jenny/define.h"
inherit "/obj/armor.c";
reset(arg) {
   ::reset(arg);
   set_name("shin pads");
   set_alias("pads");
   set_ac(2);
   set_value(1000);
   set_weight(1);
   set_type("pants");
   set_short("Shin Pads");
   set_long(
      "This is a pair of red shin pads used by hockey players.  They are made\n"+
      "out of hard plastic, and provide good protection from the ankles to above\n"+
      "the knee.\n");
}
