	/* golden armor set - battle standard  */

#include "/players/wren/ansi.h"
inherit "obj/armor";

reset(arg)  {
   if(arg)  return;
   ::reset();
   set_name("standard");
   set_alias("flag");
   set_short(" "+YEL+"Golden Standard"+NORM+" ");                     
   set_long("The "+YEL+"Golden Standard"+NORM+" of Tintagel. This combat standard\n"+
            "has been through many long campaigns. Its vivid colors are \n"+
            "said to have boosted the moral of faltering soldiers as it \n"+
            "swept past them. It bares the Mithril Unicorn on a field of  \n"+
            "Black woven through Gold .  \n");
   set_ac(2);
   set_type("misc");
   set_weight(2);
   set_value(800);
}
