inherit "obj/monster.talk";

object gold;
reset(arg) {
::reset(arg);
if (!arg) {
set_name("Crew member");
set_alias("crew");
set_short("crew member");
set_race("crew");
set_long(
"This is a ramdomly selected crew member.  The aliens has killed\n"+
"several, and Angst brings back a few now and then.  Afterall,\n"+
"what could be more fun then not only letting someone die over and\n"+
"over and each lifetime realizing ones' futility.  Are you as cruel\n"+
"as Angst?\n");
gold = clone_object("obj/money");
gold -> set_money (random(100)+750);
move_object(clone_object("/players/heroin/hunting_grounds/mchnguns.c"), this_object());
set_level(14);
call_other(this_object(),"set_heal",0,0);
set_ac(11);
set_wc(17);
set_hp(200);
set_al(0);
set_chance(30);
set_spell_dam(7);
set_spell_mess2(" You are torched you with a flame thrower!");
set_spell_mess1("You are punched from behind.");
set_aggressive(0);
set_a_chat_chance(25);
set_chat_chance(25);
load_chat("Have you seen Ripley? \n");
load_a_chat("I wish Ripley was here! She'ld know what to do. \n");
}
}

