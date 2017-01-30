#include "defs.h"

inherit MONSTER;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("man");
  set_alt_name("hooded man");
  set_short("A hooded man");
  set_long(
"The hooded man sits in a corner of the bar, unnoticed except for\n"+
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
    "The Hooded Man grasps #ATT$ with death cold hands.\n"
  );

  move_object(clone_object(ARM_PATH+"hoodcloak.c"),this_object());
  move_object(clone_object(WEP_PATH+"flail.c"),this_object());
  init_command("wear cloak");
  init_command("wield flail");
  set_wc(27);
  set_ac(14);
  set_dead_ob(this_object());
}
void monster_died(object ob) {
  object corpse;
  tell_room(environment(),
    "As the hooded man's body falls to the floor, his hood falls off of his\n"+
    "face, exposing a skull covered in rotting flesh.\n");
  corpse=present("corpse",environment());
  if(corpse)
    move_object(clone_object(OBJ_PATH+"scroll-escape.c"),corpse);
}
 