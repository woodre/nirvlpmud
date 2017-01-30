inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "emilio estevez" ||  str == "emilio" || str == "estevez" || str == "actor" || str == "Emilio Estevez"; } 
reset(arg)
{
   ::reset(arg);
    if (arg) return;
set_name("Emilio Estevez");
    set_race("human");
set_gender("male");
    set_al(40+random(15));
    set_level(14);
    set_hp(200+random(20));
    set_wc(19);
    set_ac(10+random(2));
    set_short(HIY+"Emilio Estevez"+NORM);
    set_long(
      "Emilio is an average sized guy, with short light colored hair.  He comes\n"+
      "from a fine acting family.  His father is Martin Sheen, and his brother\n"+
      "is Charlie Sheen.  Emilio was in several good movies during the 80's,\n"+
     "including 'St. Elmo's Fire', 'The Breakfast Club', 'The Outsiders',\n"+
     "and 'Repo Man'.\n");
MOCO("/players/jenny/80s/items/coke.c"),this_object());
}
