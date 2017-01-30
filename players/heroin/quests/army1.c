 
inherit "obj/monster.talk";
 
object gold;
reset(arg) {
::reset(arg);
if (!arg) {
set_name("soldier");
set_alias("man");
set_short("A soldier");
set_race("human");
set_long(
"This is just an ordinary foot soldier.  Nothing really strange\n"+
"except for the fact that this man is dressed in a WW2 Nazi outfit?\n");
move_object(clone_object("/players/heroin/quests/rifle.c"),this_object());
gold = clone_object("obj/money");
gold -> set_money (random(300)+200);
set_level(9);
call_other(this_object(),"set_heal",1,1);
set_ac(7);
set_wc(13);
set_hp(135);
set_al(-10);
set_chance(10);
set_spell_dam(5);
set_spell_mess2("RATATAT TAT  You'll Never get past me!");
set_spell_mess1("plunges his bayonet into your gut.");
set_aggressive(1);
set_a_chat_chance(20);
set_chat_chance(20);
load_chat("I've got my orders. \n");
load_a_chat("You're not a man: Youre a savage beast!\n");
}
}
 
        
