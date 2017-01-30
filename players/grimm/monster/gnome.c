inherit "obj/monster.talk";
int i;
object coins, sword;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("gnome");
set_short("A smelly little gnome");
set_long("This is a putrid little fellow.  He stands about 3 foot tall and looks to\nbe in a bad mood.\n");
set_al(-100);
set_level(14);
set_wc(14);
set_hp(200);
set_ac(6);
set_aggressive(0);

coins = clone_object("obj/money");
coins->set_money(10+(random(20)));
move_object(coins,this_object());
i = random(10);
if (i<6) {
sword = clone_object("players/grimm/weapons/gnome_sword");
move_object(sword,this_object());
}
}
