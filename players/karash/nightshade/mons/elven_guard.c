inherit "obj/monster";
object gold, weap, arm;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("guard");
set_short("Elven guard");
set_long(
"One of the kings guards. Hee looks you over and thinks you are ok.\n");
set_level(10);
set_hp(150);
set_ac(8);
set_wc(14);
gold=clone_object("obj/money");
gold->set_money(300);
move_object(gold, this_object());
weap=clone_object("players/nightshade/weap/short_sword");
move_object(weap, this_object());
arm=clone_object("players/nightshade/armor/leather");
move_object(arm, this_object());
}
