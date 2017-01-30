#include "/players/mythos/closed/guild/def.h"

replicate(str) {
object dup, dup2, dupp;
string name, name2;
if(qtf < 15) { write("Your control over fae is not enough!\n"); return 1;}
if(tsp < 150) { write("You do not have enough energy!\n"); return 1;}
if(scrp < 2000) { write("The darkness calls for a sacrifice.\n"); return 1;}
if(!str) {
  write("Usage: replicate <name>\n");
  return 1;
}
if(sscanf(str,"%s",name) != 1) return 0;
dup = present(name,environment(tp));
if(!dup) { write(capitalize(name)+" is not here.\n"); return 1;}
if(!living(dup) || (dup->is_player() && !(dup->id("jinro")) ) ) {
   write("That may not be replicated.\n");
return 1;}
if(dup->query_level() > 19 || dup->is_pet() || dup->is_kid()) {
 write("You may not replicate that monster!\n"); return 1;}
tp->add_spell_point(-150);
pp->add_sacrifice(-2000);
if(present("duplicator",dup)) {
  write("You may not replicate a replicant!\n");
  tp->heal_self(-1 - random(50));
return 1;}
sscanf(object_name(dup),"%s#%s",name2);
if(name2 == "obj/monster") {
  write("You may not replicate that.\n");
return 1; }
dup2 = clone_object("/"+name2+".c");
dup2->set_name("replicant of "+dup->query_name());
dup2->set_alias("replicant of"+name);
dup2->set_alt_name("replicant");
dup2->set_short(RED+"<REPLICANT> "+NORM+dup->short());
move_object(dup2,environment(tp));
dupp = clone_object("/players/mythos/closed/guild/spells/duplicator2.c");
dupp->set_name(name);
dupp->set_own(tp);
move_object(dupp,dup2);
write("Embracing the fae you concentrate.\n");
write("Pain shoots up your arms as the blood within is fed to the fae!\n");
tp->add_hit_point(-1-random(20));
tell_room(environment(tp),
  "Suddenly "+capitalize(name)+" is swallowed up by a "+BOLD+"BLOT"+NORM+
   "of darkness!\n"+
  "When the dark shadow disappears there are two "+capitalize(name)+"s!\n");
dup2->attack_object(dup);
return 1;}
