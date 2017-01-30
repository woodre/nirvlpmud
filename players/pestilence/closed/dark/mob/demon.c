#include "/players/pestilence/ansi.h"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

  set_name(""+HIK+"demon"+NORM+"");
  set_alt_name("demon");
  set_alias("dark demon");
  set_short(""+HIK+"Dark Demon"+NORM+"");
  set_long(
"This is a demon, called from the depths of the unknown, to\n"+
"help its master in battle.  It barely holds a solid form,\n"+
"but it seems to have a good tendency to hit hard.\n");
  set_race("demon");
  set_gender("creature");
  set_level(1);
  set_ac(2);
  set_wc(14+random(3));
  set_hp(10);
  set_chance(35);
  set_spell_dam(10+random(4));
  set_spell_mess1("A demon lashes out at its foe.\n");
  set_spell_mess2("A demon lashes out at you!\n");
  call_out("dest", 6+random(11));
} }

dest()
{
  if(environment())
  {
        tell_room(environment(),
                "A demon goes back from hence it came...\n");
    destruct(this_object());
  }
}
