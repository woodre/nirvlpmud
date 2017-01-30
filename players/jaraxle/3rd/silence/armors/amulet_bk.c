#include "/players/jaraxle/define.h"
inherit "/obj/armor";

void
reset(status arg)
{
   if(arg) return;
   ::reset();
   set_name("fairy amulet");
   set_short("Fairy "+YEL+"Am"+HIR+"ul"+NORM+YEL+"et"+NORM);
   set_type("amulet");
   set_weight(1);
   set_long("A long necklace made of "+GRN+"wrapped and twined vine"+NORM+".\nA small piece of "+YEL+"amber"+NORM+" is attached to the center.\n");
   set_ac(0); /* physical ac */
   set_value(100+random(300));
   set_params("other|fire", 2, 30, "do_fire_special");
   /* 2 ac, 30% resistance to other|fire damage,
   plus it calls the 'do_fire_special()' function */
}

do_special(owner){
  if(!random(6)){
    tell_object(owner, "The "+YEL+"amber "+YEL+"gem"+NORM+" in your necklace flashes "+HIY+BLINK+"brightly"+NORM+"!\n");
    if(this_player() && this_player()!=owner)
      write(owner->query_name()+"'s amber gem necklace flashes brightly!\n");
return 1+random(9);
  }
}
int
do_fire_special(object owner)
{
   if(!random(8))
      {
      tell_object(owner, "\
         Your "+YEL+"amber"+NORM+" gem necklace flashes and reflects some of the "+HIR+"fire"+NORM+" damage.\n");
      return 1504;
      /* 
      15% [15] resistance boost
      4  [04] ac boost 
      */
   }
}
