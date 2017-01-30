#include "/players/jaraxle/define.h"
inherit "/obj/armor";

void
reset(status arg)
{
   if(arg) return;
   ::reset();
   set_name("frozen mask");
   set_alias("mask");
   set_short(HIC+"frozen mask"+NORM);
   set_type("misc");
   set_weight(1);
   set_long("A steel mask that is blue in shade. A small\n"+
      "snowflake adorns each cheek of the mask.\n");
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
      tell_object(owner, "Your shield flashes a bright "+HIC+"red"+NORM+"\n");
      if(this_player() && this_player()!=owner)
         write(owner->query_name()+"'s "+HIC+"frozen"+NORM+" shield flashes brightly!\n");
      return 1+random(2);
   }
}

int
do_ice_special(object owner)
{
   if(!random(8))
      {
      tell_object(owner, "\
         Your "+CYN+"frozen"+NORM+" shield flashes and reflects some of the "+CYN+"frost"+NORM+" damage.\n");
      return 1504;
      /* 
      15% [15] resistance boost
      4  [04] ac boost 
      */
   }
}
