#include "/players/mythos/closed/guild/def.h"
dwhip(str) {
object ob;
string name;
if(qtf < 3) { write("Your control over fae is not enough!\n"); return 1;}
if(tsp < 25) { write("You do not have enough energy!\n"); return 1;}
if(scrp < 500) { write("The darkness calls for a sacrifice.\n"); return 1;}
if(!str) {
  if(tp->query_attack()) { 
  name = (tp->query_attack())->query_name();
  ob = tp->query_attack(); }
  else { write("Who do you wish to whip?\n"); return 1;}
}
if(str) {
  name = str;
  ob = present(name,environment(tp)); }
if(!ob) { write(capitalize(name)+" is not here!\n"); return 1;}
if(environment(ob) != environment(tp)) { write(capitalize(name)+" is not here.\n"); tp->hit_player(random(30)); return 1; }
if(!(ob->query_npc()) && !dpp) {
  write("You may not use this on a player at this time!\n"); return 1;}
tp->add_spell_point(-25);
pp->add_sacrifice(-250);
tell_room(environment(tp),capitalize(tpn)+" lashes out at "+capitalize(name)+" with a strand of "+
          BLU+"COLD FIRE"+NORM+"!\n");
tell_room(environment(tp),ob->short()+" screams in PAIN!\n");
if(!(ob->query_attack())) { ob->attack_object(tp); }
ob->heal_self(-random(50));
return 1;}
