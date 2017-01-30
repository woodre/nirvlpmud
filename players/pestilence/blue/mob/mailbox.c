#include "/players/pestilence/ansi.h"
inherit "/obj/monster.c";
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_alias("blue's mailbox");
  set_name("mailbox");
  set_short("Blue's Mailbox");
  set_long("A large purple Mailbox with a pink flag and a smiley face.\n");
  set_level(2);
  set_gender("male");
  set_race("mailbox");
  set_wc(6);
  set_ac(3);
  set_hp(30);
  set_ep(20000);
  add_money(0);
  set_aggressive(0);
set_dead_ob(this_object());
  set_al(200);
  load_chat("Mailbox says: Steve i have mail.\n");
  set_chat_chance(5);
  load_a_chat("Mailbox says: I'm protected by the U.S. Postal Service.\n");
  load_a_chat("Mailbox hits you with his flag.\n");
set_a_chat_chance(10);
}
monster_died() {
  move_object(clone_object("/players/pestilence/blue/obj/letter.c"),
      environment(this_object()));
  tell_room(environment(this_object()),
        "As Mailbox hits the ground a letter flies out.\n");
return 0; }
