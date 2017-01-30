#include <ansi.h>
#define ROOT "/players/daranath/wastes/"

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object ob, ob2;
 ob = clone_object("obj/money");
  ob->set_money(random(25) + 10);
  move_object(ob, this_object());
 ob2 = clone_object(ROOT +"obj/legs.c");
  move_object(ob2, this_object());

set_name("Croaker");
set_alias("croaker");
set_alt_name("frog");
set_race("amphibian");
set_gender("creature");

set_short("A giant "+HIG+"croaker"+NORM);
set_long("Oversized frogs are a disturbing result of the magical wars that\n"+
         "devestated the Gundar Wastes. The Croaker is approxiamatly 4 feet in\n"+
         "length and weighs over 100 lbs. Big frog.\n");

set_level(8);
set_ac(7);
set_wc(11 + random(4));
set_hp(100 + random(40));
set_al(250);
set_aggressive(0);

   }
}
