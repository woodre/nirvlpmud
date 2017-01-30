inherit "obj/monster";
int i;
object coins, sword, armor;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("guard");
set_short("A mall guard");
set_long("This is a rather sleepy mall rent-a-cop.\nHe's here for your protection! *snicker*\n");
set_al(400);
set_level(12);
set_wc(15);
set_hp(180);
set_ac(7);
set_aggressive(0);
set_chat_chance(50);
load_chat("Guard snores loudly.\n");
load_chat("Guard says: move along.  No loitering.\n");
load_chat("Guard says: You don't want me to get rough now do you?\n");
load_chat("The mall guard falls alseep.\n");
set_a_chat_chance(70);
load_a_chat("Guard shouts: HELP! Security!\n");
load_a_chat("Guard blows his whistle.\n");
load_a_chat("Guard shouts: Stop! Stop! I quit! I quit!\n");

coins = clone_object("obj/money");
coins->set_money(10+(random(20)));
move_object(coins,this_object());
i = random(10);
if (i<7) {
sword = clone_object("players/grimm/closed/mall/guard_sword");
move_object(sword,this_object());
}
i = random(10);
if (i<4) {
armor = clone_object("players/grimm/closed/mall/guard_armor");
move_object(armor,this_object());
}
}
