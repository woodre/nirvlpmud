#include "/players/fakir/color.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("skunk");
set_race("creature");
set_short("An Angry Skunk");
set_alias("skunk");
set_long(
  "The skunk you rousted from its nice warm stump is not happy.  It has its\n"+
  "tail curled back and is making thumping sounds with its foot.  It looks\n"+
  "ready to squirt you with its rather smelly perfume!\n");

set_level(4);
set_hp(40 +random(20));
set_al(0);
set_wc(4 +random(3));
set_ac(2 +random(2));

}

