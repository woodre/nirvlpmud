inherit "obj/monster.talk";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("hooker");
set_short("A hooker");
set_long("I think she likes you.\n");
set_al(0);
set_race("human");
set_level(3);
set_wc(2);
set_hp(1160);
set_ac(0);
set_spell_mess1("Hooker says: hit me harder... harder ... oooooh\n");
set_spell_mess2("Hooker says: are you though yet?\n");
set_chance(25);
set_spell_dam(4);
set_aggressive(0);
coins = clone_object("obj/money");
coins->set_money(100);
move_object(coins,this_object());
}
