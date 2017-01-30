inherit "obj/monster.talk";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("duck");
set_short("Darkwing Duck");
set_long("Darkwing Duck says: I'm the terror that flaps in the night.\n");
set_al(0);
set_race("duck");
set_level(5);
set_wc(10);
set_hp(580);
set_ac(10);
set_spell_mess1("Darkwing blasts you\nDarkwing says: suck gas!\n");
set_spell_mess2("Darkwing laughs at your meager attempts\n");
set_chance(35);
set_spell_dam(14);
set_aggressive(0);
coins = clone_object("obj/money");
coins->set_money(500);
move_object(coins,this_object());
}

