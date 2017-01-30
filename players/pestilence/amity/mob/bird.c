#include "/players/pestilence/ansi.h"
inherit "/players/vertebraker/closed/std/monster";
#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
#define attacker attacker_ob
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name(""+CYN+"Bluejay"+NORM+"");
  set_alt_name("bluejay");
  set_alias("bird");
  set_short(""+CYN+"Bluejay"+NORM+"");
  set_long("This is a small "+CYN+"bluejay"+NORM+".  It has a small yellow beak and\n"+
           "blue feathers.  It is perched on a nearby branch.\n");
  set_race("bird");
  set_gender("female");
  set_level(11);
  set_wc(17);
  set_ac(8);
  set_hp(165);
  set_heal(1,10);
  add_money(0);
  set_aggressive(0);
  set_dead_ob(this_object());
  set_al(0);
  load_chat("A "+CYN+"bluejay"+NORM+" sings away.\n");
  load_chat("The "+CYN+"bluejay"+NORM+" flutters its wings a bit.\n");
  set_chat_chance(15);
  load_a_chat("The "+CYN+"bluejay"+NORM+" squawks.\n");
  set_a_chat_chance(25);
  set_spell_mess2("The "+CYN+"bluejay"+NORM+" tries to peck your eyes out.\n");
  set_spell_mess1("The "+CYN+"bluejay"+NORM+" tries to peck its attackers eyes out.\n");
  set_chance(30);
  set_spell_dam(10+random(5));
}
