#include "defs.h"

inherit MONSTER;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("gregor");
  set_alias("leader");
  set_alt_name("brigand");
  set_short("Gregor, the Brigand Leader");
  set_long(
"Gregor is a fearsome half-breed orc.  He has benefited from both\n"+
"his orcish and human heritage, possessing both the ample strength\n"+
/* This is right about where my inspiration wore out. */
"of an orc and the cunning of a human.  He has kept this band of\n"+
"brigands together using both and once he dies, the other brigands\n"+
"will likely scatter.\n"
  );
  set_gender("male");
  set_race("orc");
  set_level(20);
  set_hp(550);
  set_al(-800);
  set_chat_chance(4);
  load_chat("Gregor smiles, exposing sharp rows of teeth.\n");
  load_chat("Gregor says: Well, are you going to fight me or what?\n");
  set_a_chat_chance(35);
  load_a_chat("Gregor roars as he kicks you with his heavy boots.\n");
  load_a_chat("Gregor shouts: To the death!\n");
  load_a_chat("Gregor head-butts you!\n");
  load_spell(35,30,0,
    "\nGregor roars as he presses the offensive, slashing left and right!\n\n",
    "\nGregor roars as he presses the offensive, slashing left and right!\n\n"
  );
  add_money(random(1000));
  move_object(clone_object(OBJ_PATH+"key2.c"),this_object()); /* 50 */
  move_object(clone_object(ARM_PATH+"starshield.c"),this_object()); /* 1000 */
  move_object(clone_object(ARM_PATH+"ringmail.c"),this_object()); /* 800 */
  move_object(clone_object(WEP_PATH+"sword.c"),this_object()); /* 600 */
 
  init_command("wear shield"); 
  init_command("wear mail");
  init_command("wield sword");

 
  set_wc(32);
  set_ac(12); /* +5 for armor bonuses */
  set_ac_bonus(5);
  set_dead_ob(this_object());
}

monster_died() {
  write_file("/players/feldegast/log/monsters.log",ctime(time())+" "+TPRN+" killed Brigand Leader\n");
}
