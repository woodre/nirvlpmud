#include "/players/khrell/define.h"
#include <ansi.h>
inherit "obj/weapon.c";

reset(arg) {
   ::reset(arg);
   if (arg) return;

message_hit = ({
        GRN+"slapped "+NORM,"",
        HIG+"clubbed "+NORM,"",
        YEL+"clobbered "+NORM,"",           
        HIY+"crushed "+NORM,"",
        CYN+"smashed "+NORM,"",
        RED+"pulverised "+NORM,"",
        HIR+"S H A T T E R E D "+NORM,""
        });
   
      
   set_name("plague censer");
   set_alias("censer");
   set_type("club");    
   set_short(YEL+"Plague"+GRN+" Censer"+NORM);
   set_long(
"   Plague censers are a large flail whose spiked heads are filled\n"+
"with burning warpstone incense.  Only the most deranged and fanatical\n"+
"worshippers of disease are chosen for the honor of carrying one of\n"+
"these vile weapons.\n"); 
   set_class(19);
   set_weight(5);
   set_value(2000);
   set_hit_func(this_object());
}
