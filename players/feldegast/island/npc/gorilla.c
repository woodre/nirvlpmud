#include "/players/feldegast/closed/ansi.h"
#include "/players/feldegast/closed/shortcut.h"
inherit "/obj/monster";
reset(arg) {
  object banana;
  ::reset(arg);
  if(!present("banana")) {
    banana=clone_object("/players/feldegast/island/npc/banana");
    move_object(banana,this_object());
  }
  if(arg) return;
  set_name("gorilla");
  set_alt_name("ape");
  set_alias();
  set_short(BOLD+"A gorilla"+NORM);
  set_long(
"A fierce looking ape with a shiny black face and\n"+
"pointed teeth.\n"
);
  set_gender("male");
  set_race("ape");
  set_level(4);
  set_wc(8);
  set_ac(4);
  set_hp(60);
  set_al(0);
  set_chat_chance(2);
  load_chat("The gorilla grunts at you.\n");
  load_chat("The gorilla beats his chest.\n");
}

