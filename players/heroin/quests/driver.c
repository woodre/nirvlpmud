 
inherit "obj/monster.talk";
 
object gold;
reset(arg) {
::reset(arg);
if (!arg) {
set_name("driver");
set_alias("man");
set_short("A Jeep Driver");
set_race("human");
set_long(
"This guy seems to have lucked out.  While his buddies are out on\n"+
"the front-line, he gets to transport important leaders.  Well, maybe\n"+
"this isnt his lucky day, he's sworn to protecting the leaders from you.\n");
move_object(clone_object("/players/heroin/quests/rifle.c"),this_object());
gold = clone_object("obj/money");
gold -> set_money (random(300)+200);
set_level(12);
call_other(this_object(),"set_heal",1,1);
set_ac(10);
set_wc(13);
set_hp(150);
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
 
  
