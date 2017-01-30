/*  hairpin  */

#include "/players/eurale/closed/ansi.h"
inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("hairpin");
set_alias("pin");
set_short(GRY+"diam"+HIW+"*"+GRY+"nd hairpin"+NORM);
set_long(
	"  This slender, diamond-studded hairpin is used to keep a lady's\n"+
	"long locks in place on special occasions.\n");
set_class(17);
set_weight(1);
set_type("knife");
set_value(900);
set_hit_func(this_object());
}

weapon_hit(attacker) {
int W;
W = random(13);
if(W>7)  {
  say("\nThe hairpin "+GRY+"PIERCES"+NORM+" it's target.\n\n");
  write("\nYou "+GRY+"STAB VICIOUSLY"+NORM+" with the hairpin.\n\n");
  return 4; }
return;
}

query_wear() { int wear; wear = 3*hits/22; return wear; }
