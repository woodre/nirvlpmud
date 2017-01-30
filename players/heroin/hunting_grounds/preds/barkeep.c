inherit "obj/monster.talk";
object mane,gold,foe,foe_name;
reset(arg) {
::reset(arg);
if(!arg) {
set_alias("predator");
set_alt_name("manhunter");
    set_name("barkeep");
set_short("Predator Barkeep");
    set_race("predator");
set_long(
"This is the Predator known as Corky.\n"+
"He tends bar at Heroin's House of Ill repute..He hears about\n"+
"all the inner workings of Heroin's domain..Corky's\n"+
"only problem is that he has a BIG mouth when he's been\n"+
"drinking.  I bet if you stuck around long enough\n"+
"you'ld hear a rumor or two.\n");
gold = clone_object("/obj/money");
gold->set_money(random(2000)+1000);
move_object(gold,this_object());
move_object(clone_object("/players/heroin/hunting_grounds/preds/predstone.c"), this_object());
set_chance(10);
enable_commands();
set_heart_beat(1);
set_spell_dam(30);
set_chat_chance(80);
load_chat("I heard that pesky Mongol was hanging around again.\n");
load_chat("Ghengis Khan?? Muhhahahah Ghengis Khans!\n");
load_chat("Type safety to escape a chasing predator in the bar.\n");
load_chat("Predator plays with his necklace.\n");
set_a_chat_chance(20);
load_a_chat("Predator throws out his arms and screams to the sky.\n");
load_a_chat("Predator lunges at you with his claws.\n");
load_a_chat("Predator knocks you across the room.\n");
set_spell_mess1("Predator shoves his claws into your torso and holds you \n off the ground.");
set_spell_mess2("Predator puts his claws through you!");
   set_level(30);
   set_ac(35);
   set_wc(35);
   set_al(-1000);
set_hp(900);
  set_aggressive(0);
}
}
/*
heart_beat(){
object attacker,preyroom;
::heart_beat();
attacker=this_object()->query_attack();
if (attacker){
foe = attacker;
foe_name=foe->query_real_name();
}
if (foe->query_ghost()){
write("You are not yet worthy of the hunt, you poor unfortunate creature!\n");
move_object(this_player(), "room/church");
say ("The Predator releases a soul\n");
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
*/
