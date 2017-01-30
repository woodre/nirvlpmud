/* 5.25.01 Vertebraker added ice resistance */
#include "/players/softly/misc/ansi.h"

inherit "/obj/armor";

reset(arg){
   ::reset(arg);
   if (arg) return;

   set_name("ice cameo");
   set_alias("cameo");
   set_type("amulet");
   set_short(BOLD+"An Ice Cameo"+NORM);
   set_long("A finely carved cameo which appears to be etched from\n"+
            "ice shows the profile of a young man.  It hangs on a\n"+
            "fine silver chain.\n");
   set_ac(2);
   set_weight(1);
   set_value(1500);
   set_params("other|ice", 2, 0, "do_special");
}

