inherit "obj/monster.talk";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("silversurfer");
set_short("The Silversurfer");
set_long("His whole body seems to glow.\n");
set_al(0);
set_race("human");
set_level(18);
set_wc(26);
set_hp(450);
set_ac(14);
set_spell_mess1("You get his by a surfboard\n");
set_spell_mess2("The Surfer blasts by you on his board\n");
set_chance(15);
set_spell_dam(10);
set_aggressive(0);
coins = clone_object("obj/money");
coins->set_money(1000);
move_object(coins,this_object());
}
