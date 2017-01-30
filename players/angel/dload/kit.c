#include "/players/softly/closed/ansi.h"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (arg) return;

   set_name("red fox kit");
   set_short(RED+"A red fox kit"+NORM);
   set_alias("kit");
   set_long("The tiny red fox kit has just opened its eyes\n"+
            "for the first time.  Its pointy ears and dark\n"+
            "brown fur are accented by a white-tipped tail.\n");
   set_type("animal");
   set_level(1);
   set_ac(5);
   set_wc(3);
   set_hp(15);
   set_al(0);
   set_aggressive(0);
}





