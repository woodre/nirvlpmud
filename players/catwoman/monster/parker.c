inherit "obj/monster.talk";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("peter");
set_short("Peter Parker");
set_long("He looks busy working on a story.\n");
set_al(100);
set_race("human");
set_level(5);
set_wc(9);
set_hp(100);
set_ac(5);
set_spell_mess1("Parker slaps hard!\n");
set_spell_mess2("Parker slaps you hard!\n");
set_chance(15);
set_spell_dam(20);
set_aggressive(0);
coins = clone_object("obj/money");
coins->set_money(300);
move_object(coins,this_object());
}
