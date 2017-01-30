/* Increased WC and AC of Dralgos   Jun-07-2002   -Dar  */

#define ROOT "/players/daranath/closed/market/"
#include <ansi.h>
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
object ob, ob2, ob3;
     ob = clone_object("obj/money");
     ob->set_money(random(100) + 50);
     move_object(ob, this_object());
 ob3 = clone_object(ROOT+"obj/dral_armor.c");
  move_object(ob3, this_object());
 ob2 = clone_object(ROOT+"obj/bone_axe.c");
  move_object(ob2, this_object());

set_name("Dralgos the Necromancer");
set_short("Dralgos, the Dwarven Necromancer");
set_alias("dralgos");
set_alt_name("necro");
set_race("dwarf");
set_gender("male");
set_long("His face covered in scars and new wounds recently stiched up, Dralgos\n"+
         "has taken his place here with Xion, helping run the Bone Market.\n"+
         "His diminutive form wrapped in bloody leather armor, he certainly\n"+
         "does not look like anyone you want to get in a fight with.\n"+
         "You may <"+HIR+"ask"+NORM+"> Dralgos about his place in the\n"+
         "Bone Marketeers, but be nice about it.\n");
set_level(20);

init_command("wear armor");
init_command("wield weapon");

set_ac(21);
set_wc(32 + random(15));
set_hp(600 + random(200));
set_al(-420);
set_aggressive(0);
set_dead_ob(this_object());
set_chat_chance(2);
set_a_chat_chance(10);
load_chat("Dralgos nods as you browse through his shop.\n");
load_chat("Dralgos watches over everything here.\n");

   }
}

monster_died() {
write_file("/players/daranath/closed/log/drag_death",ctime(time())+"\t"+
  (this_object()->query_attack())->query_real_name()+"\t\t"+
  (this_object()->query_attack())->query_level()+"\n");
return 0;
}

