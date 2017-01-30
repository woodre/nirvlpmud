inherit "/obj/monster";

object mane,gold;
reset(arg) {
::reset(arg);
if(!arg) {
set_alias("dog");
set_alt_name("hellhound");
    set_name("cerberus");
set_short("Cerberus the Hellhound");
    set_race("demon");
set_long(
"This creature is the guardian of the Third Circle.  He is an enormous\n"+
"Dog-like creature.  His body is bristling with course fur and chipped scales.\n"+
"He is quite unsettling to look at.  Each of his three heads resemble lion's\n"+
"heads.  His skin and tail both have a reptilian appearance and are both grey\n"+
"in colour.  He seems to be studying you carefully, as if deciding whether\n"+
"or not to attack you.  This might be your only chance to run.\n");
gold = clone_object("/obj/money");
gold->set_money(random(1000)+1000);
move_object(gold,this_object());
mane=clone_object("players/unsane/closed/hell/mane.c");
move_object(mane, this_object());
init_command("wear mane");
set_chance(10);
set_spell_dam(30);
set_chat_chance(10);
load_chat("Cerberus paws at the ground.\n");
load_chat("Cerberus sniffs at you.\n");
load_chat("Cerberus licks his sharp teeth.\n");
load_chat("Cerberus growls at you.\n");
set_a_chat_chance(20);
load_a_chat("Cerberus begins panting and foaming at the mouth.\n");
load_a_chat("Cerberus shrugs off your blows.\n");
load_a_chat("Cerberus yelps.\n");
load_a_chat("You are touched by the hot breath of Cerberus.\n");
set_spell_mess1("Cerberus smashes his foe with his wicked tail!");
set_spell_mess2("Cerberus lashes at you with his tail!");
   set_level(20);
   set_ac(35);
   set_wc(30);
   set_al(-1000);
set_hp(500);
  set_aggressive(0);
}
}
