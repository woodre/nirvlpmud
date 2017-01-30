#include "/players/pestilence/ansi.h"
inherit "/players/vertebraker/closed/std/monster";
#define TP this_player()
#define attacker attacker_ob
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Jason");
  set_alt_name("jason");
  set_alias("jason the pervert");
  set_short("Strip club customer named Jason");
  set_long("Jason is 5 feet and 11 inches tall, with short brown hair and brown\n"+
           "eyes.  He is a regular customer of Pesty's Strip Club.\n");
  set_race("human");
  set_gender("male");
  set_level(18);
  set_wc(30);
  set_ac(17);
  set_hp(500);
  set_heal(5,3);
  add_money(3000 + random(2000));
  set_aggressive(0);
  set_dead_ob(this_object());
  set_al(0);
  load_chat("Jason says: Wow these girls are the best.\n");
  load_chat("Jason says: This place is much better than Score's.\n");
  set_chat_chance(20);
  load_a_chat("Jason says: You bastard.  Can't you leave me alone.\n");
  load_a_chat("Jason pushes you.\n");
  set_a_chat_chance(30);
  set_spell_mess2("Jason punches you in the eye, causing some irritation.\n");
  set_spell_mess1("Jason throws a flurry of punches at his opponent.\n");
  set_chance(15);
  set_spell_dam(20);
}
id(str) { return (::id(str) || str == "pervert"); }
