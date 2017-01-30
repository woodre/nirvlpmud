#define ROOT "/players/daranath/qualtor/newstuff/"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
object ob, ob2;

 ob = clone_object("obj/money");
 ob->set_money(random(200) + 120);
  move_object(ob, this_object());
  ob2 = clone_object(ROOT+"obj/half_leather.c");
  move_object(ob2, this_object());

set_name("Scared Halfling");
set_short("A rather scared halfling");
set_alias("scared");
set_alt_name("citymon");
set_race("halfling");
set_gender("male");
set_long("A rather young looking halfling, he came here with the others\n"+
         "to help rebuild the city. He seems to have wandered off into the\n"+
         "dangerous Arena Ward. Not a good place to be.\n");
set_level(8);

init_command("wear armor");

set_ac(7);
set_wc(10 + random(4));
set_hp(100 + random(30));
set_al(0);
set_aggressive(0);

set_chat_chance(15);
load_chat("The halfling shakes in fear.\n");
load_chat("The halfling says: 'Whatever you do, don't go north!\n");
load_chat("The halfling says: 'Whatever you do, don't go north!\n");
load_chat("The halfling looks north and shakes in fear.\n");
load_chat("The halfling says: 'Gerald went north, and never came back...\n");
   }
}
