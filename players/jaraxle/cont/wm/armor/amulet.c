/*  10/08/06 - Rumplemintz
      Removed trailing ; from include statement
*/

inherit "/obj/armor";
#include "/players/jaraxle/define.h"

void
reset(status arg)
{
   if(arg) return;
   ::reset();
   set_name("frozen amulet");
   set_alias("frozen_amulet");
   set_short(HIC+"frozen amulet"+NORM);
   set_type("amulet");
   set_weight(2);
   set_long("A small necklace with a snowball shaped amulet.\n");
   set_ac(1); /* physical ac */
   set_value(1000+random(300));
   set_params("other|ice", 2, 50, "do_ice_special");
   /* 2 ac, 50% resistance to other|ice damage,
   plus it calls the 'do_ice_special()' function */
}

string
short()
{
   string sh, x;
   if(sscanf(sh = (string)::short(), "%s(worn)", x))
      return x + (CYN + "(" + NORM + "worn" + CYN + ")" + NORM);
   else return sh;
}



do_special(owner){
   if(!random(6)){
      tell_object(owner, "The "+HIC+"amulet on your necklace flashes "+HIC+BLINK+"brightly"+NORM+"!\n");
      if(this_player() && this_player()!=owner)
         write(owner->query_name()+"'s "+HIC+"frozen"+NORM+" amulet flashes brightly!\n");
      return 1+random(2);
   }
}

int
do_ice_special(object owner)
{
   if(!random(8))
      {
      tell_object(owner, "\
         Your "+CYN+"frozen"+NORM+" amulet flashes and reflects some of the "+CYN+"frost"+NORM+" damage.\n");
      return 1504;
      /* 
      15% [15] resistance boost
      4  [04] ac boost 
      */
   }
}
