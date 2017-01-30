 
inherit "obj/monster.talk";
 
object gold;
reset(arg) {
::reset(arg);
if (!arg) {
set_name("guard");
set_alias("man");
set_short("Hitler's guard");
set_race("human");
set_long(
"6'2 and eyes of blue.  An arayan wet dream...Are you sure you don't\n"+
"want to retire?\n");
move_object(clone_object("/players/heroin/quests/boots.c"),this_object());
gold = clone_object("obj/money");
gold -> set_money (random(300)+200);
set_level(18);
call_other(this_object(),"set_heal",1,1);
set_ac(15);
set_wc(5);
set_hp(250);
set_al(-10);
set_chance(10);
set_spell_dam(7);
set_spell_mess2("HAIL HITLER..DIE YOU SCUM");
set_spell_mess1("His fists move like lightning!.");
set_aggressive(1);
set_a_chat_chance(20);
set_chat_chance(50);
load_chat("Ever heard him speak..he speaks with the tounge of God. \n");
load_a_chat("I've been waiting for such a stupid move!\n");
}
}
 
    
