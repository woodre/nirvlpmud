inherit "obj/monster.talk";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("bruce");
set_short("Bruce Lee");
set_long(
  "Bruce Lee is on the brink of insanity.  He has been sent\n"+
  "here to defend the repressed.\n");
set_al(1000);
set_race("human");
set_level(17);
set_wc(24);
set_hp(425 + random(200));
set_ac(14);
set_spell_mess1("Bruce moves faster than the speed of light.\n");
set_spell_mess2("Bruce kicks you in the head with a round house.\n");
set_chance(15);
set_spell_dam(28);
set_aggressive(1);
coins = clone_object("obj/money");
coins->set_money(950);
move_object(coins,this_object());
}

