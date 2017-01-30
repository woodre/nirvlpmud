inherit "obj/monster.talk";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("old man");
set_alias("man");
set_short("An old wrinkly man");
set_long("This is the last of the great vampire killers.\n");
set_level(20);
set_aggressive(0);
set_al(30);
set_wc(30);
set_ac(17);
set_hp(500);
set_chat_chance(5);
load_chat("Old man says: I almost had him! but all I got was a piece of his cape!\n");
coins = clone_object("obj/money");
coins->set_money(100+(random(100)));
move_object(coins,this_object());
}
