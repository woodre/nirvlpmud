#include "/players/softly/closed/ansi.h"

inherit "/obj/armor";

reset(arg){
   ::reset(arg);
   if (arg) return;

   set_name("eternal band");
   set_alias("band");
   set_type("ring");
   set_short(HIY + "An Eternal Band" + NORM);
   set_long("A golden wedding band made of two strands twisted\n"+
            "around each other.  There is a small inscription\n"+
            "that says 'Love is Eternal'.\n");
   set_ac(2);
   set_weight(1);
   set_value(1200);
}
