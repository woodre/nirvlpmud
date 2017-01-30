#include "/players/pestilence/ansi.h"
inherit "/players/vertebraker/closed/std/monster";
#define TP this_player()
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
  set_heal(5,3);
  add_money(0);
  set_wc_bonus(8);
  set_aggressive(1);
  set_dead_ob(this_object());
  set_al(-700);
  set_assist("/players/pestilence/amity/mob/sant.c", 5, 1, 3);
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
add_action("stop","north");
add_action("stop","south");
}
stop() {
if(TP->query_ghost() == 1) { return 0; }
else{
write("Guard ant pushes you to the ground, not allowing you to leave.\n");
return 1; }
}


heart_beat(){
int z;
::heart_beat();

if(attacker_ob && present(attacker_ob,environment(this_object()))){
z = random(10);
if(z>8){
   tell_room(environment(this_object()), 
  ""+HIR+"Guard ant tears into some flesh, splattering blood everywhere"+NORM+".\n");
  tell_object(attacker_ob,
  ""+HIR+"Guard ant tears into your flesh, splattering blood everywhere"+NORM+".\n");
    attacker->hit_player(random(80));
     }
}
}

monster_died() {
  move_object(clone_object("/players/pestilence/amity/obj/antennae2.c"),
      environment(this_object()));
  tell_room(environment(this_object()),
        "As the ant hits the floor, his antennae falls from his head.\n");
return 0; }
