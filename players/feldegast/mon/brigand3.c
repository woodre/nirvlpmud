#include "defs.h"

inherit "/obj/monster.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("natarios");
  set_alias("dashing");
  set_alt_name("brigand");
  set_short("Natarios the Dashing Brigand");
  set_long(
"This brigand wears his confidence like a cape around his shoulders.  His\n\
face is chiseled, perhaps even handsome if it weren't for his arrogant and\n\
cold green eyes.  His thin lips are curled back in a snear of contempt for\n\
all who stand in his way.  He wears an expensive, but too large white\n\
tunic, and a good pair of black boots that're well past repairability.\n");
  set_gender("male");
  set_race("human");
  set_level(13);
  set_hp(200);
  set_al(-200);
  set_chat_chance(2);
  load_chat("Natarios paces majestically about the camp.\n");
  load_chat("Natarios strokes his chin thoughtfully.\n");
  set_a_chat_chance(5);
  load_a_chat("Natarios wields his weapon with skill and panache.\n");
  load_a_chat("Natarios leaps up into the air and delivers a powerful kick.\n");
  move_object(clone_object(WEP_PATH+"scimitar.c"),this_object()); /* 600 coins */
  init_command("wield scimitar");
  move_object(clone_object(ARM_PATH+"gauntlet.c"),this_object()); /* 50 coins*/
  init_command("wear gauntlet");
  add_money(random(100));
  set_wc(17);
  set_ac(10);

}

