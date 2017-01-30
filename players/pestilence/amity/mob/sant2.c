#include "/players/pestilence/ansi.h"
inherit "/players/vertebraker/closed/std/monster";
#define TP this_player()
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Small Ant");
  set_alias("small ant");
  set_short("A small ant");
  set_long("This is a smaller ant, but still stands four feet tall.  It usually is summoned to\n"+
           "help the guard ants in warding off intruders.\n");
  set_race("ant");
  set_gender("creature");
  set_level(15);
  set_wc(20);
  set_ac(12);
  set_hp(250);
  add_money(0);
  set_aggressive(1);
  set_dead_ob(this_object());
  set_al(-800);
  load_chat("A small ant gnaws at your skin.\n");
  set_chat_chance(20);
  load_a_chat("A small ant bites you in the leg.\n");
  load_a_chat("A small ant circles you.\n");
  set_a_chat_chance(30);
  set_spell_mess2("A small ant lunges at your throat, just missing your jugular.\n");
  set_spell_mess1("A small ant leaps in an attack.\n");
  set_chance(35);
  set_spell_dam(random(20));
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
write("A small ant pushes you to the ground, not allowing you to leave.\n");
return 1; }
}
heart_beat(){
 object ob;
 object att;
 object next;
 if(!environment()) return;
 if(!attacker_ob)
 if(ob = present("ant", environment())) { if(ob->query_attack()) attack_object(ob->query_attack()); } ;
 ::heart_beat();

}
monster_died() {
  move_object(clone_object("/players/pestilence/amity/obj/antennae3.c"),
      environment(this_object()));
  tell_room(environment(this_object()),
        "As the ant hits the floor his antennae falls from it's head.\n");
return 0; }
