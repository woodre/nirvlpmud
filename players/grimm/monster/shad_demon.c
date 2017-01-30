inherit "obj/monster.talk";
object coins, armor;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("demon");
set_alias("shadow");
set_short("Shadow Demon");
set_long("This foul creature is the essence of a demon imprisoned in the"
+" form of a\nshadow.\n");
set_al(-750);
set_level(20);
set_wc(30);
set_hp(500);
set_ac(17);
set_aggressive(0);
armor = clone_object("players/grimm/armor/shad_armor");
move_object(armor,this_object());
coins = clone_object("obj/money");
coins->set_money(700+(random(200)));
move_object(coins,this_object());
}
