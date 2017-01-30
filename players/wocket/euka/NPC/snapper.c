#include "/players/wocket/closed/ansi.h"
inherit "/obj/monster.c";

reset(arg){
::reset(arg);
  if(arg) return;
set_name("vines");
set_short(RED+"Snapper vines"+OFF);
set_long();
set_level(20);
set_wc(15);
set_ac(9);
set_hp(400);
set_aggressive(1);
}

init(){
::init();
#ifndef __LDMUD__
  add_action("attackme"); add_xverb("");
#else
  add_action("attackme", "", 3);
#endif
}

attackme(){
if(!attacker_ob && random(10) == 1){
  tell_object(this_player(),"The snapper vine notices you and attacks.\n");
attacker_ob = this_player();
}
return 0;
}

heart_beat(){
object invenv;
int i,a,size,found;
  ::heart_beat();
  if(attacker_ob && present(attacker_ob, environment(this_object()))){
    size = sizeof(invenv);
    for(i=0,a=random(4);i<a;i++){
      already_fight = 0;
      say("Another plant tentacle lashes out.\n");
      this_object()->attack(attacker_ob);
    }
  }
}

