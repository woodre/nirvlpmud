#define ETO environment(this_object())
inherit "/obj/monster.c";
object gold;

reset(arg) {
::reset(arg);
if(arg) return;
set_a_chat_chance(35);
set_chat_chance(40);
load_chat("Dragon says:  So are you a wimp are a man?\n");
load_chat("Dragon says:  If you want to die attack me.\n");
load_chat("Dragon says:  I have fought many warriors like you.\n");
load_chat("Dragon says:  Your not about to get my goods.\n");
load_chat("Dragon says:  You will die if you attack me.\n");
load_a_chat("Dragon yells:  Die you little shit!\n");
set_name("dragon");
set_alias("deep");
set_short("Deep Dragon");
set_long(
"This is a nice sized dragon.  It is black in color and has yellow eyes.\n"
+ "It's tail swings behind it ready to strike when your not ready for it.\n"
+ "It's 87 feet tall with a tail that is abou 73 feet long.  It's hiding\n"
+ "alot of goodies behind it.  You can't see exactually what it is but\n"
+ "it looks pretty good.\n");
set_level(20);
set_al(-400);
set_race("dragon");
set_hp(500);
set_wc(40);
set_ac(23);
set_dead_ob(this_object());

gold = clone_object("obj/money");
gold->set_money(4000 + random(2000));
move_object(gold,this_object());
}
monster_died(ob) {
  move_object(clone_object("players/mouzar/castle/under/obj/ddshield"),ETO);
}
