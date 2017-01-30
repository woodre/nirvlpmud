#include "defs.h"

inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  move_object(clone_object(ARM_PATH+"redcloak.c"),this_object()); 
  init_command("wear cloak");
  move_object(clone_object(ARM_PATH+"mail.c"),this_object());
  init_command("wear mail");
  move_object(clone_object(WEP_PATH+"sword.c"),this_object());
  init_command("wield sword");  
  set_name("eagle");
  set_alt_name("bloody eagle");
  set_short("A "+RED+"Bloody "+HIY+"Eagle"+NORM);
  set_long(
    "This is a mercenary of Jikhal's Bloody Eagles.  The 'Eagles are\n"+
    "a Westeros mercenary outfit with a reputation for playing rough.\n"+
    "They currently have a contract with the Sultan of Sudakan.\n"
  );
  set_gender("male");
  set_race("human");
  set_level(16);
  set_wc(22);
  set_ac(9); /* 13 total with armor */
  set_hp(400);
  set_al(-350);
  set_chat_chance(5);
  load_chat("The Eagle stares at you insolently.\n");
  set_a_chat_chance(20);
  load_a_chat("The Bloody Eagle kicks you in the chest.\n");
  load_a_chat("The Bloody Eagle elbows you on the backswing.\n");  
  load_a_chat("The Bloody Eagle tosses sand in your eyes.\n");
}
