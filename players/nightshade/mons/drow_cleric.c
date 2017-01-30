inherit "obj/monster";
reset(arg) {
object gld, weap;
::reset(arg);
if(arg) return;
set_name("cleric");
set_alias("drow");
set_short("Drow Cleric");
set_long("A thin muscular female drow dressed in the clerical robes of their evil deity Lolth.\n");
set_level(20);
set_hp(500);
set_wc(30);
set_ac(17);
set_al(-1000);
set_chance(25);
set_spell_dam(30);
set_spell_mess1("The drow rolls her eyes back into her head and calls upon the power of Lolth!");
set_spell_mess2("You are hit with a massive wave of mental energy!");
gld=clone_object("obj/money");
gld->set_money(random(100) + 1000);
move_object(gld, this_object());
weap=clone_object("players/nightshade/weap/whip");
move_object(weap, this_object());
}

/* wc was 15, ac was 13, hp was 400 - mythos <6-17-96> */
