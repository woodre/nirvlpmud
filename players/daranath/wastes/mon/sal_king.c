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
 ob2 = clone_object(ROOT +"obj/coal_crown.c");
  move_object(ob2, this_object());
 ob4 = clone_object(ROOT +"obj/sil_cloak.c");
  move_object(ob4, this_object());
 ob3 = clone_object(ROOT +"wep/trident.c");
  move_object(ob3, this_object());

set_name("Salamander King");
set_alias("lavamon");
set_alt_name("king");
set_race("salamander");
set_gender("male");

set_short(RED+"Salamander "+HIW+"King"+NORM);
set_long("The largest and more powerful of all the Salamanders, the King stands over\n"+
         "eight feet tall. In addition to the crown on his head, he carries a\n"+
         "wicked looking trident and wears a silver cloak.\n");

set_level(20);
set_ac(15);
set_wc(30 + random(7));
set_hp(500 + random(30));
set_al(-1200);
set_aggressive(0);

init_command("wield trident");
init_command("wear crown");
init_command("wear cloak");

set_chance(15);
set_spell_dam(35);
set_spell_mess1("Salamander King hits you very hard.\n");
set_spell_mess2("Salamander King hits you very hard.\n");

   }
}
