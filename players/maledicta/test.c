#include "/players/maledicta/ansi.h"
#define WEAPON "/players/maledicta/cont/skaven/obj/shortsword.c"
#define ARMOR "/players/maledicta/cont/skaven/obj/scalemail.c"
#define SHIELD "/players/maledicta/cont/skaven/obj/shield.c"

inherit "obj/monster.c";

object peep;
object gold;
object shield;
object weapon;
object armor;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("skaven");
set_alt_name("warrior");
set_alias("skaven warrior");
set_race("skaven");
set_short("Skaven Warrior");
set_long(
"  This is a reddish-brown furred ratlike humanoid.  It is\n"+
"around four feet in height, and has dark black eyes that\n"+
"stare at you menacingly.  It is a wiry creature, with a\n"+
"short sword in its hand, and a shield in the other.  A\n"+
"nasty scalemail protects its body.\n"); 
set_level(2);
set_hp(30);
set_al(-1000);
set_wc(6);
set_ac(3);
set_aggressive(1);
set_heart_beat(1);
}
