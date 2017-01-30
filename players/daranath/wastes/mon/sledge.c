#include <ansi.h>
#define ROOT "/players/daranath/wastes/"

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object ob;
 ob = clone_object("obj/money");
  ob->set_money(random(300) + 300);
/*average coins of 450, less then monster guide */
  move_object(ob, this_object());

set_name("Sledge");
set_alias("sledge");
set_alt_name("cavemon");
set_race("sledge");
set_gender("male");

set_short("A "+WHT+"sledge"+NORM);
set_long("The sledge rears itself before you. Its body is made of a flexible rocky\n"+
         "carapace that allows it to move easily, while offering excellent\n"+
         "protection. The arms of the sledge end in large, blunt fists, each in\n"+
         "the shape of a hammer, giving the creature its name.\n");

set_level(11);
set_ac(10);
set_wc(13 + random(5));
set_hp(150 + random(50));
set_al(-850);
set_aggressive(0);

set_a_chat_chance(10);
load_a_chat("Sledge hammers at you with its massive arms.\n");
load_a_chat("Sledge drives its hammers into your body.\n");

   }
}
