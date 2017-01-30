#include "/players/cosmo/closed/ansi.h"
inherit "obj/monster.c";

object bizdust;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

  set_name(HIY+"Feldman"+NORM);
  set_alias("feldman");
  set_alt_name("feldman");
  set_race("human");
  set_short("Feldman");
  set_long(
  "  Feldman is the anti-Kramer in bizarro world. He has\n"+
  "great ideas but never acts on them. He rings the doorbell\n"+
  "and waits to be acknowledged before entering a room. He\n"+
  "buys his own groceries, instead of eating those of his\n"+
  "neighbor. Feldman is just an all-around nice, generous, and\n"+
  "normal guy - quite the opposite of Kramer.\n");

  set_level(15);
  set_hp(225+random(50));
  set_al(0);
  set_wc(20);
  set_ac(12);
  set_heal(3,20);
  set_aggressive(0);
  set_dead_ob(this_object());
  set_a_chat_chance(15);
  load_a_chat("Feldman exclaims: You'll never get the dust!\n");

  add_money(350+random(50));

  bizdust = clone_object("players/cosmo/apt/obj/bizarro");
  move_object(bizdust,this_object());
}

monster_died() {
object friend;
  friend = present("kevin", environment());
  if(!friend) friend = present("gene", environment());
  if(friend) {
    move_object(bizdust, friend);
    tell_room(environment(),
    "Feldman tosses the dust to "+friend->query_name()+" as he dies.\n");
  }
  return 0;
}
