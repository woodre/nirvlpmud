#include "/players/jaraxle/define.h"
inherit "/obj/armor";

void
reset(status arg)
{
   if(arg) return;
   ::reset();
   set_name("flaming amulet");
   set_alias("flaming_amulet");
   set_short(RED+"flaming amulet"+NORM);
   set_type("amulet");
   set_weight(2);
   set_long("A small necklace with a fireball shaped amulet.\n");
   set_ac(1); /* physical ac */
   set_value(1000+random(300));
   set_params("other|fire", 2, 50, "do_fire_special");
   /* 2 ac, 50% resistance to other|fire damage,
   plus it calls the 'do_fire_special()' function */
}

string
short()
{
   string sh, x;
   if(sscanf(sh = (string)::short(), "%s(worn)", x))
      return x + (RED + "(" + NORM + "worn" + RED + ")" + NORM);
   else return sh;
}



do_special(owner){
   if(!random(6)){
      tell_object(owner, "The "+HIR+"amulet on your necklace flashes "+HIR+BLINK+"brightly"+NORM+"!\n");
      if(this_player() && this_player()!=owner)
         write(owner->query_name()+"'s "+HIR+"flaming"+NORM+" amulet flashes brightly!\n");
      return 1+random(2);
   }
}

int
do_fire_special(object owner)
{
   if(!random(8))
      {
      tell_object(owner, "\
         Your "+RED+"flaming"+NORM+" amulet flashes and reflects some of the "+RED+"flame"+NORM+" damage.\n");
      return 1504;
      /* 
      15% [15] resistance boost
      4  [04] ac boost 
      */
   }
}
