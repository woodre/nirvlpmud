/*
This is a fairly typical weapon with emotes only for dwarves, and
based off of the strength attribute.
				-Feldegast
*/

#include "/players/feldegast/defines.h"

inherit "obj/weapon.c";

reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("hammer");
  set_alias("warhammer");
  set_short("Dwarven Warhammer");
  set_long(
"This is an ancient warhammer, enchanted by dwarven blacksmiths\n"+
"and wielded by great heroes of dwarvenkind.  The warhammer is\n"+
"carefully weighted to allow maximum accuracy if thrown.\n"
  );
  set_type("club");
  set_class(18);
  set_weight(7);
  set_value(5000);
  set_hit_func(this_object());
}

weapon_hit(attacker) {
  int H;
  if(environment()->query_race()=="dwarf") {
    H=random(environment()->query_attrib("str"));
    if(H==20) {
      write(
"\nYou "+BOLD+"SMITE"+NORM+" your foe with the might of ancient dwarves.\n\n"
      );
      say(
TPN+" smites "+TP->query_possessive()+" foe with the might of ancient dwarves.\n\n"
      );
      return 10;
       }
    if(H>17) {
      write(
"\nYou throw the ancient warhammer with all of your might, crushing\n"+
"your foe with the impact, then catching it as it returns.\n"
       );
      say(
"\n"+TPN+" throws "+TP->query_possessive()+" ancient warhammer with all of "+
TP->query_possessive()+" might, crushing\n"+
TP->query_possessive()+" foe with the impact, then retrieves it as\n"+
"it flies through the air.\n"
         );
      return 5;
    }
  }
  return 0;
}
