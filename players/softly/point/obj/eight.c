#include "/players/softly/closed/ansi.h"

inherit "obj/armor.c";

reset(arg){

   set_name("pieces");
   set_alias("eight");
   set_type("earring");
   set_short("Pieces of Eight");
   set_long("Silver coins showing a seal on one side and the Pillars\n"+
            "of Hercules on the reverse side\n");
   set_ac(0);
   set_weight(1);
   set_value(800);
}
