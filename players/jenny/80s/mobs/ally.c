inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "ally sheedy" ||  str == "ally" || str == "sheedy" || str == "actress" || str=="Ally Sheedy"; }
reset(arg)
{
   ::reset(arg);
    if (arg) return;
set_name("Ally Sheedy");
    set_race("human");
set_gender("female");
    set_al(50+random(20));
    set_level(12);
    set_hp(175+random(10));
    set_wc(16);
    set_ac(8+random(3));
    set_short(WHT+"Ally Sheedy"+NORM);
    set_long(
      "Ally Sheedy is a cute, but not beautiful, dark haired woman.  She\n"+
      "was a member of the 80's Brat Pack, and in popular movies such\n"+
      "as 'St. Elmo's Fire', and 'The Breakfast Club'.\n");
MOCO("/players/jenny/80s/items/juice.c"),this_object());
}
