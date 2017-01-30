inherit "obj/monster.talk";

object gold;
reset(arg) {
::reset(arg);
if (!arg) {
set_name("Nugent");
set_alias("nugent");
set_short("Ted Nugent");
set_race("nugent");
set_long(
"The Motor City Madman....The Rocker from Detroit....\n"+
"The Actor....The Homophob....The Right Wing's longhair \n"+
"spokesman...The Avid Bowsman......THE.......\n"+
".............Hunter!!!!!!!!!!.................\n"+
"Go ahead and kill the SOB\n");
gold = clone_object("obj/money");
gold -> set_money (random(200)+600);
move_object(clone_object("/players/heroin/hunting_grounds/compound.c"), this_object());
set_level(16);
call_other(this_object(),"set_heal",0,0);
set_ac(13);
set_wc(20);
set_hp(300);
set_al(0);
set_chance(20);
set_spell_dam(15);
set_spell_mess2("Just Say No to Drugs");
set_spell_mess1("Ted cat scratches your eyes out");
set_aggressive(0);
set_a_chat_chance(20);
set_chat_chance(20);
load_chat("I've been duped by the right wing \n");
load_a_chat("Wait a minute- I thought you only wanted an autograph \n");
}
}

