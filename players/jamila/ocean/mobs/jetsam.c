#include "/players/jamila/define.h"

inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
  set_dead_ob(this_object());
  if(arg) return;
  set_name("jetsam");
  set_alt_name("eel");
  set_alias("fish");
  set_short("Jetsam");
  set_long(
"Jetsam is one of Ursula's minions.  He along with his\n"+
"buddy Flotsam follow her orders and do her bidding.  They\n"+
"aren't the smartest fish in the sea but they have been\n"+
"known to spy successfully so watch out.\n"
  );
  set_gender("male");
  set_race("fish");
  set_level(20);
  set_wc(28+random(3));
  set_ac(23+random(2));
  set_hp(800+random(20));
  set_al(-500);
  set_chat_chance(6);  
  set_a_chat_chance(6);
  load_chat("Jetsam sneaks around.\n");
  load_a_chat("Jetsam snickers and gives away his position.\n");
  set_chance(6);
  set_spell_mess1(
"\n\tJetsam strikes at his opponent and bites at them causing\n"+
"\t\tan electric shock through their body.\n\n"
  ); /* 3RD PERSON */
  set_spell_mess2(
"\n\tJetsam strikes at you and bites causing an electric shock\n"+
"\t\tto run through your body.\n\n"
  ); /* 1ST PERSON */
  set_spell_dam(30);
}
monster_died() {
object gold;
tell_room(environment(this_object()),
  "Jetsam dies and leaves behind a small pile of gold,\n"+
  "this must be his small payment from Ursula.\n");
  gold = clone_object("obj/money");
  gold->set_money(6500+random(500));
  move_object(gold,environment(this_object()));
return 1; }
