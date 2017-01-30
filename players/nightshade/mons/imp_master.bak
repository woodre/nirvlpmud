inherit "obj/monster";
object gold, weap;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("imp");
set_alias("master");
set_short("Imp Master");
set_long("This huge guy is here to prevent those unworthy of killing imps\n"+
"from doing so. Dont attack him.\n");
set_level(30);
set_hp(2000);
set_wc(40);
set_ac(10);
gold=clone_object("obj/money");
gold->set_money(5000);
move_object(gold, this_object());
set_chance(45);
set_spell_dam(100);
set_spell_mess1("Die scum!");
set_spell_mess2("The masters axe screams over his head and nails you square in the jaw, ripping half your face off!");
}
