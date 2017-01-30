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

set_name("Flame Creeper");
set_alias("lavamon");
set_alt_name("creeper");
set_race("elemental");
set_gender("creature");

set_short("A "+HIR+"Flame Creeper"+NORM);
set_long("The flame creeper is a small creature born of the Elemental plane of\n"+
         "Fire. So, its no surprise that they settled here, within the Gundar\n"+
         "Lava Pits. Its body is completly shrouded in flames, making the creeper\n"+
         "a living weapon.\n");

set_level(11);
set_ac(9);
set_wc(10 + random(4));
set_hp(140 + random(45));
set_al(-1000);
set_aggressive(0);

   }
}
