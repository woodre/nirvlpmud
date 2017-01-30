inherit "obj/monster.talk";

object gold;
reset(arg) {
::reset(arg);
if (!arg) {
set_name("robot");
set_alias("robot");
set_short("robot for now");
set_race("robot");
set_long(
"This is the ship's android.  He is responsible for all medical\n"+
"and science aspects of the mission.  His number one priority is\n"+
"to make sure that the alien specimen makes it back to Earth. To\n"+
"Guarantee this, he is willing to destroy anything or anyone who would\n"+
"hurt the aliens.  Lucky for you, he is already damaged.  He is \n"+
"spurting white goo everywhere. Unlucky for you, is that now he is\n"+
"in berserker mode..Guess you have to take the good with the bad.\n");
gold = clone_object("obj/money");
gold -> set_money (random(500)+500);
set_level(13);
call_other(this_object(),"set_heal",0,0);
set_ac(10);
set_wc(17);
set_hp(225);
set_al(-100);
set_chance(30);
set_spell_dam(10);
set_spell_mess2("White goo gets sprayed in your eyes.");
set_spell_mess1("The android throws you across the room like a ragdoll.");
set_aggressive(1);
set_a_chat_chance(20);
set_chat_chance(20);
load_chat("You are expendable..The alien must be preserved. \n");
load_a_chat("I Will Kill You Myself Then..Beep Beep. \n");
}
}

