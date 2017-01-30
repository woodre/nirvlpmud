#include "/players/jaraxle/define.h"
inherit "/obj/treasure";

reset(arg)  {
   
   if(arg) return;
   
   set_id("pouch");
   set_alias("skull");
   set_short("A small, brightly polished skull\n Component pouch");
   set_long("A skull taken from a treasured victory of long ago.\n"+
            "The skull has been meticulously cleaned and taken\n"+
            "care of.  The symbol of a true Necromancer.\n");
   set_weight(0);
   set_value(10);
}
