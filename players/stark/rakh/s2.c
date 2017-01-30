inherit "obj/weapon.c";
#include "/players/stark/defs.h"
reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("katana");
set_alias("sword");
set_short("Crappy Katana");
set_long(
"The sword of the Duelist, Touga\n"+
"It is a traditional Katana.  Simply from the feel of the blade \n"+
"you can tell it has had a strong and proud history.  The grip \n"+
"has recently been redone, giving even more control. \n");

set_type("sword");  /*  sword/knife/club/axe/bow/polearm  */
set_class(5);
set_weight(3);
set_value(1000);
set_hit_func(this_object());
}
weapon_hit(attacker){
int W;
W = random(13);
if(W>9)  {
  say(
" "+this_player()->query_name()+" looks into the eyes of "+this_player()->query_possessive()+" enemy and smiles deeply...\n"+
"   "+attacker->query_name()+" lets it's guard down at the sign of sincerity\n"+
"      "+this_player()->query_name()+" "+RED+"stabs"+NORM+" the Katana deep into "+attacker->query_name()+"\n");

  write(
" You look into the eyes of "+attacker->query_name()+" and smile deeply...\n"+
"   "+attacker->query_name()+" lets it's guard down at the sign of your sincerity\n"+
"      You "+RED+"stab"+NORM+" the Katana deep into "+attacker->query_name()+"\n");
  return 4;
   }
return;
}


