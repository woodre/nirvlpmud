inherit "obj/monster.talk";

object gold;
reset(arg) {
::reset(arg);
if (!arg) {
set_name("robin");
set_alias("boywonder");
set_short("Robin the boywonder");
set_race("robin");
set_long(
"Here's that happy-go-lucky, always amazed at Batman's abilities\n"+
"boy-wonder.  This is not, of course, the original Robin, since\n"+
"Batman disposes of boy wonders like most people throw away kleenex\n"+
"Actually, as you start to think about it...Robin really does get a\n"+
"bad wrap.  Afterall, Batman's writers are always willing to sacrifice\n"+
"him, he got the cruddy outfit, and he has to pretend like Batman is\n"+
"actually clever.  As you think more and more about the situation\n"+
"you can't actually decide whether to spare his life or not!?!\n");
gold = clone_object("obj/money");
gold -> set_money (random(400)+400);
move_object(clone_object("/players/heroin/hunting_grounds/boyshchrm.c"), this_object());
set_level(13);
call_other(this_object(),"set_heal",0,0);
set_ac(10);
set_wc(17);
set_hp(225);
set_al(0);
set_chance(10);
set_spell_dam(5);
set_spell_mess2("Robin jumps on your back and pounds on you.");
set_spell_mess1("Robin ties you shoelaces together; you land with a thump.");
set_aggressive(0);
set_a_chat_chance(30);
set_chat_chance(30);
load_chat("Batman told me to stay here and he would be right back. \n");
load_a_chat("Screw that Batguy anyway- I'm out of here \n");
}
}

