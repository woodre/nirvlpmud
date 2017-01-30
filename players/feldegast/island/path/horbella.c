#include "/players/feldegast/closed/ansi.h"
#include "/players/feldegast/closed/shortcut.h"
inherit "/obj/monster";

object eye;
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("horribella");
  set_alias("crone");
  set_short("Horribella the Crone (Definately Not Good)");
  set_long(
"Horibella is an unbelievably ugly old crone.  She is the\n"+
"second of the Three Hags, made out of rusty razor\n"+
"blades, poison rattails, venomous snake fangs, and\n"+
"smelly onion rinds.\n"
  );
  set_gender("female");
  set_race("spirit");
  set_level(7);
  set_wc(11);
  set_ac(6);
  set_hp(105);
  set_al(-150);
  enable_commands();
}

init() {
  add_action("block","east");
  add_action("block","south");
  call_out("script",1);
}
script() {
  if(!eye) {
  say("\nHorribella screeches loudly as she sees you.\n");
  say("Horribella screeches: How did you get past Uggl-Uggl??  No matter.\n");
  say("  You won't get past me!\n");
  say("\nHorribella does a strange, complex dance, and before long a\n"+
      "huge, all-seeing, all-knowing eye appears above the jungle path.\n");
  eye=clone_object("/players/feldegast/island/path/eye");
  move_object(eye,environment(this_object()));
  move_player("south#players/feldegast/island/path/path4");
  }
}
block() {
  write("Horribella says: Don't count on it, ugly!\n");
  return 1;
}
