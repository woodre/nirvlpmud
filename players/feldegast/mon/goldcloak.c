#include "defs.h"

inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  move_object(clone_object(ARM_PATH+"gcloak.c"),this_object());
  init_command("wear cloak"); /* 100 coins */
  move_object(clone_object(ARM_PATH+"ringmail.c"),this_object());
  init_command("wear mail");  /* 600 coins */
  move_object(clone_object(WEP_PATH+"pike.c"),this_object());
  init_command("wield pike");  /* 600 coins */
  add_money(50*random(9)); /* 0-400 coins */
  set_name("goldcloak");
  set_alt_name("guard");
  set_short("A "+HIY+"Goldcloak"+NORM);
  set_long(
    "This is an elite guard of the Sultan's army.  They wear gold\n"+
    "colored cloaks over their armor, which has earned them the\n"+
    "nickname 'Goldcloaks'.  They are highly trained and well\n"+
    "equiped for both urban and desert combat.\n"
  );
  set_gender("male");
  set_race("human");
  set_level(16);
  set_wc(22);
  set_ac(9); /* 13 total with armor */
  set_ac_bonus(4);
  set_hp(300); /* Changed from 400 to 300 due to new monster guide 1/10/01 */
  set_al(500);
  set_chat_chance(5);
  load_chat("Goldcloak says: Move along.\n");
  load_chat("The Goldcloak looks at you suspiciously.\n");
  set_a_chat_chance(20);
  load_a_chat("The Goldcloak kicks you in the chest.\n");
  load_a_chat("The Goldcloak elbows you on the backswing.\n");  
}
