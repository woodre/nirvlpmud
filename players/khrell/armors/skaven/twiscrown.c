#include "/players/khrell/define.h"
#include <ansi.h>
inherit "obj/armor";

reset(arg) {
   set_name("Twisted Crown");
   set_alias("crown");
   set_short(HIK+"Twis"+NORM+BLU+"ted C"+GRN+"rown"+NORM+" of the Horned Rat");
   set_long("\
   This crown is made of corroded and tangled barbs of sharp metal\n\
that bite and push their way into the skull of anyone wearing it.\n");   
   
   set_ac(2);
   set_type("helmet");
   set_weight(1);
   set_value(1500);
}
