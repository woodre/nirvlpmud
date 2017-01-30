	/* golden armor set - gauntlet  */

#include "/players/wren/ansi.h"
inherit "obj/armor";

reset(arg)  {
   if(arg)  return;
   ::reset();

   set_id("gauntlet");
   set_name("ggauntlets");
   set_alias("gauntlets");
   set_short(" "+YEL+"Golden Gauntlets"+NORM+"");                     
   set_long("The "+YEL+"Golden Gauntlets"+NORM+" of Tintagel. These hand coverings \n"+
            "are composed of elven chainmail so fine that it feels more \n"+
            "like silk then metal. Over this are built the articulated  \n"+
            "plates that form that protect the back of the hand. The   \n"+
            "right bares the mark of defense and the left has vigilance.  \n");
   set_ac(2);
   set_type("ring");
   set_weight(2);
   set_value(700);
}
