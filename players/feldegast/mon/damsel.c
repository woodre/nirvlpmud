#include "defs.h"

inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("crysten");
  set_alt_name("damsel");
  set_short("A damsel in distress");
  set_long(
"Crysten is a young woman with cornsilk hair and deep blue\n"+
"eyes.  She wears a cotton dress with flowers on it.  She is\n"+
"chained to the wall.  You will need a key to release her.\n"
  );
  set_gender("female");
  set_race("human");
  set_level(6);
  set_wc(10);
  set_ac(5);
  set_hp(90);
  set_al(1000);
  set_chat_chance(5);
  load_chat("Damsel screams for help!\n");
  load_chat("Damsel says: Please release me!\n");
}

run_away() {
  say(name+" rattles her chains.\n");
}

void init() {
  ::init();
  add_action("cmd_rescue","release");
}

cmd_rescue(str) {
  object chest;
  if(!id(str)) {
    notify_fail("Release who?\n");
    return 0;
  }
  if(!present("key#2020202",TP)) {
    write("You do not have a key for the manacles.\n");
    notify_fail("");
    return 0;
  }
  write("Crysten gives you a big hug as you unchain her.\n"+
        "\nCrysten says: Thank you for freeing me!  I'm sure if you come to\n"+
        "  the house of my father, Abdullah Sakadi, he will glady reward you\n"+
        "  for your valiant deeds!\n\n"+
        "Crysten leaves southwest.\n");
  
  this_player()->add_alignment(1000);
  chest=present("chest",environment(TP));
  if(!chest) chest=present("chest",TP);
  if(chest) {
    chest->set_damsel(1);
  }
  destruct(this_object());
  return 1;
}


