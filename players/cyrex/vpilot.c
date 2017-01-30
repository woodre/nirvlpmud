inherit "obj/monster";
object gold;
int items;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("pilot");
set_alias("pilot");
set_short("Veritech pilot");
set_long("This is the pilot of the Veritech. He looks pissed!\n");
set_level(10);
set_hp(350);
set_al(-100);
set_ac(15);
set_wc(15);
set_whimpy();
set_aggressive(1);
gold=clone_object("obj/money");
gold->set_money(random(500)+700);
move_object(gold, this_object());
}

