/* Increased HP, WC and AC of Xion   Jun-07-2002   -Dar  */

#define ROOT "/players/daranath/closed/market/"
#include <ansi.h>
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
object ob, ob2, ob3;
  ob = clone_object("obj/money");
  ob->set_money(random(2500) + 750);
  move_object(ob, this_object());
 ob3 = clone_object(ROOT+"obj/xion_robes.c");
  move_object(ob3, this_object());
 ob2 = clone_object(ROOT+"obj/bone_staff.c");
  move_object(ob2, this_object());

set_name("Xion the Scholar");
set_short("Xion, the Scholar");
set_alias("xion");
set_alt_name("scholar");
set_race("human");
set_gender("male");
set_long("A tall and very gaunt individual, xion has been running\n"+
         "the Bone Market since it opened almost five years ago. The \n"+
         "stress has taken its toll, leaving him wth large amounts\n"+
         "of white hair and a very haggard appearance.\n"+
         "Xion can help you <"+HIR+"join"+NORM+"> the Bone Marketeers.\n"+
         "You can also <"+HIR+"ask"+NORM+"> him for information about the group.\n");
set_level(19);

init_command("wear armor");
init_command("wield weapon");

set_ac(22);
set_wc(28 + random(12));
set_hp(580 + random(100));
set_al(-420);
set_aggressive(0);
set_dead_ob(this_object());
set_chat_chance(2);
set_a_chat_chance(10);
load_chat("Xion changes his grip on the Bone QuarterStaff.\n");
load_chat("Xion wanders about the Bone Marketplace.\n");
load_chat("Xion walks over and checks a corpse on another table.\n");
load_chat("Xion examines a corpse upon one of the long tables.\n");
load_chat("Xion nods, and a couple of monks take another corpse away.\n");
load_a_chat("The child of thought hits you with a mental strike.\n");

   }
}

monster_died() {
write_file("/players/daranath/closed/log/xion_death",ctime(time())+"\t"+
  (this_object()->query_attack())->query_real_name()+"\t\t"+
  (this_object()->query_attack())->query_level()+"\n");
return 0;
}

