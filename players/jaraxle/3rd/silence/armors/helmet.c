/*  10/08/06 - Rumplemintz: removed trailing ; from #include  */
inherit "/obj/armor";
#include "/players/jaraxle/define.h"

void
reset(status arg)
{
   if(arg) return;
   ::reset();
   set_name("fairy helmet");
   set_short("Fairy "+BLU+"He"+HIC+"lm"+NORM+BLU+"et"+NORM);
   set_type("helmet");
   set_weight(1);
   set_long("A small helmet made with clay.  Small specks of "+HIY+"fairy dust"+NORM+" has been\nmolded into the clay.\n");
   set_ac(0); /* physical ac */
   set_res(10); /* 2% resistance to all physical attacks */
   set_value(300+random(300));
   set_params("other|water", 2, 10, "do_water_special");
   /* 2 ac, 10% resistance to other|water damage,
   plus it calls the 'do_water_special()' function */
}

do_special(owner){
   if(!random(5)){
      tell_object(owner, "The Fairy Helmet flashes "+HIG+BLINK+"brightly"+NORM+"!\n");
      if(this_player() && this_player()!=owner)
         write(owner->query_name()+"'s Fairy Helmet flashes brightly!\n");
      return 1+random(4);
   }
}
int
do_water_special(object owner)
{
   if(!random(4))
      {
      tell_object(owner, "\
         Your helmet flashes and absorbs some of the water damage.\n");
      return 0504;
      /* 
      5% [05] resistance boost
      4  [04] ac boost 
      */
   }
}
