#include <ansi.h>
#define ROOT "/players/daranath/wastes/"

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object ob, ob2, ob3;
 ob = clone_object("obj/money");
  ob->set_money(random(25) + 10);
  move_object(ob, this_object());
 ob2 = clone_object(ROOT +"obj/coal_amulet.c");
  move_object(ob2, this_object());
 ob3 = clone_object(ROOT +"wep/heat_spear.c");
  move_object(ob3, this_object());

set_name("Salamander Warrior");
set_alias("lavamon");
set_alt_name("warrior");
set_race("salamander");
set_gender("creature");

set_short(RED+"Salamander warrior"+NORM);
set_long("Dark red scales cover the body of the Salamader race, and their\n"+
         "warriors are no exception. The scales provide a measure of\n"+
         "protection, while the Salamander weaponsmiths craft exceptional\n"+
         "weapons to bring to the battlefield.\n");

set_level(12);
set_ac(9);
set_wc(11 + random(4));
set_hp(160 + random(60));
set_al(-1200);
set_aggressive(0);

init_command("wield spear");
init_command("wear coal");

   }
}
