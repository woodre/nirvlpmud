#include "/players/feldegast/closed/ansi.h"
#include "/players/feldegast/closed/shortcut.h"
inherit "/obj/monster";

object vine;
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("uggl");
  set_short("Uggl-Uggl the Hag (Not Very Nice)");
  set_long(
"Uggl-Uggl is an unbelievably ugly old hag.  She is the\n"+
"first of the Three Hags Full, made out of rusty razor\n"+
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
  add_action("block","south");
  add_action("block","east");
  call_out("script",1);
}
script() {
  if(!vine) {
  say("\nUggl-Uggl looks surprised to see you here.\n");
  say("Uggl-Uggl says: Oh my! An adventurer!  I guess I'm supposed to\n"+
      "stop you.  I'm sorry, but you brought this on yourself.\n");
  say("Uggl-Uggl makes a few strange gestures and a "+GRN+"tangle vine"+NORM+" springs\n"+
      "up in the middle of the path.\n");
  vine=clone_object("/players/feldegast/island/path/vine");
  move_object(vine,environment(this_object()));
  move_player("east#players/feldegast/island/path/path2");
  }
}
block() {
  write("Uggl-Uggl says: I'm afraid I can't let you go any further.\n");
  return 1;
}
