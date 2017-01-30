#include "/players/pestilence/ansi.h"
inherit "/obj/monster.c";
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("magenta"); 
  set_alias("magenta");
  set_short(""+MAG+"Magenta"+NORM+"");
  set_long("Magenta is a dog similiar to Blue, but obviously Magenta is\n"+
           "a mix of hound and beagle, being magenta colored, with dark purple\n"+
            "spots and floppy ears.\n");
  set_race("dog");
  set_gender("male");
  set_level(8);
  set_wc(12);
  set_ac(7);
  set_hp(120);
  set_ep(1000);
  add_money(0);
  set_aggressive(0);
  set_al(200);
  move_object(clone_object("/players/pestilence/blue/obj/mcollar.c"),
        this_object()); }
