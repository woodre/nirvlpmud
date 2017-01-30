inherit "obj/monster";
object gold, weap, pch;
reset(arg) {
  ::reset(arg);
if(arg) return;
set_alias("thief");
set_level(5);
set_hp(250);
set_ac(10);
set_wc(14);
set_aggressive(1);
gold=clone_object("obj/money");
gold->set_money(450);
move_object(gold, this_object());
pch=clone_object("players/nightshade/misc/pouch");
move_object(pch, this_object());
}
