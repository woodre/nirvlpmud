inherit "obj/monster.talk";
int i;
object coins, sword, armor;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("guard");
set_short("A Castle Guard");
set_long("This is a rather large brut that is employed to guard the castle.\n");
set_al(400);
set_level(12);
set_wc(15);
set_hp(180);
set_ac(7);
set_aggressive(0);

coins = clone_object("obj/money");
coins->set_money(10+(random(20)));
move_object(coins,this_object());
i = random(10);
if (i<7) {
sword = clone_object("players/grimm/weapons/guard_sword");
move_object(sword,this_object());
}
i = random(10);
if (i<4) {
armor = clone_object("players/grimm/armor/guard_armor");
move_object(armor,this_object());
}
}
