#include "/players/cosmo/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

  set_name(HIY+"Kevin"+NORM);
  set_alias("kevin");
  set_alt_name("kevin");
  set_race("human");
  set_short("Kevin");
  set_long(
  "  Kevin is the anti-Jerry in bizarro world. He likes\n"+
  "the idea of just being friends with Elaine when she breaks\n"+
  "up with him. His apartment has a unicycle hanging on the\n"+
  "wall. In fact, all of his furniture is exactly the opposite\n"+
  "of Jerry's. He also has jars of pasta on his kitchen shelf,\n"+
  "instead of cereal boxes. Kevin likes to tell his friends that\n"+
  "he loves them.\n");

  set_level(15);
  set_hp(225+random(50));
  set_al(0);
  set_wc(20);
  set_ac(12);
  set_heal(3,20);
  set_aggressive(0);
  set_dead_ob(this_object());
  set_a_chat_chance(15);
  load_a_chat("Kevin exclaims: Hey, that hurts!\n");

  add_money(350+random(50));
}

monster_died() {
object friend;
object bizdust;
  friend = present("gene", environment());
  bizdust = present("pouch", this_object());
  if(friend && bizdust) {
    move_object(bizdust, friend);
    tell_room(environment(),
    "Kevin tosses the dust to "+friend->query_name()+" as he dies.\n");
  }
  return 0;
}
