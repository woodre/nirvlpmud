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

set_name("Choaker Vine");
set_alias("lavamon");
set_alt_name("choaker");
set_race("vine");
set_gender("creature");

set_short("A "+BLK+BOLD+"choaker Vine"+NORM);
set_long("A choaker Vine loves to live in extremly hot areas, such as the Gundar\n"+
         "Lava Pits. Its thick, black hide protects it from the heat, while a\n"+
         "series of thorns down its length make an excellent weapon.\n");

set_level(9);
set_ac(7);
set_wc(6 + random(4));
set_hp(120 + random(45));
set_al(0);
set_aggressive(0);

   }
}
