#include "/players/pestilence/ansi.h"
inherit "/obj/monster.c";
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Blue"); 
  set_alias("blue");
  set_short(""+CYN+"Blue"+NORM+"");
  set_long("This is Blue, she is a small light blue dog with dark blue spots and\n"+
           "big floppy ears.  Blue is part hound and part beagle.\n");
set_race("dog");
  set_gender("female");
  set_level(4);
  set_wc(8);
  set_ac(5);
  set_hp(60);
  set_ep(1000);
  add_money(0);
  set_aggressive(0);
set_dead_ob(this_object());
  set_al(200);
  load_chat("Rwooof rwoof woof woof rwooof.\n");
  set_chat_chance(20);
}
monster_died() {
  move_object(clone_object("/players/pestilence/blue/obj/bcollar.c"),
      environment(this_object()));
  tell_room(environment(this_object()),
        "As Blue dies, she removes her collar.\n");
return 0; }
