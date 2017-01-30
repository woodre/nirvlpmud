#include <ansi.h>

inherit "obj/monster";

reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("venus");
  set_alt_name("flytrap");
  set_alt_name("fly");
  set_alt_name("trap");
  set_race("Dionaea muscipula");
  set_alias("venus");
  set_short("Venus flytrap");
  set_long("\
  Awe inspiring when first seen in action, the Venus flytrap\n\
is without doubt the most famous of all carnivorous plants. Venus\n\
flytraps are native only to the coastal plain of southeastern North\n\
Carolina and extreme northeastern South Carolina. It is a small\n\
rosette plant, generally six to eight inches in diameter. The leaves\n\
consist of leaf stems, or petioles, that may be heart-shaped and flat\n\
on the ground, or thin and upright. The trap will close in less than\n\
a second and start secreting digestive juices eating you up.\n");
  set_level(21);
  set_hp(560 + random (100));
  set_ac(20 + random (9));
  set_wc(38 + random (9));
  set_al(0);
  set_chat_chance(15);
  load_chat(query_name()+" says, \"I am looking for a tasty snack!\"\n");
  load_chat("The wind flows through the Garden Center and tugs your hair!\n");
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  set_multi_cast(1);

  add_spell("trap",
"#MN# the Dionaea muscipula $HR$TRAPS$N$ you\n\
and releases its juices!\n",
"#MN# the Dionaea muscipula $HR$Traps$N$ #TN#.\n",
20,({65,40}),({"physical","other|poison"}));

  add_spell("paralyzing juice",
"#MN# injects its $HM$Paralyzing Juices$N$, you feel all of your strength $HW$ZAPPED!$N$\n",0,
10,30,"other|evil");
}