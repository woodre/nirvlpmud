#define WAR "/players/maledicta/cont/daemon"
#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";

object enemy;

reset(arg)  {

  ::reset(arg);
  if(arg) return;
set_name("darkling");
set_alt_name("demon");
set_race("darkling");
set_long(
"This is a small black skinned creature. It has short\n"+
"bat-like wings which seem barely able to hold its small\n"+
"3 foot tall frame. It is wirey in stature and yet very\n"+
"strong. The Darkling has small claws and tiny razor\n"+
"sharp teeth, both of which are capable of small amounts\n"+
"of damage.\n");
set_level(7);
set_hp(50);
set_al(-1000);
set_wc(50);
set_ac(2);
set_heart_beat(1);
set_aggressive(1);
}

short(){
if(attacker_ob){
return BOLD+"Darkling"+NORM;
}
else{
return;
 }
}

init(){
::init();
add_action("stop_exit", "north", 1);
add_action("stop_exit", "west", 1);
}

stop_exit(){
write("The Darkling flies down to block you!\n");
return 1;
}

heart_beat(){
 ::heart_beat();

if(attacker_ob) enemy = attacker_ob;

if(enemy && !attacker_ob){
 if(environment(enemy) == environment()){ 
    tell_room(environment(),
    "The Darkling rushes out of the dark and attacks!\n");
    attack_object(enemy);
    }
  }
}