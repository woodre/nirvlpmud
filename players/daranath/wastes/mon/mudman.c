#include <ansi.h>
#define ROOT "/players/daranath/wastes/"

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object ob;
 ob = clone_object("obj/money");
  ob->set_money(random(25) + 10);
  move_object(ob, this_object());

set_name("Mudman");
set_alias("mudman");
set_alt_name("cavemon");
set_race("mudman");
set_gender("male");

set_short("A "+YEL+"mudman"+NORM);
set_long("Its body made completly of soft mud, the Mudman seems to be almost\n"+
         "helpless while defending itself. The mud protects him, however, and\n"+
         "its short arms pack a powerful punch.\n");

set_level(10);
set_ac(8);
set_wc(12 + random(4));
set_hp(140 + random(40));
set_al(-800);
set_aggressive(0);

set_a_chat_chance(10);
load_a_chat("Mudman slams you with its powerful arms.\n");
load_a_chat("Mudman throws some mud at you, causing you to gasp for air.\n");

   }
}
