int i;
object gold;
inherit "/obj/monster.talk";

object mane;
reset(arg) {
::reset(arg);
if(!arg) {
set_alias("the wrathful");
set_alt_name("soul");
    set_name("wrathful");
set_short("A Wrathful Soul");
    set_race("demon");
set_long(
"  These people were cruel and vicious in their past life.  They did nothing\n"+"but dish out suffering and pain to others.  Among these people you see some\n"+
"of the most brutal killers of your time.  The wrathful immediatly take notice\n"+
"of you, for you are new prey.  They are becoming tired of tearing each\n"+
"other to pieces.  Now they can tear you apart!\n");
gold =  clone_object("obj/money");
gold->set_money(random(500)+150);
move_object(gold, this_object());
set_chance(10);
set_spell_mess1("A wrathful soul rips his foe open with a wicked claw!");
set_chat_chance(2);
load_chat("A wrathful soul rips off the arm of another soul.\n");
load_chat("The wrathful scream in anticipation of the kill.\n");
load_chat("The wrathful tear each other to pieces.\n");
set_a_chat_chance(3);
load_a_chat("The wrathful begin to bicker about who gets the final kill.\n");
load_a_chat("A wrathful soul screams at you.\n");
load_a_chat("A wrathful soul froths at the mouth.\n");
set_spell_mess2("You are ripped open by the vicious claw of a wrathful soul!");
   set_level(15);
   set_ac(16);
   set_wc(30);
   set_al(-500);
 set_hp(300);
  set_aggressive(1);
set_can_kill(1);
}
}
