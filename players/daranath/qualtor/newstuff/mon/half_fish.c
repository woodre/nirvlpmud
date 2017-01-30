#define ROOT "/players/daranath/qualtor/newstuff/"
inherit "/players/daranath/closed/monster1.c";

reset(arg) {
   ::reset(arg);
   if (!arg) {
object ob, ob2;

 ob = clone_object("obj/money");
 ob->set_money(random(200) + 120);
  move_object(ob, this_object());
  ob2 = clone_object(ROOT+"obj/half_leather.c");
  move_object(ob2, this_object());

set_name("Fishing Halfling");
set_short("A halfling is fishing here");
set_alias("fishing");
set_alt_name("citymon");
set_race("halfling");
set_gender("male");
set_long("A young halfling has cast his line into the small amount of nasty water,\n"+
         "probably to waste time more then actually catch anything worth \n"+
         "eating. His dirty leather armor has been well broken in, and he\n"+
         "hasn't had much luck lately.\n");
set_level(8);

init_command("wear armor");

set_ac(7);
set_wc(10 + random(4));
set_hp(100 + random(30));
set_al(0);
set_aggressive(0);

set_chat_chance(15);
load_chat("The halfling tugs a bit on his fishing line.\n");
load_chat("The halfling takes a drink from a wineskin and wipes his brow.\n");
load_chat("The halfling grins and nods at you.\n");
   }
}
