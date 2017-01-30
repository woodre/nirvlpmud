inherit "obj/monster.talk";

object gold;
reset(arg) {
::reset(arg);
if (!arg) {
set_name("Chester");
set_alias("Chester");
set_short("Chester the biomech");
set_race("biomech");
set_long(
"	This is Chester, like Angst,he is also a biomech. \n"+
"Angst and Chester were friends for hundreds of years.  They grew\n"+
"up hunting together.  In fact, they shared their first human \n"+
"together.  In their spare time, Angst and Chester would play chess\n"+
"and drink beer.  For years, Chester let Angst win- until one day.\n"+
"Angst was so enraged to lose at the game that he went before the \n"+
"the Masters and demanded revenge.  The masters responded by placing\n"+
"Chester forever trapped inside the game in which Angst was defeated\n"+
"Everytime, Chester makes the move that defeated Angst the board \n"+
"changes so Chester has to recreate the scene.  The only way Chester\n"+
"can escape is if he solves the game and defeats the Masters' board\n"+
"once and for all!\n");
gold = clone_object("obj/money");
gold -> set_money (random(500)+500);
set_level(15);
call_other(this_object(),"set_heal",0,0);
set_ac(12);
set_wc(18);
set_hp(200);
set_al(-1);
set_chance(20);
set_spell_dam(10);
set_spell_mess2("You are pawn in the Masters' game!");
set_spell_mess1("You are slammed to the ground by a rook!");
set_aggressive(0);
set_a_chat_chance(20);
set_chat_chance(20);
load_chat("Shhh..this time I'll get 'em. \n");
load_a_chat("You are now in check! \n");
}
}

