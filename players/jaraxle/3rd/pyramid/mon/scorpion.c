#include "/players/jaraxle/define.h"
inherit "/players/vertebraker/closed/std/monster.c";

reset(arg)  {
     ::reset(arg);
  if(arg) return;

set_name("scorpion");
set_alias("scorpion");
set_race("creature");
set_short("Scorpion");
set_long("A deadly scorpion about the size of a grown human, mans hand.\n"+
    "It has a pair of enormous pinchers and an extrodinarilly long tail.\n");

set_level(1);
set_aggro(1, 50, 100);
set_hp(45+random(6));
set_al(-1000+random(1001));
set_wc(10+random(6));
set_ac(0);
set_aggressive(1);
set_chat_chance(20);
load_chat("The scorpion snaps its claws.\n");
set_dead_ob(this_object());

}

monster_died() {
  tell_room(environment(this_object()),
     "The scorpion writhes on the floor, dead.\n");
return 0; }
init(){
    ::init();
  add_action("climb","climb");
}
climb(arg){
write("The scorpion blocks your exit!\n");
return 1; }
