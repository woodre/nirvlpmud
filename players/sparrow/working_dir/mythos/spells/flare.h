#include "/players/mythos/closed/guild/def.h"
/*  In exchange for -20-rand(60) damage i ask for 30sp and target wc +  2 - 5
 *  instead of the usual 70sp                 -mythos           */
flare(str) {
object ob;
string name;
if(qtf < 5) { write("Your control over fae is not enough!\n"); return 1;}
if(tsp < 30) { write("You do not have enough energy!\n"); return 1;}
if(scrp < 1000) { write("The darkness calls for a sacrifice.\n"); return 1;}
if(!str) {
  if(tp->query_attack()) { 
  ob = tp->query_attack(); 
  name = ob->query_name();}
  else { write("Who do you wish to flare\n"); return 1;}
}
if(str) {
  name = str;
  ob = present(name,environment(tp)); }
if(!ob) { write(capitalize(name)+" is not here!\n"); return 1;}
if(environment(ob) != environment(tp)) { write(capitalize(name)+" is not here.\n"); tp->hit_player(random(30)); return 1; }
if(ob == tp || ob->is_pet() || ob->is_kid()) {
  tp->heal_self(-100);
  write("What are you doing?\n");
return 1; }
if(ob->is_player() && !dpp) {
  write("You may not use this on a player at this time!\n"); return 1;}
ob->set_wc(ob->query_wc() + 2 + random(4));
if(!(ob->query_attack())) { ob->attack_object(tp); }
ob->heal_self(-20-(random(60)));
tp->add_spell_point(-30);
pp->add_sacrifice(-1000);
tell_room(environment(tp),"\nSuddenly, "+BLU+"COLD FIRE"+NORM+" lashes out from\n"+
          capitalize(tpn)+" and strikes "+capitalize(name)+"!\n\n");
return 1;}
