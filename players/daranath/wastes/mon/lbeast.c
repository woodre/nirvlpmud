#include <ansi.h>
#define ROOT "/players/daranath/wastes/"

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object ob;
 ob = clone_object("obj/money");
  ob->set_money(random(400) + 300);
/* Random coins average out to 500 per monster guide */
  move_object(ob, this_object());

set_name("Lava Beast");
set_alias("lavamon");
set_alt_name("beast");
set_race("hound");
set_gender("creature");

set_short("A "+HIR+"lava beast"+NORM);
set_long("Standing upon the lava without giving it another thought, the Lava Beast\n"+
         "looks like a flaming hound straight from the bowels of hell itself.\n"+
         "Red hot flames surround its body, while its two eyes burn like\n"+
         "the surface of the sun.\n");

set_level(11);
set_ac(9);
set_wc(10 + random(4));
set_hp(140 + random(45));
set_al(-1000);
set_aggressive(0);

   }
}
