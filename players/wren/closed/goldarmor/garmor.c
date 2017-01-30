	/* golden armor set - platemail  */

#include "/players/wren/ansi.h"
inherit "obj/armor";

reset(arg)  {
   if(arg)  return;
   ::reset();
   set_name("garmor");
   set_alias("platemail");
   set_short(" "+YEL+"Golden Platemail"+NORM+"");                     
   set_long("The "+YEL+"Golden Platemail"+NORM+" of Tintagel was the main piece of a  \n"+
            "legendary armor set. The whole of its surface is covered with \n"+
            "whirls and spiraling etchings. The plates are fitted together \n"+
            "using delicate chainlinks. The workmanship appears elven and  \n"+
            "likely has some enchantments to protect its owner.  \n");
   set_ac(4);
   set_type("armor");
   set_weight(3);
   set_value(1500);
}
