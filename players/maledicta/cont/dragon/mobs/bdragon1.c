#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";

int bdelay;

reset(arg)  {

  ::reset(arg);
  if(arg) return;
bdelay = 0;
set_name("dragon");
set_alt_name("cont_dragon");
set_race("dragon");
set_short(HIB+"Blue "+NORM+BLU+"Dragon"+NORM+" [adult]");
set_long(
"   This is a huge adult blue dragon. It is extremely long\n"+
"and has a considerable wingspan.  Its head is decorated by\n"+
"long white horns which fade into a deep shade of blue at the\n"+
"tips. Its maw is long and narrow with hundreds of small\n"+
"sharp teeth as well as two long sets of fangs at the front.\n"+
"Its white eyes stare menacingly at you.\n");
set_level(20);
set_hp(650);
set_al(-1000);
set_aggressive(1);
set_wc(35);
set_ac(15);
set_heart_beat(1);
}

init(){
::init();
add_action("exit_block", "north", 1);
add_action("exit_block", "east", 1);
}

exit_block(){
write("The Blue Dragon steps to intercept you!\n");
return 1;
}

heart_beat(){
::heart_beat();

if(!bdelay && random(100) < 50 && attacker_ob){
tell_room(environment(),
"The "+HIB+"Blue "+NORM+BLU+"Dragon"+NORM+" sucks in a deep breath and...\n\n\n"+
"                "+HIY+"B O O M"+NORM+"\n\n"+
"Discharges a bright flash of lightning from its huge maw!\n");
attacker_ob->hit_player(random(40) + 10);
bdelay = 3;
}
else if(attacker_ob){
bdelay -= 1;
if(bdelay < 0) bdelay = 0;
}

if(bdelay && attacker_ob){
if(random(100) < 70 && attacker_ob){
tell_room(environment(),
"The "+HIB+"Blue "+NORM+BLU+"Dragon"+NORM+" Slashes its opponent with its gleaming claws!\n",
({ attacker_ob }));
tell_object(attacker_ob,
"You feel a terrible pain as the Dragon tears into you with its claws!\n");
attacker_ob->hit_player(20);
}
else if(attacker_ob){
tell_object(attacker_ob,
"You barely dodge the long claws of the Dragon!\n");
}
}
if(alt_attacker_ob && random(100) < 30){
tell_object(alt_attacker_ob,
"You are "+HIR+"SLAMMED"+NORM+" by the long tail of the Dragon!\n");
alt_attacker_ob->hit_player(15);
tell_room(environment(),
"The dragon's tail lashes out and strikes "+alt_attacker_ob->query_name()+"!\n");
}

}

