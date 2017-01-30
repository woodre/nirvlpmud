#include <ansi.h>
#define ROOT "/players/daranath/wastes/"

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object ob;
 ob = clone_object("obj/money");
  ob->set_money(random(400) + 250);
/* average coins of 450 per monster guide */
  move_object(ob, this_object());

set_name("A flying Maw");
set_alias("cavemon");
set_alt_name("Maw");
set_race("maw");
set_gender("creature");

set_short("A flying "+RED+"maw"+NORM);
set_long("A small leathery, flying creature, the maw seems to be little more then\n"+
         "a mouth full of snapping teeth.\n");

set_level(10);
set_ac(3);
set_wc(18 + random(4));
/* AC of Maw is poor (5 below GUIDE), but WC is increased (up to 7 more then
   GUIDE), reflecting that the maw is little more then a flying set of teeth */
set_hp(120 + random(50));
set_al(-1000);
set_aggressive(1);

set_a_chat_chance(40);
load_a_chat("Maw tears at your body with its teeth.\n");
load_a_chat("Maw rips at your body with its teeth.\n");
load_a_chat("Maw howls with an unworldly sound.\n");
load_a_chat("Maw growls and continues its attack.\n");
load_a_chat("Maw bites into you, ripping flesh and bone.\n");

   }
}
