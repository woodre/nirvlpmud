#include "defs.h"

inherit MONSTER;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  move_object(clone_object(ARM_PATH+"hoodcloak.c"),this_object()); /* 300 */
  move_object(clone_object(WEP_PATH+"flail.c"),this_object()); /* 700 */
  init_command("wear cloak");
  init_command("wield flail");
  set_name("man");
  set_alt_name("hooded man");
  set_short("A hooded man");
  set_long(
"The hooded man sits in a corner of the room, unnoticed except for\n"+
"a strange odor that emanates from his vicinity.  He wears a dark\n"+
"black, hooded cloak with a hood pulled down over his face.  His\n"+
"hands, the only part of him visible, are grey and appear ill.\n"
  );
  set_gender("male");
  set_race("undead");
  set_level(18);
  set_wc(27); /* +1 */
  set_ac(14); /* -1 */
  set_hp(475); /* +25 */
  set_al(-500);
  set_chat_chance(3);
  load_chat("Something smells like it died in here.\n");
  load_spell(10,10,2, /* Sp drain */
    "The Hooded Man grasps you with"+HIW+" death cold hands"+NORM+".\n",
    "The Hooded Man grasps #ATT# with death cold hands.\n"
  );
  set_dead_ob(this_object());
/*
  add_talk("quest",
"The Hooded Man rasps: Long ago, this desert was rich farmland and\n"+
"\tthe heart of a magnificent civilization.  A wise sorcerer\n"+
"\tking ruled the people and all were happy.  But this utopia\n"+
"\twas not to last...Malicious people, jealous of the wise king,\n"+
"\tattempted to overthrow him against the people's will.  The\n"+
"\twise king attempted to summon a creature of power from\n"+
"\tanother dimension to aid him...It was a risky gamble, for\n"+
"\tthe creature was a demon named Jal-Hab.  The rebels inter-\n"+
"\trupted the spell, considering it better to risk the land's\n"+
"\teternal damnation rather than be defeated.  In a great battle,\n"+
"\tthe four rebel leaders and the wise king fought...The king was\n"+
"\tdefeated and barely escaped.  The gateway to the demon\n"+
"\tdimension was left open to poison the land.  Your quest is\n"+
"\tto close the gateway and save the Jal-Hab.\n");
  add_talk(({ "king", "wise king", }),
    "The Hooded Man rasps: The wise king of the story is my master,\n"+
    "\tKing Malador.  He has entrusted me with finding a worthy\n"+
    "\thero to undergo this quest.\n");
  add_talk("reward",
    "The Hooded Man rasps: If you accomplish this task, then my king\n"+
    "\twill reward you with all the gold you will ever need.\n");
  add_talk("gateway",
    "The Hooded Man rasps: The gateway is a temple known as Daemonsraad.\n"+
    "\tYou will have to locate it.  I do not know how to close\n"+
    "\tthe gateway myself.  The rebels had a plan to close the\n"+
    "\tgate, but they could not complete it after two of them\n"+
    "\twere slain in the great battle.\n");
*/
}

void monster_died(object ob) {
  tell_room(environment(),
    "As the hooded man's body falls to the floor, his hood falls off of his\n"+
    "face, exposing a skull covered in rotting flesh.\n");
}
 