#include <ansi.h>
inherit "/players/sparrow/areas/bwo/include/mob_funcs.c";
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("droid");
    set_alias("microdroid");
    set_short(HIW+"M"+NORM+"icro"+HIW+"D"+NORM+"roid");
    set_race( "machine");
    set_long("Standing only three feet tall, this small battledroid should not be underestimated.\n"+
      "Twin plasma cannons are fixed to the shoulders of this wonder of engineering.\n"+
      "The MicroDroid scurries across the floor on two tank tracks, providing mobility\n"+
      "in even the most difficult terrain.  The Black Willow Order first developed these\n"+
      "small battledroids for reconnaissance as well as other delicate procedures.  Weak\n"+
      "by themselves, but these mini monsters have been known to overwhelm even great\n"+
      "foes when concentrated in numbers.\n");
    set_level(12);
    set_ac(9);
    set_wc(0);
    set_hp(120+random(20));
    set_al(0);
    set_aggressive(0);
    set_chat_chance(7);
    set_a_chat_chance(10);
    load_chat("The "+HIW+"M"+NORM+"icro"+HIW+"D"+NORM+"roid pauses a moment to scan you, and scurries away.\n");
    load_chat("The "+HIW+"M"+NORM+"icro"+HIW+"D"+NORM+"roid beeps and hums.\n");
    load_a_chat("The "+HIW+"M"+NORM+"icro"+HIW+"D"+NORM+"roid builds up a static charge!\n");
    load_a_chat("The "+HIW+"M"+NORM+"icro"+HIW+"D"+NORM+"roid releases the charge into you!\n");
    set_weapon_params("other|electric",20,"gut_punch");
  }
}
