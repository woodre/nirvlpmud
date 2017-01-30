inherit "obj/monster.talk";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("lois");
set_short("Lois Lane");
set_long("Looks like you woke her up or she was expecting company.*grin*\n");
set_al(10);
set_race("human");
set_level(8);
set_wc(12);
set_hp(160);
set_ac(7);
set_spell_mess1("Lois whips you\n");
set_spell_mess2("Lois slaps you\n");
set_chance(15);
set_spell_dam(4);
set_aggressive(0);
coins = clone_object("obj/money");
coins->set_money(100);
move_object(coins,this_object());
}
