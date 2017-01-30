#include "/players/mythos/closed/guild/def.h"
mesmerize(str) {
int z;
object ob;
string name;
if(qtf < 1) { write("Your control over fae is not enough!\n"); return 1;}
if(scrp < 1000) { write("The darkness calls for a sacrifice.\n"); return 1;}
if(!str) {
if(tsp < 100) { write("You do not have enough energy!\n"); return 1;}
ob=all_inventory(environment(tp));
  for(z=0;z<sizeof(ob);z++) {
  if(living(ob[z])) {
    if(ob[z]->query_attack()) { (ob[z]->query_attack())->stop_fight();
    ob[z]->stop_fight(); } }
  }
  for(z=0;z<sizeof(ob);z++) {
  if(living(ob[z])) {
    if(ob[z]->query_attack()) { ob[z]->stop_fight(); } }
  }
tp->add_spell_point(-100);
pp->add_sacrifice(-1000);
write("You summon up power and force all to stop fighting.\n");
say("A Halt is called to the fighting by "+capitalize(tpn)+".\n");
return 1;}
if(tsp < 80) { write("You do not have enough energy!\n"); return 1;}
name = str;
if(!present(name,environment(tp))) { 
write(capitalize(name)+" is not here.\n"); return 1;}
if(!(present(name,environment(tp))->query_attack())) {
  write(capitalize(name)+" is not in combat.\n"); return 1;}
  ob=present(name,environment(tp));
  if(ob->is_player() && ob->query_level() > (tl - 1) && ob != tp) {
  write("You can not target mez on a player equal \n"+
         "to or higher than your level!\n");
  return 1;}
  (ob->query_attack())->stop_fight(); ob->stop_fight(); 
  (ob->query_attack())->stop_fight(); ob->stop_fight();
tp->add_spell_point(-80);
pp->add_sacrifice(-1000);
write("You gaze at "+capitalize(name)+".\n"+
       capitalize(ob->query_pronoun())+" is mesmerized by your gaze.\n");
tell_object(ob,capitalize(tpn)+" gazes at you....\n\n"+
            RED+"Sw"+NORM+BLU+"ir"+NORM+YEL+"ls "+NORM+"of "+HIR+"COLORS"+NORM+
            " seem to envelope you.\n\nYou are at peace....\n\n");
say(capitalize(name)+" is mesmerized by "+capitalize(tpn)+".\n");
return 1;}
