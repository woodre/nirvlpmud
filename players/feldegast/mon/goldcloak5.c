#include "defs.h"

inherit MONSTER;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  move_object(clone_object(ARM_PATH+"gcloak.c"),this_object()); /* 100 */
  init_command("wear cloak");
  move_object(clone_object(ARM_PATH+"shield.c"),this_object()); /* 200 */
  init_command("wear shield");
  move_object(clone_object(ARM_PATH+"guardhelm.c"),this_object()); /* 1000 */
  init_command("wear helm");  
  move_object(clone_object(ARM_PATH+"mail.c"),this_object()); /* 700 */
  init_command("wear mail");
  move_object(clone_object(WEP_PATH+"scimitar.c"),this_object()); /* 600 */
  init_command("wield sword");
  add_money(1300+random(200)); /* Total is 4000 */
  set_name("valesh");
  set_alt_name("captain");
  set_alias("guard");
  set_short("Captain Valesh");
  set_long(
    "Captain Valesh is a large man with a strong muscular body.  His\n"+
    "features are dark, from his long, braided hair to his intelligent\n"+
    "black eyes.  Captain Valesh rose to his current rank through\n"+
    "cunning and political acumen.\n"
  );
  set_gender("male");
  set_race("human");
  set_level(20);
  set_wc(32);
  set_ac(10); /* 17 total */
  set_ac_bonus(7);
  set_hp(520);
  set_al(700);
  set_chat_chance(5);
  load_chat("Valesh says: You are not one of my men.\n");
  load_chat("Valesh says: How did you get in here?\n");
  set_a_chat_chance(20);
  load_a_chat("Valesh twirls his scimitar about his body.\n");
  load_a_chat("Valesh parries with his scimitar.\n");
  load_a_chat("Valesh says: You're slow and weak!\n");
  load_spell(25,15,0,
    "\nCaptain Valesh bashes you with his shield.\n\n",
    "\nCaptain Valesh bashes #ATT# with his shield.\n\n");
  load_spell(30,15,0,
    "\nCaptain Valesh raises his scimitar high above his head before\n"+
    "bringing it down on you with all his might!\n\n",
    "\nCaptain Valesh brandishes his scimitar!\n\n");
    
  set_dead_ob(this_object());
}
monster_died() {
 write_file("/players/feldegast/log/monsters.log",ctime(time())+" "+TPRN+" killed Goldcloak captain\n");
}
