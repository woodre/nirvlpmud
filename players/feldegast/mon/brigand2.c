#include "defs.h"

inherit "/obj/monster.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("slika");
  set_alias("brigand");
  set_short("Slika the Living Rainbow");
  set_long(
"This brigand is slim, almost anemic, and perhaps half-starved.  His eyes\n\
are shifty, with perhaps a hint of desperation.  His entire torso, or at\n\
least as much of it as you can see, is covered in tattoos.  He wears a worn-\n\
out jacket and a threadbare pair of trousers.  His shoes are little more\n\
than straps of leather tied around his feet.\n");
  set_gender("male");
  set_race("human");
  set_level(12);
  set_ac(8);
  set_hp(200);
  set_al(-200);
  set_chat_chance(2);
  load_chat("Slikas rocks back and forth on his heels.\n");
  load_chat("Slikas drools.\n");
  set_a_chat_chance(5);
  load_a_chat("Slikas screams and starts frothing at the mouth.\n");
  load_a_chat("Slikas launches himself at your legs and starts gnawing.\n");
  move_object(clone_object(WEP_PATH+"scimitar.c"),this_object());
  init_command("wield scimitar");
  move_object(clone_object(ARM_PATH+"amulet2.c"),this_object());
  init_command("wear amulet");
  set_wc(17);
  set_ac(8);
}

