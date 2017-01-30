#define WAR "/players/maledicta/cont/daemon"
#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";

int bdelay;

reset(arg)  {

  ::reset(arg);
  if(arg) return;
bdelay = 0;
set_name("dragon");
set_alt_name("cont_mother");
set_race("dragon");
set_short(HIB+"Blue "+NORM+BLU+"Dragon"+NORM+" [Guardian Mother]");
set_long(
"   This is a large Blue Dragon which seems very aged and\n"+
"decrepit. Its wings seem to no longer function due to the\n"+
"fact that it has been here in this place for so long. Its\n"+
"claws, teeth, and powerful muscles speak of a dangerous\n"+
"creature nonetheless. You had best be careful.\n");
set_level(20);
set_hp(1000);
set_al(-1000);
set_wc(40);
set_ac(16);
set_heart_beat(1);
set_dead_ob(this_object());
}


heart_beat(){
::heart_beat();


if(random(100) < 70 && attacker_ob){
tell_room(environment(),
"The "+HIB+"Blue "+NORM+BLU+"Dragon"+NORM+" Slashes its opponent with its gleaming claws!\n",
({ attacker_ob }));
tell_object(attacker_ob,
"You feel a terrible pain as the Dragon tears into you with its claws!\n");
attacker_ob->hit_player(30);
}
else if(attacker_ob){
tell_object(attacker_ob,
"You barely dodge the long claws of the Dragon!\n");
}
if(alt_attacker_ob && random(100) < 30){
tell_object(alt_attacker_ob,
"You are "+HIR+"SLAMMED"+NORM+" by the long tail of the Dragon!\n");
alt_attacker_ob->hit_player(35);
tell_room(environment(),
"The dragon's tail lashes out and strikes "+alt_attacker_ob->query_name()+"!\n");
}

}


monster_died(){
tell_room(environment(),
""+HIB+"The Guardian Mother calls out, 'My Children!!!' and then dies..."+NORM+"\n");
return 1;
}