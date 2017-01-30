#include "/players/jaraxle/define.h"
inherit "/obj/armor";

void
reset(status arg)
{
   if(arg) return;
   ::reset();
   set_name("frozen ring");
   set_alias("frozen_ring");
   set_short(HIC+"frozen ring"+NORM);
   set_type("ring");
   set_weight(1);
set_long("A small golden ring.  The gold is very\n"+
"cold to the touch and frosted.\n");
   set_ac(1); /* physical ac */
   set_value(500+random(300));
   set_params("other|ice", 1, 25, "do_ice_special");
   /* 1 ac, 25% resistance to other|ice damage,
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
      tell_object(owner, "Your ring flashes a bright "+HIC+"blue"+NORM+"\n");
      if(this_player() && this_player()!=owner)
         write(owner->query_name()+"'s "+HIC+"frozen"+NORM+" ring flashes brightly!\n");
      return 1+random(2);
   }
}

int
do_ice_special(object owner)
{
   if(!random(8))
      {
      tell_object(owner, "\
         Your "+CYN+"frozen"+NORM+" ring flashes and reflects some of the "+CYN+"frost"+NORM+" damage.\n");
      return 1504;
      /* 
      15% [15] resistance boost
      4  [04] ac boost 
      */
   }
}
