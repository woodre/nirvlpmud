/*  10/08/06 - Rumplemintz: removed trailing ; from #include */
inherit "/obj/armor";
#include "/players/jaraxle/define.h"

void
reset(status arg)
{
   if(arg) return;
   ::reset();
   set_name("flaming shield");
   set_alias("flaming_shield");
   set_short(RED+"flaming shield"+NORM);
   set_type("shield");
   set_weight(2);
   set_long("A small shield made of black iron.  A large\n"+
      "fireball streaks across the face.\n");
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
      tell_object(owner, "Your shield flashes a bright "+HIR+"red"+NORM+"\n");
      if(this_player() && this_player()!=owner)
         write(owner->query_name()+"'s "+HIR+"flaming"+NORM+" shield flashes brightly!\n");
      return 1+random(2);
   }
}

int
do_fire_special(object owner)
{
   if(!random(8))
      {
      tell_object(owner, "\
         Your "+RED+"flaming"+NORM+" shield flashes and reflects some of the "+RED+"flame"+NORM+" damage.\n");
      return 1504;
      /* 
      15% [15] resistance boost
      4  [04] ac boost 
      */
   }
}
