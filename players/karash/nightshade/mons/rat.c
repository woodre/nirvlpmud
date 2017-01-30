inherit "obj/monster";
object gold;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("rat");
set_short("Rat");
set_long("What else can i say. Its a rat.\n");
set_level(1);
set_hp(30);
set_wc(5);
set_ac(3);
gold=clone_object("obj/money");
gold->set_money(random(15));
move_object(gold, this_object());
}
