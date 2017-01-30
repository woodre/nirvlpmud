#include <ansi.h>
#define ROOT "/players/daranath/wastes/"

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object ob, ob2, ob3, ob4;
 ob = clone_object("obj/money");
  ob->set_money(random(25) + 10);
  move_object(ob, this_object());
 ob2 = clone_object(ROOT +"obj/coal_amulet.c");
  move_object(ob2, this_object());
 ob3 = clone_object(ROOT +"wep/heat_sword.c");
  move_object(ob3, this_object());
 ob4 = clone_object(ROOT +"obj/rag_cloak.c");
  move_object(ob4, this_object());

set_name("Salamander Assassin");
set_alias("lavamon");
set_alt_name("assassin");
set_race("salamander");
set_gender("creature");

set_short(RED+"Salamander "+BLK+BOLD+"assassin"+NORM);
set_long("The dark red scales of the Salamander show through the gaps of the\n"+
         "large black cloak that he has wrapped his body in. He keeps trying to\n"+
         "sneak and hide about the area, looking for a place to ambush from.\n");

set_level(14);
set_ac(10);
set_wc(17 + random(6));
set_hp(190 + random(60));
set_al(-1200);
set_aggressive(0);

init_command("wield sword");
init_command("wear cloak");
init_command("wear coal");

   }
}
