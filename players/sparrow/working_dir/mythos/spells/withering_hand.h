#include "/players/mythos/closed/guild/def.h"

withering_hand(str) {
object ob,ob2;
string name;
if(qtf < 15) { write("Your control over fae is not enough!\n"); return 1;}
if(tsp < 120) { write("You do not have enough energy!\n"); return 1;}
if(scrp < 1200) { write("The darkness calls for a sacrifice.\n"); return 1;}
if(!str) {
  if(tp->query_attack()) { 
  ob = tp->query_attack(); 
  name = ob->query_name();}
  else { write("Who do you wish to wither?\n"); return 1;}
}
if(str) {
  name = str;
  ob = present(name,environment(tp)); }
if(!ob) { write(capitalize(name)+" is not here!\n"); return 1;}
if(!(ob->query_npc()) && !(ob->id("masakado")) && !(ob->id("amoril"))) {
  write("You may not use this on a player!\n"); return 1;}
ob2=clone_object("/players/mythos/closed/guild/spells/wither.c");
ob2->start_heal_shadow(ob);
ob->set_wc(ob->query_wc() + 7 + random(8));
move_object(clone_object("/players/mythos/closed/guild/spells/adds.c"),ob);
tp->add_spell_point(-120);
pp->add_sacrifice(-1200);
tp->lower_attrib();
tp->lower_attrib();
tell_room(environment(tp),capitalize(tpn)+" steps forward and touches "+
            capitalize(ob->query_name())+" lightly.\n"+
            "A "+BOLD+"Dark"+NORM+" mist seeps into "+capitalize(ob->query_name())+
            "!\n"+capitalize(ob->query_name())+" screams in great agony!\n"+
            "You realize that the fabric of reality has changed!\n");
write("The fae has a greater hold on the monster!\n"+
     "And the wounds of the monster made by Fae will do more!\n");
tell_room(environment(tp),capitalize(ob->query_name())+" flies into a rage!\n");
if(!(ob->query_attack())) { ob->attack_object(tp); }
else { if(ob->query_attack() != tp) ob->attack_object(tp); }
return 1;}
