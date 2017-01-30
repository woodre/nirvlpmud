inherit "obj/monster.talk";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("catwoman");
set_short("Catwoman");
set_long("This must be an imposter.\n");
set_al(-1000);
set_race("human");
set_level(10);
set_wc(14);
set_hp(150);
set_ac(8);
set_spell_mess1("Catwoman throws her head back and cackles with glee\n");
set_spell_mess2("Catwoman hits you again\n");
set_chance(15);
set_spell_dam(5);
set_aggressive(0);
coins = clone_object("obj/money");
coins->set_money(325+(random(200)));
move_object(coins,this_object());
}
