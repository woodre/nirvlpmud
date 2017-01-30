#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";

int bdelay;

reset(arg)  {

  ::reset(arg);
  if(arg) return;
bdelay = 0;
set_name("dragon");
set_alias("galentara");
set_alt_name("king");
set_race("dragon");
set_short(BOLD+"Galentara, King of the "+HIB+"Blue "+NORM+BLU+"Dragons"+NORM+"");
set_long(
"  This is a very large and powerful dragon. You feel instant fear\n"+
"just by laying eyes upon it. Its front paws are huge and have\n"+
"claws the size of longswords. Its maw is filled with razor sharp\n"+
"teeth that can easily tear a cow in half with a single bite. The\n"+
"Dragons wings are so wide they block out most of the view before\n"+
"you.  You aren't sure if you have the power to even hurt this great\n"+
"being.\n");
set_level(22);
set_hp(2000);
set_al(0);
set_wc(45);
set_ac(25);
set_heart_beat(1);
set_dead_ob(this_object());
}


heart_beat(){
int rnum;

::heart_beat();

rnum = random(100);

if(!bdelay && random(100) < 60 && attacker_ob){
tell_room(environment(),
"The "+HIB+"Blue "+NORM+BLU+"Dragon"+NORM+" sucks in a deep breath and...\n\n\n"+
"                "+HIY+"B O O M"+NORM+"\n\n"+
"Discharges a bright flash of lightning from its huge maw!\n");
attacker_ob->hit_player(random(70) + 20);
bdelay = 3;
}
else if(attacker_ob){
bdelay -= 1;
if(bdelay < 0) bdelay = 0;
}

if(bdelay && attacker_ob){
if(random(100) < 70){
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
if(rnum > 70){
if(alt_attacker_ob && random(100) < 30){
tell_object(alt_attacker_ob,
"You are "+HIR+"SLAMMED"+NORM+" by the long tail of the Dragon!\n");
alt_attacker_ob->hit_player(35);
tell_room(environment(),
"The dragon's tail lashes out and strikes "+alt_attacker_ob->query_name()+"!\n");
}
}
}
else if(rnum < 20){
if(hit_point < 100 && attacker_ob){
tell_room(environment(),
HIR+"The Ancient Dragon goes into a mad rage as its life blood flows freely...\n"+
"It unleashes a mad torrent of claws and bites at its opponent!"+NORM+"\n");
attacker_ob->hit_player(random(25));
}
}
}


monster_died(){
tell_room(environment(),
""+HIB+"The Ancient Dragon dies..."+NORM+"\n");
attacker_ob->add_exp(4000);
return 1;
}