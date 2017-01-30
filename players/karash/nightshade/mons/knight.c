inherit "obj/monster";
object gold, weap;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("knight");
set_short("Skeletal Knight");
set_long("The skeletal knight is the long dead animated corpse of a once proud knight.\n");
set_level(10);
set_hp(150);
set_wc(15);
set_ac(8);
gold=clone_object("obj/money");
gold->set_money(250);
move_object(gold, this_object());
weap=clone_object("players/nightshade/weap/knight_sword");
move_object(weap, this_object());
}
