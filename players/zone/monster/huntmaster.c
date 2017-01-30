
inherit"obj/monster";
reset(arg) {
object money;
::reset(arg);
if(arg) return;
set_name("huntmaster");
set_alias("master");
set_short("Hunt's Master");
set_long(
"This is the leader of the wild hunt.  While humanoid, he has antlers on his\n"
+ "head.  Though his face is there, you can't seem to see it, save for fiery\n"
+ "eyes.\n");
set_level(20);
set_race("man");
set_hp(1500);
set_wc(30);
set_ac(20);
set_chance(25);
set_spell_dam(40);
set_spell_mess1("The Hunt's master bays!");
money = clone_object("obj/money");
money->set_money(500);
move_object(money, this_object());
}
