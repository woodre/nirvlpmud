inherit "obj/monster";
#include "/players/illarion/dfns.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("Goon #2");
  set_race("human");
  set_gender("male");
  set_short("A short, bony goon");
  set_long(
"A relatively short, stupid-looking man who likes to think of\n"+
"himself as 'tough'.  This allows to him exude enough confidence to intimidate\n"+
"others.  He wears jeans and a pizza-stained shirt that looks vaguely\n"+
"military.\n");
  set_level(14);
  set_al(-200);
  set_hp(175+random(50));
  add_money(650);
  set_wc(19);
  set_ac(11);
  set_chat_chance(7);
  load_chat("The small goon scratches himself.\n");
  load_chat("You catch a very undesired whiff of stale pizza...\n");
  set_a_chat_chance(7);
  load_a_chat("The small goon tries to knee you in the crotch.\n");
  load_a_chat("The small goon's elbow bumps you painfully.\n");
}
id(str) { return ::id(str) || str == "goon" || str == "neandrithal"; }
