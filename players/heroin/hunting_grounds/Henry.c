inherit "/obj/monster.c"; /* monster.talk no longer loads -Feld 8/19/00 */

object gold;
reset(arg) {
::reset(arg);
if(!arg) {
    set_name("henry");
set_alias("henry");
set_short("Henry the dog");
    set_race("dog");
    set_long(
"Henry is Angst's faithful mutt.  He remains to keep Angst\n"+
"company.  Angst is so fond of his dog, that he would do \n"+
"anything to protect her.  I mean anything! Henry is really\n"+
"happy to see you..she's always looking for someone to play with\n"+
"All-in-all, Henry is a good animal.  You wish she was your \n"+
"companion.  It occurs to you, if i was really nice to her, she\n"+
"might be able to help me out. I guess I better NEVER, EVER attack her\n");
gold = clone_object("obj/money");
gold -> set_money (random (2000) + 500);
move_object(gold, this_object());
   set_level(20);
call_other(this_object(),"set_heal",0,0);
   set_ac(30);
   set_wc(30);
   set_hp(10000);
   set_al(-300);
set_chance(20);
set_spell_dam(100);
set_spell_mess1("Henry licks away part of your soul.");
  set_spell_mess2("Henry's tail knocks the wind out of you.\n");
  set_aggressive(0);
    set_a_chat_chance(10);
   set_chat_chance(10);
load_chat("Henry plays dead and wants ya to rub her belly\n");
load_chat("Henry says: I am a dog dummy-I cant speak\n");
load_a_chat("Henry puts her ears back\n");
load_a_chat("You pissed off my master...GoodBye\n");
}
}
