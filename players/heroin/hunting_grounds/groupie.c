inherit "obj/monster.talk";

object gold;
reset(arg) {
::reset(arg);
if (!arg) {
set_name("groupie");
set_alias("fan");
set_short("rock groupie");
set_race("groupie");
set_long(
"This is a groupie. He/she exists entirely within the world of \n"+
"rock-n-roll.  Groupies hang out and tell other groupies about the\n"+
"shows they have seen.  Groupies are normally only seen out on the\n"+
"floor, however, this by choice, since most groupies are friends \n"+
"with the preformers.  In fact, the preformers sometimes gain expert\n"+
"technical advice from the groupie.  In return for the honor that the\n"+
"performers endow on their groupies, the groupies will fight to the \n"+
"death over any critisism.  Uh oh, this groupie is stoned watch out\n"+
"you know how squirrely pot makes them!\n");
gold = clone_object("obj/money");
gold -> set_money (random(500)+400);
set_level(13);
call_other(this_object(),"set_heal",0,0);
set_ac(10);
set_wc(17);
set_hp(195);
set_al(-100);
set_chance(20);
set_spell_dam(15);
set_spell_mess2("The groupie blows smoke in your face.");
set_spell_mess1("The groupie bangs his head, and knocks you out.");
set_aggressive(0);
set_a_chat_chance(25);
set_chat_chance(25);
load_chat("Uh you might not of known this, but my dad was in the Beatles. \n");
load_a_chat("And to think I was going to show where the kind bud was..Jesus. \n");
}
}

