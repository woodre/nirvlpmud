inherit "obj/monster.talk";

object gold;
reset(arg) {
::reset(arg);
if (!arg) {
set_name("Momma");
set_alias("queeny");
set_short("Momma Alien");
set_race("alien");
set_long(
"This is perhaps the universes' most perfect mother.  She hunts\n"+
"she kills, she breeds with herself.  She is death and life in\n"+
"one vicious creation.  She stands at about 30 feet tall and moves\n"+
"at around 10 miles per hour.  She has the strength of approximately\n"+
"30 grown men, and she needs approximately the same number for food\n"+
"every day.  She resembles the other aliens you have encountered \n"+
"except for the sheer size of her.  She does appear to have a few\n"+
"differences which may be to your advantage.  She doesn't appear to \n"+
"have the same jaws as her children.  This means most her attacks \n"+
"should be singular and slower.\n");
gold = clone_object("obj/money");
gold -> set_money (random(1000)+3000);
move_object(clone_object("/players/heroin/hunting_grounds/scales.c"), this_object());
set_level(18);
call_other(this_object(),"set_heal",0,0);
set_ac(15);
set_wc(15);
set_hp(450);
set_al(-10);
set_chance(20);
set_spell_dam(30);
set_spell_mess2("She begins to rip your arms from your body");
set_spell_mess1("She slashes you from the crotch to your neck.");
set_aggressive(1);
set_a_chat_chance(20);
set_chat_chance(20);
load_chat("Shreeeeeeeeeek....crahhhhhhhhh...Shreeeeeeek... \n");
load_a_chat("DDDDDDDDDDDIIIIIIIIIIIIIIIIEEEEEEEEEEEEEEEEEEE \n");
}
}

