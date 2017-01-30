inherit "obj/monster.talk";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("pirate");
set_short("The Dread Pirate Roberts");
set_long("The pirate smiles at you.\n");
set_al(0);
set_race("human");
set_level(18);
set_wc(16);
set_hp(450);
set_ac(14);
set_spell_mess1("Roberts switches to his left hand\n");
set_spell_mess2("Roberts switches to his right hand\n");
set_chance(15);
set_spell_dam(22);
set_aggressive(0);
coins = clone_object("obj/money");
coins->set_money(800 + random(200));
move_object(coins,this_object());
}
