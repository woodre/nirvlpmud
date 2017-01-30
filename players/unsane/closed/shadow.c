inherit "obj/monster.talk";

object mane,gold,foe,foe_name;
reset(arg) {
::reset(arg);
if(!arg) {
set_alias("");
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
set_chance(10);
enable_commands();
set_heart_beat(1);
set_spell_dam(30);
set_chat_chance(10);
load_chat("Cerebus paws at the ground.\n");
load_chat("Cerebus sniffs at you.\n");
load_chat("Cerebus licks his sharp teeth.\n");
load_chat("Cerebus growls at you.\n");
set_a_chat_chance(20);
load_a_chat("Cerebus begins panting and foaming at the mouth.\n");
load_a_chat("Cerebus shrugs off your blows.\n");
load_a_chat("Cerebus yelps.\n");
load_a_chat("You are touched by the hot breath of Cerebus.\n");
set_spell_mess1("Cerebus smashes his foe with his wicked tail!");
set_spell_mess2("Cerebus lashes at you with his tail!");
   set_level(20);
   set_ac(35);
   set_wc(30);
   set_al(-1000);
set_hp(500);
  set_aggressive(0);
}
}
heart_beat(){
object attacker,preyroom;
::heart_beat();
attacker=this_object()->query_attack();
if (attacker){
foe = attacker;
foe_name=foe->query_real_name();
}
if (foe && !foe->query_ghost()){
  preyroom=environment(foe);
  if (!present(foe_name,environment(this_object()))){
    say("Predator screams and leaves hunting "+foe_name+".\n");
    move_object(this_object(),preyroom);
    say("The Predator has found you!\n");
          }
  }
}
