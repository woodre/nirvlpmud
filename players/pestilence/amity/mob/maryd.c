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

  move_object(clone_object("/players/pestilence/amity/arm/dring.c"),
        this_object());
  command("wear ring");

  set_name("Mary");
  set_alt_name("mary");
  set_alias("mary dailey");
  set_short("Mary Dailey");
  set_long("Mary Dailey is about five foot and one inch tall.  She has black hair,\n"+
           "and brown eyes.  She looks like she's scared out of her mind.\n");
  set_race("human");
  set_gender("female");
  set_level(17);
  set_wc(20+random(8));
  set_ac(10+random(8));
  set_hp(350);
  set_heal(3,15);
  add_money(100+random(200));
  set_aggressive(0);
  set_dead_ob(this_object());
  set_al(0);
  load_chat("Mary says: Are the ants gone now?.\n");
  load_chat("Mary says: I don't feel good.\n");
  set_chat_chance(15);
  load_a_chat("Mary says: Why are you doing this to me?\n");
  load_a_chat("Mary says: Please stop!!.\n");
  set_a_chat_chance(25);
  set_spell_mess2("Mary scratches you with her nails.\n");
  set_spell_mess1("Mary lashes out with her nails.\n");
  set_chance(15);
  set_spell_dam(20);
}
