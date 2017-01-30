#include "/players/cosmo/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

  set_name(HIY+"Gene"+NORM);
  set_alias("gene");
  set_alt_name("gene");
  set_race("human");
  set_short("Gene");
  set_long(
  "  Gene is the anti-George in bizarro world. He likes\n"+
  "to go to the library to read. He eats at Reggie's\n"+
  "diner instead of Monk's. He gives money to those that are\n"+
  "less fortunate. He reported a pay phone that was giving out\n"+
  "free long distance calls. And he was happy about receiving\n"+
  "tickets to the ballet!\n");

  set_level(15);
  set_hp(225+random(50));
  set_al(0);
  set_wc(20);
  set_ac(12);
  set_heal(3,20);
  set_aggressive(0);
  set_dead_ob(this_object());
  set_a_chat_chance(15);
  load_a_chat("Gene tells you: Be careful when using that dust.\n");

  add_money(350+random(50));
}

monster_died() {
object friend;
object bizdust;
  friend = present("kevin", environment());
  bizdust = present("pouch", this_object());
  if(friend && bizdust) {
    move_object(bizdust, friend);
    tell_room(environment(),
    "Gene tosses the dust to "+friend->query_name()+" as he dies.\n");
  }
  return 0;
}
