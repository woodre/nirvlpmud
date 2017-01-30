inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "andrew mccarthy" ||  str == "andrew" || str == "mccarthy" || str == "actor" || str == "Andrew McCarthy"; } 
reset(arg)
{
   ::reset(arg);
    if (arg) return;
set_name("Andrew McCarthy");
    set_race("human");
set_gender("male");
    set_al(45+random(20));
    set_level(13);
    set_hp(200);
    set_wc(16+random(2));
    set_ac(10);
    set_short(HIB+"Andrew McCarthy"+NORM);
    set_long(
      "Andrew McCarthy is a thin young man with light brown hair.\n"+
      "This brat pack actor stared in the movies 'Class', 'Heaven Help\n"+
      "Us', 'St. Elmo's Fire', 'Pretty in Pink', and 'Weekend at Bernie's'.\n");
MOCO("/players/jenny/80s/items/cooler.c"),this_object());
  gold=clone_object("obj/money");
  gold->set_money(90+random(20));
  move_object(gold,this_object());
}
