#include "/players/coldwind/define.h"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("chain");
set_alias("weapon");
set_short(HIK+"Battle Chain"+NORM);
set_long(HIK+
" Black rings connected together making a powerful chain. It's somewhat\n"+
"heavy for being two and half feet long; nevertheless, in the hands of a\n"+
"trained soldier, the chain can be a very deadly weapon.\n"+NORM);
set_type("mace");
set_class(18);
set_weight(5);
set_value(1000);
set_hit_func(this_object());
}

weapon_hit(attacker){
int W;
object user;
user = environment(this_object())->query_name();
W = random(20);
if(W>15)  {
  say(HIK+"\n"+
          "()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()\n"+
          ""+NORM+RED+"   The chain Twirls few times before it "+HIR+"C R U C H E S"+NORM+RED+" your bones.\n"+
    ""+HIK+"()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()"+NORM+"\n"+ 
  " \n");

  write(HIK+"\n"+
          "()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()\n"+
          ""+NORM+RED+"   The chain Twirls few times before it "+HIR+"C R U C H E S "+NORM+RED+ attacker->query_name() +"'s bones.\n"+
      ""+HIK+"()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()"+NORM+"\n"+ 
" \n");
  return 7;
   }
if(W>11)  {
  say(RED+"The chain twirls in the air"+HIK+"\n"+
   ""+HIR+""+ attacker->query_name() + " falls on the ground with broken bones"+NORM+"\n");

  write(RED+"You twirl the chain in the air"+HIK+"\n"+
     ""+HIR+""+ attacker->query_name() + " falls on the ground with broken bones"+NORM+"\n");

  return 4;
   }
return;
}
