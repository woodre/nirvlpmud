#include "/players/feldegast/closed/ansi.h"
#include "/players/feldegast/closed/shortcut.h"
inherit "/obj/monster";
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("python");
  set_short(GRN+"A python"+NORM);
  set_long(
"The python is a long snake, approximately 5 meters in length.\n"+
"His tongue flicks out, tasting the air as he slowly slithers\n"+
"around the room.\n"
  );
  set_gender("male");
  set_race("snake");
  set_level(5);
  set_wc(9);
  set_ac(5);
  set_hp(75);
  set_al(0);
  set_chat_chance(2);
  load_chat("The python slithers.\n");
  set_dead_ob(this_object());
  set_a_chat_chance(10);
  load_a_chat("The python wraps itself around your limbs.\n");
  load_a_chat("The python C R U S H E S you!\n");
}
monster_died(ob) {
  object skin;
  skin=clone_object("/players/feldegast/island/npc/snake_skin");
  move_object(skin,environment(ob));
}
