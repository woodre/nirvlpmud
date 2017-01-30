#include "defs.h"

inherit "/obj/monster.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("borgas");
  set_alias("brigand");
  set_short("Borgas Brokenose");
  set_long(
"This brigand is huge, muscular, and astoundingly ugly.  His nose has\n\
been broken so many times that it is practically flat.  His stout body is\n\
artfully decorated with years of scars acquired through a variety of\n\
professions.  His clothes are cast-offs, poorly patched and sewn together\n\
and combining to give a slovenly appearance.\n");
  set_gender("male");
  set_race("human");
  set_level(12);
  set_ac(8);
  set_hp(200);
  set_al(-200);
  set_chat_chance(2);
  load_chat("Borgas bounces his head against a rock and bellows loudly.\n");
  load_chat("Borgas flexes his rippling muscles.\n");
  load_chat("Borgas looks at you contemptuously.\n");
  set_a_chat_chance(5);
  load_a_chat("Borgas head-butts you.\n");
  load_a_chat("Borgas performs a perfect roundhouse kick.\n");
  load_a_chat("Borgas grins wickedly.\n");
  move_object(clone_object(WEP_PATH+"scimitar.c"),this_object());
  init_command("wield scimitar");
  move_object(clone_object(ARM_PATH+"buckler.c"),this_object());
  init_command("wear shield");
  set_wc(17);
  set_ac(8);
}
