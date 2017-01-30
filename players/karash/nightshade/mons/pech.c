inherit "obj/monster";
object gold;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("pech");
set_short("Pech");
set_long("A small funny looking creature. He works the stone of the Underdark.\n");
set_level(5);
set_hp(100);
set_ac(5);
set_wc(10);
gold=clone_object("obj/money");
gold->set_money(200);
move_object(gold, this_object());
}
