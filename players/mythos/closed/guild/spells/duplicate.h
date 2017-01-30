#include "/players/mythos/closed/guild/def.h"

duplicate(str) {
object dup, dup2;
string name, name2;
/*
write("Due to abuse this spell has been removed.\n");
write("at this rate you players will be reduced to having no powers.\n");
write("its up to you guys ..... - Mythos - 3-9-2000.\n");
return 1;
*/
if(qtf < 5) { write("Your control over fae is not enough!\n"); return 1;}
if(tsp < 60) { write("You do not have enough energy!\n"); return 1;}
/* THIS IS STOPGAP COST - CHANGE TO WHATEVER WORKS (was 1000) -Snow 3/00 */
if(scrp < 20000) { write("The darkness calls for a sacrifice.\n"); return 1;}
if(!str) {
  write("Usage: duplicate <object name>\n"+
        "Note: You may only duplicate a weapon or piece of armor once.\n");
  return 1;
}
if(sscanf(str,"%s",name) != 1) return 0;
dup = present(name,tp);
if(!dup) { write("You do not have "+name+".\n"); return 1;}
if(!(dup->armor_class()) && !(dup->weapon_class()) || (dup->drop()) ||
   dup->nondup() ||
   dup->query_auto_load()  || !(dup->query_weight()) || !(dup->query_value())) {
   write("That may not be duplicated.\n");
return 1;}
tp->add_spell_point(-60);
/* THIS IS STOPGAP COST - CHANGE TO WHATEVER WORKS (was 1000) -Snow 3/00 */
pp->add_sacrifice(-20000);
if(present("duplicator",dup)) {
  write("You may duplcate an object only once!\n"+
        capitalize(name)+" can not take the strain!\n"+
        "It shatters!\n");
  tp->add_weight(-(dup->query_weight()));
  destruct(dup);
  tp->heal_self(-1 - random(50));
return 1;}
sscanf(object_name(dup),"%s#%s",name2);
dup2 = clone_object("/"+name2+".c");
dup2->set_name("duplicate");
dup2->set_alias("copy");
dup2->set_alt_name("duplicate");
dup2->set_short(dup->short()+CYN+"  <duplicate>"+NORM);
if(dup->armor_class()) { dup2->set_ac(dup->armor_class() - 1); }
if(dup->weapon_class()) { dup2->set_class(dup->weapon_class() - 1); }
if(dup->query_value() > 1) {
dup2->set_value(dup->query_value() - random(2)); }
if(dup->query_value() > 10) {
dup2->set_value(dup->query_value() - random(10)); }
if(dup->query_value() > 1000) {
dup2->set_value(dup->query_value() - random(1000)); }
move_object(dup2,tp);
tp->add_weight(dup2->query_weight());
move_object(clone_object("/players/mythos/closed/guild/spells/duplicator.c"),dup);
move_object(clone_object("/players/mythos/closed/guild/spells/duplicator.c"),dup2);
write("The "+capitalize(name)+" glows as fae seeps into it.\n"+
      "Slowly the object divides into two and both halves form into wholes.\n");
return 1;}
