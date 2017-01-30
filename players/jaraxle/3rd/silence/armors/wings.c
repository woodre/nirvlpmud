/*  10/08/06 - Rumplemintz: removed trailing ; from #include  */
inherit "/obj/armor";
#include "/players/jaraxle/define.h"

void
reset(status arg)
{
   if(arg) return;
   ::reset();
   set_name("fairy wings");
   set_alias("wings");
   set_short("Fairy "+HIM+"Wi"+HIW+"n"+HIM+"gs"+NORM);
   set_type("misc");
   set_weight(0);
  set_long("A translucent pair of small Fairy Wings.  A rainbow of glass-like colors can be seen\nin the gaps of the wings.\n");
   set_ac(1); /* physical ac */
   set_value(1+random(25));
   set_params("other|wind", 2, 20, "do_wind_special");
   /* 2 ac, 20% resistance to other|wind damage,
   plus it calls the 'do_wind_special()' function */
}

do_special(owner){
  if(!random(6)){
   tell_object(owner, "Your wings close around you,  quickly "+HIM+"protecting"+NORM+" you from the "+RED+"blow"+NORM+"!\n");
    if(this_player() && this_player()!=owner)
      write(owner->query_name()+"'s Fairy Wings flash brightly!\n");
return 1+random(7);
  }
}
int
do_wind_special(object owner)
{
if(!random(2)){
   tell_object(owner, "\tYour wings "+HIB+"spread out"+NORM+", lifting you high into the "+HIC+"air"+NORM+".\n");
      return 1002;
      /* 
      10% [10] resistance boost
      2  [02] ac boost 
      */
    }
}
