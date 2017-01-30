 
inherit "obj/monster.talk";
 
object gold;
reset(arg) {
::reset(arg);
if (!arg) {
set_name("khan");
set_alias("ghengis");
set_short("Ghengis Khan");
set_race("man");
set_long(
"Ghengis Khan: <<Ruler>>\n"+
"This guy once almost conquered Europe..How long as this hunt\n"+
"been going on anyway?  And another thing, Your still in your own time??\n");
gold = clone_object("obj/money");
gold -> set_money (random(300)+200);
move_object(clone_object("/players/heroin/quests/paper3.c"), this_object());
set_level(15);
call_other(this_object(),"set_heal",1,1);
set_ac(7);
set_wc(13);
set_hp(100);
set_al(-10);
set_chance(10);
set_spell_dam(1);
set_spell_mess2("Khan goes berserk and slice you below the eye.");
set_spell_mess1("Khan tackles you to the ground.");
set_aggressive(0);
set_a_chat_chance(20);
set_chat_chance(50);
load_chat("The god of the earth...\n");
load_a_chat("........will destroy you!\n");
}
}
 
    
