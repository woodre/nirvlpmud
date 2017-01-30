 
inherit "obj/monster.talk";
 
object gold;
reset(arg) {
::reset(arg);
if (!arg) {
set_name("hitler");
set_alias("adolph");
set_short("Adolph Hitler");
set_race("man");
set_long(
"As you stare at Hitler, He begins to talk: \n"+
"You'll never get anything out of me!  I will never help you.\n"+
"I'll do ANYTHING to stop you!.................\n"+
"With that Hitler takes a knife from the table and cuts\n"+
"off his own tongue!\n"+
"Man, this guy means business, Yick\n");
gold = clone_object("obj/money");
gold -> set_money (random(300)+200);
move_object(clone_object("/players/heroin/quests/tongue.c"), this_object());
set_level(7);
call_other(this_object(),"set_heal",1,1);
set_ac(3);
set_wc(3);
set_hp(100);
set_al(-10);
set_chance(10);
set_spell_dam(1);
set_spell_mess2("Hummph Hummph Phat Tho Thfucker");
set_spell_mess1("Hitler salutes hitting you in the eye.");
set_aggressive(0);
set_a_chat_chance(20);
set_chat_chance(50);
load_chat("HUMMPH HUMMPH BLUm FUUSH MUUPHO \n");
load_a_chat("NAH NAH NAH NAH!\n");
}
}
 
   
