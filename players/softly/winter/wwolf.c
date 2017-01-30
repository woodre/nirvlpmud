#include "/players/softly/misc/ansi.h"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (arg) return;
  move_object(clone_object("/players/softly/winter/cameo.c"),this_object());  

  set_name("White Wolf");
  set_alt_name("white wolf");   
  set_alias("wolf");
  set_long("A startlingly large"+BOLD+" white wolf"+NORM+" with bright clear eyes\n"+
           "and a healthy coat.  A glint of something is visible at her\n"+
           "throat.  She stares intently as if waiting for you to move.\n");
  set_short("A"+BOLD+" white wolf"+NORM);
  set_type("wolf");
  set_level(20);
  set_wc(30);
  set_ac(17);
  set_hp(500);
  set_al(200);
  set_aggressive(0);
  set_chance(30);
  set_spell_dam(15);
  set_spell_mess1("The wolf growls deeply and suddenly lunges!.\n");
  set_spell_mess2("Suddenly the wolf growls and dives at your throat!\n");


}
init() {
add_action("block_exit", "enter");
}
block_exit(){
  if(this_player()->query_level() < 20){
    attack_object(this_player());
    write("The wolf snarls and attacks as you try to enter the cottage.\n");
  return 1;
  }
return;
}
