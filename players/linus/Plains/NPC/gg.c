/* Assistance code provided by Jaraxle, Jenny */
#include "/players/pestilence/ansi.h"
inherit "/players/vertebraker/closed/std/monster";
#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
#define attacker attacker_ob
int i;
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name(""+HIY+"Ant of the Royal Guard"+NORM+""); 
  set_alt_name("royal guard");
  set_alias("guard");
  set_short(""+HIY+"Ant of the Royal Guard"+NORM+"");
  set_long("This is one of the "+HIY+"Royal Ant Guards"+NORM+".  He is slightly larger than the army ants.\n"+
           "He is very protective of his queen and will do anything to prevent you from getting to her.\n");
  set_race("ant");
  set_gender("male");
  set_level(20);
  set_wc(32+random(4));
  set_ac(18+random(4));
  set_hp(550+random(200));
  set_ac_bonus(8);
  set_wc_bonus(16);
  set_heal(15,5);
  add_money(0);
  set_aggressive(0);
  set_dead_ob(this_object());
  set_al(-700);
  load_chat(""+HIY+"Royal Guard"+NORM+" says: We must protect the queen, don't let anyone by!\n");
  set_chat_chance(20);
  load_a_chat(""+HIY+"Royal Guard"+NORM+" pushes you against the wall.\n");
  load_a_chat("The ant circles around you.\n");
  set_a_chat_chance(20);
}

init() {
  ::init();
add_action("stop","south");
}
stop() {
if(TP->query_ghost() == 1) { return 0; }
else{
write("The "+HIY+"Royal Guard"+NORM+" throws you to the ground, not allowing you to leave.\n");
return 1; }
}


monster_died() {
  move_object(clone_object("/players/pestilence/amity/obj/thorax.c"),
      environment(this_object()));
  tell_room(environment(this_object()),
        "As the "+HIY+"Royal Guard"+NORM+" hits the ground, his thorax breaks off from his body.\n");
return 0; }



flesh_tear(){

string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
 
    say("The "+HIY+"Royal Guard"+NORM+" "+RED+"lacerates"+NORM+" "+ATT_NAME+" with his teeth.\n");
if(attacker_ob->query_npc())
attacker_ob->heal_self(-20-random(20));
else
attacker_ob->add_hit_point(-20-random(20));
}

flesh_impale(){

string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
    say("The "+HIY+"Royal Guard"+NORM+" impales "+ATT_NAME+" with one of his legs.\n");
if(attacker_ob->query_npc())
attacker_ob->heal_self(-15-random(20));
else
attacker_ob->add_hit_point(-15-random(20));
}

mass_attack() {

string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
    say("The "+HIY+"Royal Guard"+NORM+" bites into "+ATT_NAME+"'s arm causing a large "+RED+"bloody"+NORM+" wound.\n");
if(attacker_ob->query_npc())
attacker_ob->heal_self(-10-random(20));
else
attacker_ob->add_hit_point(-10-random(20));
}


heart_beat(){
 ::heart_beat();

if(attacker_ob){
i = random(25);
switch(i){


    case 0..3: flesh_tear();
  break;

    case 4..6: flesh_impale();
  break;

    case 7..9: return 0;
  break;

    case 10..14: mass_attack();
  break;

    case 15..24: return 0;
  break;
    }
  }
}
