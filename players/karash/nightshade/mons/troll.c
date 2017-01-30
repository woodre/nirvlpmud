inherit "obj/monster";
object gold;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("troll");
set_short("Troll");
set_long("A tall, lanky, green, ugly, smelly, mother. He insulted your mom.\n");
set_level(16);
set_hp(400);
set_ac(13);
set_wc(22);
gold=clone_object("obj/money");
gold->set_money(500);
move_object(gold, this_object());
}
