#include "/players/jaraxle/define.h"
inherit "obj/weapon.c";
int broke;

reset(arg){
  ::reset(arg);
  if (arg) return;

broke =1;
set_name("machete");
set_alias("machete");
set_short("A machete");
set_long(
  "A dirty old machete. It looks as though you can barely cut through bushes with this.\n");

set_type("sword");  /*  sword/knife/club/axe/bow/polearm  */
set_class(5);
set_weight(1);
set_value(200);
set_hit_func(this_object());
}
query_wear() {    int wear;    wear = 300;   return wear; }

weapon_hit(attacker){
int W;
W = random(13);
if(W>9)  {
  say(
  ""+TPRN+" hacks at you.\n");

  write(
   "You hack at your enemy with the machete.\n");
  return 3;
   }
return;
}

