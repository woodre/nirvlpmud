/*
Just like the squires.  Meant to be a commentary upon the similarity
of the lower classes regardless of their ideology.  Or lazy recyling
of material.  You decide.
*/
#include "defs.h"

inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  move_object(clone_object(ARM_PATH+"leather.c"),this_object()); /* 300 */
  init_command("wear armor");
  move_object(clone_object(WEP_PATH+"sknife.c"),this_object()); /* 350 */
  init_command("wield knife");
  add_money(100+random(200));
  set_name("cultist");
  set_alt_name("darke cultist");
  set_short("Darke Cultist");
  set_long(
    "This sinister looking person is swathed in the black robes of the\n"+
    "Darke cult.  These fiendish demon worshippers supposedly work to\n"+
    "bring a demon lord into the world in order to further their dreams\n"+
    "of wealth and power.\n"
  );
  set_gender("male");
  set_race("human");
  set_level(15);
  set_wc(18+random(3));
  set_ac(11+random(3));
  set_hp(200+random(50));
  set_al(-400-random(400));
  set_chat_chance(4);
  load_chat("Cultist says: This castle is haunted, I'm sure of it.\n");
  load_chat("Cultist says: Oh, my aching back.\n");
  load_chat("Cultist says: This land is too hot and dry.\n");
  load_chat("Cultist says: What're the odds we'll actually find the stone anyway?\n");
  load_chat("Cultist complains: Move this, move that, cook this, kill that.\n");
  set_aggressive(1);
}
