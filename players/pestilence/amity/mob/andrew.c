/* Assistance code provided by Jaraxle*/
#include "/players/pestilence/ansi.h"
inherit "/players/vertebraker/closed/std/monster";
#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
#define attacker attacker_ob
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Andrew");
  set_alt_name("andrew");
  set_alias("andrew dailey");
  set_short("Andrew Dailey");
  set_long("Andrew is a tall, lanky man.  He has light brown hair with brown eyes.\n"+
           "He is content on protection his wife and son.\n");
  set_race("human");
  set_gender("male");
  set_level(18);
  set_wc(22+random(8));
  set_ac(11+random(8));
  set_hp(400);
  set_heal(4,6);
  add_money(2800+random(900));
  set_aggressive(0);
  set_dead_ob(this_object());
  set_al(0);
  load_chat("Andrew says: don't worry we will be safe.\n");
  load_chat("Andrew says: The ants will be gone soon don't worry.\n");
  set_chat_chance(15);
  load_a_chat("Andrew punches you in the face.\n");
  load_a_chat("Andrew says: to think we thought the ants were our major problem.\n");
  set_a_chat_chance(25);
  set_spell_mess2("Andrew hits you with a combination punch to your stomach and head.\n");
  set_spell_mess1("Andrew hits his attacker with a combination punch to the head and stomach.\n");
  set_chance(30);
  set_spell_dam(30);
}
