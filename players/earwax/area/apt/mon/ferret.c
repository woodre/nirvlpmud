inherit "/obj/monster.c";
inherit "/players/earwax/area/apt/mon/color.c";
#include <ansi.h>
#define tpn this_player()->query_name()

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("ferret");
  set_race("creature");
  set_short(color_name("Ferret")+" of DOOM");
  set_long(
    "  A large mutated ogre of a ferret. Its claws are\n"+
    "as sharp as razors and blood drips from its enormous\n"+
    "fangs. It stands poised waiting and watching you.\n");
  
  add_money(4000+random(2000));
  set_level(20);
  set_hp(500+random(100));
  set_al(-800);
  set_ac(21+random(4));
  set_wc(32);
  set_aggressive(0);
  set_chance(20);
  set_spell_dam(25);
  set_spell_mess1(
    "The ferret "+BOLD+" L A S H E S"+NORM+" out at "+tpn+" you with it's huge paws!\n");
  set_spell_mess2(
    "\nYou stumble back from the blow. "+HIB+" PAIN"+NORM+" shoots through your body!\n");
}
