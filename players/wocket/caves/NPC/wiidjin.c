#include "/players/wocket/closed/ansi.h"
inherit "/obj/monster.c";

reset(arg){
::reset(arg);
  if(arg) return;
set_name("wiidjin");
set_race("nightmare");
set_short("A wiidjin");
set_long("You stare at a wirlwind of dust.  Spiraling at a rate that almost gives it a\n"+
    "solid form.  Flashes of two swords appear though the dust and smoke, whirling at\n"+
    "dangerous speeds.  The wiidjin just floats there waiting for anyone brave enough\n"+
    "to challenge its speed.\n");
set_level(20);
set_wc(40);
set_ac(9);
set_hp(400);
/* multi attacks */
wc_bonus += 40;
/* autoatttack */
ac_bonus += 4;
set_aggressive(1);
add_money(3000+random(3000));
}

init(){
::init();
#ifndef __LDMUD__
   add_action("attackme");add_xverb("");

#else
   add_action("attackme","", 3);

#endif
}

attackme(){
if(!attacker_ob && random(10) == 1){
if(this_player()->is_player()){
  tell_object(this_player(),"Wiidjin notices you and attacks.\n");
attacker_ob = this_player();
}
}
return 0;
}

heart_beat(){
object invenv;
int i,size,found;
::heart_beat();
 if(!environment()) return set_heart_beat(0);
if(attacker_ob && present(attacker_ob, environment(this_object()))){
size = sizeof(invenv);
already_fight = 0;
tell_object(attacker_ob,"A whirl wind of blades swing from the wiidjin slashing at you.\n");
say("Wiidjin swings it's swords at "+attacker_ob->query_name()+".\n",attacker_ob);
this_object()->attack(attacker_ob);
  }
}


