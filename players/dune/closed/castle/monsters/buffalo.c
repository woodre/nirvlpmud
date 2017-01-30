inherit "obj/monster";
#include "definitions.h"


reset(arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("buffalo");
   set_short("A buffalo");
   set_alias("buffalo");
   set_level(4);
   set_race("buffalo");
   set_hp(60);
   set_wc(8);
   set_ac(4);
   set_long(
"     The large buffalo stands seven feet tall. A thick coat of long\n"+
"brown fur surrounds its mane. It has a massive upper body and, combined\n"+
"with its weight, could trample an obstruction easily.\n");
}
