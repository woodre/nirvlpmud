#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("aartuk");
set_alias("second");
set_race("creature");
set_short(HIG+"Aartuk"+NORM);
set_long(
  "  This aartuk has a body generally shaped like a star.  It is covered\n"+
  "with thick, flexible bark, similar to spiked leather.  It moves on\n"+
  "it's branches, the tips of which end in suction cups that it uses\n"+
  "to hold onto verticle or inverted surfaces.  Each suction cup houses\n"+
  "a cluster of  3 retractable pseudopods that it uses to handle small\n"+
  "objects.  The head stands on a six-foot-tall, snake-like stalk that\n"+
  "can coil in and out of the center of the star.  It is oblong, with a\n"+
  "hole on one end surrounded by 3 black lumps which are sensory organs.\n"+
  "These organs detect movement, smell and provide infrared vision.\n");

set_level(19);
  set_hp(450 + random(50));
  set_al(- random(100));
  set_wc(28);
  set_ac(16);
  set_aggressive(1);

set_chat_chance(12);
  load_chat("The aartuk head moves your way.......\n");
  load_chat("You feel revulsion....\n");
set_a_chat_chance(15);
  load_a_chat("\nThe aartuk spits a stone pellet at your eye..\n");
  load_a_chat("\nYou feel the aartuk's gooey tongue hit your face..\n");
  load_a_chat("\nThe aartuk entangles you with it's neck....\n");

gold = clone_object("obj/money");
gold->set_money(1500 + random(1000));
move_object(gold,this_object());
}
