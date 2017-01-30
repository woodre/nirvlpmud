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
  set_name("worker");
  set_alt_name("worker");
  set_alias("worker ant");
  set_short(""+HIK+"A very large Worker Ant"+NORM+"");
  set_long("This is one of the worker ants.  This ant is close to the size of the army ants.  She\n"+
           "stands about seven feet tall.  The worker is black with six large legs and a very sharp.\n"+
           "jaw.  The worker ants are mainly used for the gathering of food, using what ever is available.\n"+
           "It seems the queen ant has a distinct taste for human flesh.\n");
  set_race("ant");
  set_gender("female");
  set_level(18);
  set_wc(23+random(4));
  set_hp(330+random(100));
  set_ac_bonus(8);
  set_wc_bonus(16);
  set_heal(5,5);
  add_money(0);
  set_aggressive(0);
  set_dead_ob(this_object());
  set_al(-200);
  load_chat("The worker ant continues to tear flesh from the corpses.\n");
  load_chat("The worker ant chatters loudly.\n");
  set_chat_chance(10);
  load_a_chat("The worker ant throws you to the ground, attempting to make you the queen's next meal.\n");
  load_a_chat("The worker ant takes a bite at you, just missing.\n");
  set_a_chat_chance(20);
}

id(str) { return (::id(str) || str == "insect"); }

monster_died() {
  move_object(clone_object("/players/pestilence/amity/obj/metasoma.c"),
      environment(this_object()));
  tell_room(environment(this_object()),
        "As the worker ant hits the ground her metasoma breaks off from her body.\n");
return 0; }



flesh_tear(){

string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
    say("The worker ant "+RED+"lacerates"+NORM+" "+ATT_NAME+" with her teeth.\n");
       tell_object(attacker_ob,
"The worker ant "+RED+"lacerates"+NORM+" you with her teeth.\n");
if(attacker_ob->query_npc())
attacker_ob->heal_self(-20-random(20));
else
attacker_ob->add_hit_point(-20-random(20));
}

flesh_impale(){

string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
    say("The worker ant knocks "+ATT_NAME+" to the ground.\n"+
        "The worker ant begins to kick "+ATT_NAME+" while "+ATT_NAME+" is down.\n"+
        ""+HIR+"Blood flows freely from "+ATT_NAME+"'s wounds"+NORM+".\n"+
        ""+ATT_NAME+" recovers, gets back to their feet.\n");
       tell_object(attacker_ob,
        "The worker ant knocks you to the ground.\n"+
        "The worker ant begins to kick's you while you are down.\n"+
        ""+HIR+"Blood flows freely from your wounds"+NORM+".\n"+
        "You recover, and get back to your feet.\n");
if(attacker_ob->query_npc())
attacker_ob->heal_self(-25-random(20));
else
attacker_ob->add_hit_point(-25-random(20));
}


heart_beat(){
 object ob;
 object att;
 object next;
 if(!environment()) return;
/*
 if(!attacker_ob)
 if(ob = present("ant", environment())) { if(ob->query_attack()) attack_object(ob->query_attack()); } ;
*/
 ::heart_beat();

if(attacker_ob){
i = random(25);
switch(i){


    case 0..3: flesh_tear();
  break;

    case 4..9: flesh_impale();
  break;

    case 10..24: return 0;
  break;
    }
  }
}
