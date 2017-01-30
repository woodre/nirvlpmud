/* Assistance code provided by Jaraxle, Jenny */
#include "/players/pestilence/ansi.h"
inherit "/players/vertebraker/closed/std/monster";
#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
#define attacker attacker_ob
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Guard Ant");
  set_alt_name("guard ant");
  set_alias("guard");
  set_short("A Guard Ant");
  set_long("This ant is dark black and around eight feet tall.  It appears he is guarding something\n"+
           "from the humans.\n");
  set_race("ant");
  set_gender("male");
  set_level(20);
  set_wc(30);
  set_ac(17);
  set_hp(500);
  set_heal(20,3);
  add_money(0);
  set_aggressive(0);
  set_dead_ob(this_object());
  set_al(-700);
  load_chat("The ant pushes you to the ground.\n");
  set_chat_chance(20);
  load_a_chat(""+HIK+"Ant tries to rip your limbs off"+NORM+".\n");
  load_a_chat("The Guard Ant spits on you.\n");
  set_a_chat_chance(30);
  set_spell_mess2(""+RED+"The Guard Ant rips into your flesh"+NORM+".\n");
  set_spell_mess1(""+RED+"The Guard Ant tears into some flesh"+NORM+".\n");
  set_chance(15);
  set_spell_dam(20);
}

id(str) { return (::id(str) || str == "insect"); }

init() {
  ::init();
add_action("stop","enter");
}
stop() {
if(TP->query_ghost() == 1) { return 0; }
else{
write("Guard ant pushes you to the ground, not allowing you to leave.\n");
return 1; }
}


monster_died() {
  move_object(clone_object("/players/pestilence/amity/obj/antennae2.c"),
      environment(this_object()));
  tell_room(environment(this_object()),
        "As the ant dies, the antennae breaks off from his head.\n");
return 0; }

slice_dice(){

string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
 
    say("The ant slices "+ATT_NAME+" down the torso leaving "+ATT_NAME+RED+" eviscerated"+NORM+".\n");
       tell_object(attacker_ob,
"The ant slices you down the torso leaving "+ATT_NAME+RED+" eviscerated"+NORM+".\n");
    attacker_ob->add_hit_point(-20-random(20));
}


flesh_tear(){

string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
 
    say("The ant "+RED+"tears flesh"+NORM+" from "+ATT_NAME+", spewing "+HIR+"blood"+NORM+" all over.\n");
       tell_object(attacker_ob,
"The ant "+RED+"tears flesh"+NORM+" from you, spewing "+HIR+"blood"+NORM+" all over.\n");
 move_object(clone_object("/players/pestilence/amity/obj/flesh.c"),
      environment(this_object()));
    attacker_ob->add_hit_point(-20-random(60));
}


heart_beat(){
int i;
  ::heart_beat();
if(attacker_ob){
i = random(18);
switch(i){

    case 0..1: flesh_tear();
  break;

    case 2..6: slice_dice();
  break;

    case 7..17: return 0;
  break;
    }
  }
}
