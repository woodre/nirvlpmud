inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "judd nelson" ||  str == "judd" || str == "nelson" || str == "actor" || str == "Judd Nelson"; }
reset(arg)
{
   ::reset(arg);
    if (arg) return;
set_name("Judd Nelson");
    set_race("human");
set_gender("male");
    set_al(30+random(10));
    set_level(13);
    set_hp(200);
    set_wc(18);
    set_ac(9);
    set_short(HIW+"Judd Nelson"+NORM);
    set_long(
      "Judd Nelson is an average sized guy with dark hair, and a dorky\n"+
      "looking face.  This brat pack actor stared in movies such as\n"+
      "'St. Elmo's Fire' and 'The Breakfast Club'.  He was probably\n"+
      "the least popular brat pack actor.\n");
MOCO("/players/jenny/80s/items/cooler.c"),this_object());
  gold=clone_object("obj/money");
  gold->set_money(90+random(20));
  move_object(gold,this_object());
}
