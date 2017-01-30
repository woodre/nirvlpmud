#include "defs.h"

inherit MONSTER;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  move_object(clone_object(ARM_PATH+"gcloak.c"),this_object()); /* 100 */
  init_command("wear cloak");
  move_object(clone_object(ARM_PATH+"shield.c"),this_object()); /* 200 */
  init_command("wear shield");
  move_object(clone_object(ARM_PATH+"mail.c"),this_object()); /* 700 */
  init_command("wear mail");
  move_object(clone_object(WEP_PATH+"scimitar.c"),this_object()); /* 600 */
  init_command("wield sword");
  add_money(300+random(200)); /* Total is 2000 */
  set_name("suzak");
  set_alt_name("lieutenant");
  set_alias("guard");
  set_short("Lieutenent Suzak");
  set_long(
    "Lieutenant Suzak is a strong young nobleman who has risen swiftly\n"+
    "among the Goldcloaks due to both his efficiency and his fairness.\n"+
    "His long black hair is tied in a braid and his beard is oiled\n"+
    "in the manner of Sudakani nobles.\n"
  );
  set_gender("male");
  set_race("human");
  set_level(19);
  set_wc(29);
  set_ac(16);
  set_hp(460);
  set_al(700);
  set_chat_chance(5);
  load_chat("Suzak asks: What are you doing here?\n");
  load_chat("Suzak says: You are not supposed to be here.\n");
  set_a_chat_chance(20);
  load_a_chat("Lieutenant Suzak's scimitar moves with astounding speed.\n");
  load_a_chat("Lieutenant Suzak deftly feints.\n");
  load_a_chat("Lieutenant Suzak taunts: I am the better swordsman!\n");
  load_spell(15,25,0,
    "\nLieutenent Suzak raises his scimitar high above his head and strikes\n"+
    "you with a mortal blow!\n\n",
    "\nLieutenent Suzak strikes #ATT# with his scimitar!\n\n");
}