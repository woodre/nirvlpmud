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
 ob2 = clone_object(ROOT +"obj/bl_chain.c");
  move_object(ob2, this_object());
 ob3 = clone_object(ROOT +"wep/bl_sword2.c");
  move_object(ob3, this_object());

set_name("Faerl Warrior");
set_alias("platmon");
set_alt_name("warrior");
set_race("faerl");
set_gender("male");

set_short(WHT+"Faerl"+WHT+" warrior"+NORM);
set_long("A small goblin stands before you, trying to look brave as it holds\n"+
         "a dirty short sword in your direction. As you examine the goblin you\n"+
         "notice the sword seems to be shaking slightly.\n");

set_level(11);
set_ac(9);
set_wc(13 + random(4));
set_hp(140 + random(50));
set_al(-1000);
set_aggressive(0);

init_command("wield sword");
init_command("wear chain");
   }
}
