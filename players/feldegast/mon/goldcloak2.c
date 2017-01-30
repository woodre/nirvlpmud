#include "defs.h"

inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  move_object(clone_object(OBJ_PATH+"key3.c"),this_object()); /* 5 */
  move_object(clone_object(ARM_PATH+"gcloak.c"),this_object()); /* 100 */
  init_command("wear cloak");
  move_object(clone_object(WEP_PATH+"blackjack.c"),this_object()); /* 100 */
  init_command("wield pike");  
  add_money(245+random(100)); /* 500 total plus 50 in room */
  set_name("gaoler");
  set_alt_name("guard");
  set_short("A gaoler");
  set_long(
    "The tower's gaoler is a petty man with a sniveling expression\n"+
    "on his face and little respect for his charges.  He limps along\n"+
    "with a club foot.\n"
  );
  set_gender("male");
  set_race("human");
  set_level(12);
  set_wc(16);
  set_ac(8); /* 9 total with armor */
  set_hp(180);
  set_al(-50);
  set_chat_chance(5);
  load_chat("Gaoler says: You don't belong here.\n");
  load_chat("Gaoler says: What are you doing here?\n");
  set_a_chat_chance(20);
  load_a_chat("The gaoler screams for help!\n");
  set_whimpy();
}
