#include "defs.h"

inherit MONSTER;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  move_object(clone_object(OBJ_PATH+"seal.c"),this_object()); /* 650 */
  move_object(clone_object(OBJ_PATH+"skull.c"),this_object()); /* 3500 */
  move_object(clone_object(WEP_PATH+"sknife.c"),this_object()); /* 350 */
  init_command("wield knife");
  add_money(random(2000));
  set_name("cleric");
  set_alt_name("darke cleric");
  set_short("Darke Cleric");
  set_long(
    "This sinister looking person is swathed in the black robes of the\n"+
    "Darke cult.  These fiendish demon worshippers supposedly work to\n"+
    "bring a demon lord into the world in order to further their dreams\n"+
    "of wealth and power.  This member of the Darke cult appears more\n"+
    "sinister than the others.  He has grown strong under the tutelage\n"+
    "of his demon master.\n"
  );
  set_gender("male");
  set_race("human");
  set_level(21);
  set_wc(32); /* Compensated by spells */
  set_ac(22);
  set_hp(750);
  set_al(-950);
  set_chat_chance(4);
  load_chat("Darke Cleric says: It must be here...\n");
  load_spell(50,25,0,
    "\nThe Darke Cleric mutters a prayer to his master...\n"+
    MAG+"\tYou are swept up into a vortex of negative energy!\n\n"+NORM,
    MAG+"#ATT# is swept up into a vortex of negative energy!\n\n"+NORM);
  load_spell(40,20,2,
    BOLD+BLK+"\nA dark aura surrounds the Cleric, draining your energy.\n\n"+NORM,
    BOLD+BLK+"\n#ATT# is drained by the Dark Cleric's aura.\n\n"+NORM);
  load_spell(30,20,1,
    "The Darke Cleric brushes your skin with the tips of his fingers...\n"+
    "\tYour flesh crawls and goes black where he touched you.\n",
    "The Darke Cleric touches #ATT# with his deadly touch.\n");
}
