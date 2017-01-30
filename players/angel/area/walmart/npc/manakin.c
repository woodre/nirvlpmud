#include <ansi.h>

inherit "obj/monster";

reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
  /* fixed typo (miz) */
  set_name("Magical Mannequin");
  set_race("mannequins");
  set_alias("mannequin");
  set_short(HIM+"Magical Mannequin"+NORM);
  set_long("\
  This is a Magical Mannequin. It is over 6 feet tall with a\n\
slender build. This mannequin was made of plastic from ancient\n\
Eqypt. An Egyptian has been reincarnated in the department store\n\
mannequin with great magical power.\n");
  set_level(21 + random (4));
  set_hp(629 + random (100));
  set_ac(19 + random (9));
  set_wc(35 + random (9));
  set_al(0);
  set_dead_ob(this_object());
  set_chat_chance(10);
  load_chat(query_name()+" asks, \"are you ready to DIE???\"\n");
  load_chat("Mannequin says, does the molten plastic taste GREAT?\n");
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  set_multi_cast(1);

  add_spell("muttered curse",
"#MN# mutters an ancient $HM$CURSE$N$ upon you!\n",
"#MN# mutters an ancient $HM$CURSE$N$ upon #TN#!\n",
5,({10,10}),({"other|mental","magical"}));

  add_spell("molten fireball",
"#MN# flummox a large chunk of Molten $HR$FIREBALL$N$\n\
then discharges it swiftly in your direction!\n",
"#MN# flummox a large chunk of Molten $HR$FIREBALL$N$\n\
then discharges it swiftly at #TN#!\n",
20,({25,40}),({"physical","other|earth"}));

  add_spell("death wings",
"#MN# shierk a ominous $HM$curse$N$, They who enter this sacred tomb shall be\n\
visited by $HR$Wings of Death!$N$\n",0,
10,30,"other|evil");

  add_spell("twisted fireball",
"#MN# calls upon the gods of Ancient Eqypt for a $HW$TWISTED$N$-$HR$FIREBALL$N$\n\
engulfing you!\n",
"#MN# calls upon the gods of Ancient Eqypt for a $HW$TWISTED$N$-$HR$FIREBALL$N$!\n",
15,({25,35}),({"other|fire","other|evil"}),1);

}

monster_died() {
  tell_room(environment(this_object()),
  "\n"+HIM+"Mannequin"+NORM+" falls to its knee's and screech's out\n\
"+HIW+"Your estate shall belong to the fire, and your house to the consuming flame!"+NORM+"\n");
    return 0;
}

status id(string str) {
  return (status)::id(str) ||
          str=="manakin";
}

