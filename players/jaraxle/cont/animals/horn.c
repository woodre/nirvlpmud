#include "/players/jaraxle/define.h"
inherit "/obj/treasure";

reset(arg)  {
   if(arg) return;
   
   set_alias("horn");
   set_id("unicorn horn");
set_short(HIW+"Unicorn horn"+NORM);
   set_weight(1);
   set_value(1500);
}
long(){ write("An animal skin that can be bartered with a Furrier.\n"); }

