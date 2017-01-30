inherit "obj/monster.talk";

object gold;
reset(arg) {
::reset(arg);
if (!arg) {
set_name("batman");
set_alias("pussy");
set_short("Batman the pussy");
set_race("pussy");
set_long(
"At last, standing before you is the great Batman. Except, you seemed\n"+
"to have have caught him right after he got out of the shower.  Here\n"+
"is the great Batman reduced down to a wet towel and a pair of socks.\n"+
"You notice the bat belt laying off to the side. When you examine the\n"+
"belt closely, you realize it is nothing more than costume jewelery.\n"+
"You really can't help but giggle at how ludicris the whole thing is.\n"+
"You almost feel sorry for Batman and almost decide to spare his \n"+
"life...well that is...almost!\n");
gold = clone_object("obj/money");
gold -> set_money (random(400)+400);
set_level(13);
call_other(this_object(),"set_heal",0,0);
set_ac(10);
set_wc(17);
set_hp(195);
set_al(5);
set_chance(20);
set_spell_dam(15);
set_spell_mess2("Batman snaps you with his towel.");
set_spell_mess1("Batman reveals himself to you.");
set_aggressive(0);
set_a_chat_chance(20);
set_chat_chance(20);
load_chat("If you spare me, I let you borrow Robin and the batcar. \n");
load_a_chat("Hey, thats not my belly button!!!!! \n");
}
}

