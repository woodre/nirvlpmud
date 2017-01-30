#include "/players/mythos/closed/guild/def.h"
/*  In exchange for -30-rand(40) damage i ask for 20sp and 10 hp
 *  instead of the usual 100sp                 -mythos           */
dblood(str) {
object ob;
string name;
if(qtf < 3) { write("Your control over fae is not enough!\n"); return 1;}
if(tsp < 20) { write("You do not have enough energy!\n"); return 1;}
if(scrp < 5000) { write("The darkness calls for a sacrifice.\n"); return 1;}
if(!str) {
  if(tp->query_attack()) { 
  ob = tp->query_attack(); 
  name = ob->query_name();}
  else { write("Who do you wish to wound?\n"); return 1;}
}
if(str) {
  name = str;
  ob = present(name,environment(tp)); }
if(!ob) { write(capitalize(name)+" is not here!\n"); return 1;}
if(environment(ob) != environment(tp)) { write(capitalize(name)+" is not here!\n"); tp->hit_player(random(30)); return 1; }
if(!(ob->query_npc()) && !dpp) {
  write("You may not use this on a player at this time!\n"); return 1;}
tp->add_hit_point(-10);
pp->add_sacrifice(-1000);
tp->add_spell_point(-20);
tell_room(environment(tp),capitalize(tpn)+" takes out a sacrificial knife.\n"+
       capitalize(tpn)+" whispers some words, points at \n"+capitalize(name)+
       ", and drives the knife into the ground!\n");
tell_room(environment(tp),ob->short()+" screams and screams!\n");
if(!(ob->query_attack())) { ob->attack_object(tp); }
ob->heal_self(-30-(random(40)));
return 1;}
