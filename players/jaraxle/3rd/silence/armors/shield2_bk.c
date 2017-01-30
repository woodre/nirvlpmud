#include "/players/jaraxle/define.h"
inherit "/obj/armor";

void
reset(status arg)
{
   if(arg) return;
   ::reset();
   set_name("fairy shield");
   set_short("Fairy "+HIG+"Sh"+HIM+"ie"+HIG+"ld"+NORM);
   set_type("shield");
   set_weight(1);
   set_long("A small shield made of frosted leaves.  A "+HIB+"bluish tint spreads from the middle\n"+HIC+"of the shield, turning "+HIW+"white towards the edges"+NORM+".\n");
   set_ac(0); /* physical ac */
   set_res(12);
   set_value(250+random(250));
   set_params("other|ice", 2, 10, "do_ice_special");
   /* 2 ac, 10% resistance to other|ice damage,
   plus it calls the 'do_ice_special()' function */
}

do_special(owner){
   if(!random(7)){
      tell_object(owner, "The Fairy Shield flashes "+HIW+BLINK+"brightly"+NORM+"!\n");
      if(this_player() && this_player()!=owner)
         write(owner->query_name()+"'s Fairy Shield flashes brightly!\n");
      return 1+random(9);
   }
}
int
do_ice_special(object owner)
{
   if(!random(8))
      {
      tell_object(owner, "\
         Your shield flashes and absorbs some of the ice damage.\n");
      return 1202;
      /* 
      12% [12] resistance boost
      2  [02] ac boost 
      */
   }
}
