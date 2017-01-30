#define MAXVAL 3000
duplicate(str) {
object dup, dup2;
string name, name2;
if(!str) {
  write("Usage: duplicate <object name>\n"+
        "Note: You may only duplicate an original item up to two times.\n");
  return 1;
}
if(sscanf(str,"%s",name) != 1) return 0;
dup = present(name,tp);
if(!dup) { write("You do not have "+name+".\n"); return 1;}
if((dup->drop()) || dup->query_auto_load()  ||
   !(dup->query_weight()) || !(dup->query_value())) {
   write("That may not be duplicated.\n");
return 1;}
if(dup->query_value() < MAXVAL || dup->armor_class() || dup->weapon_class()) {}
else { write("That may not be duplicated!\n"); return 1; }
if(present("duplicator",dup)) {
  if(present("duplicator",dup)->query_num() > 1) {
  write("You may duplicate only an original object and only two times!\n"+
        capitalize(name)+" can not take the strain!\n"+
        "It shatters!\n");
  tp->add_weight(-(dup->query_weight()));
  destruct(dup); 
  tp->hit_player(10000);
return 1;}
}
sscanf(object_name(dup),"%s#%s",name2);
dup2 = clone_object("/"+name2+".c");
dup2->set_name("duplicate");
dup2->set_alias("copy");
dup2->set_alt_name("duplicate");
dup2->set_short(dup->short()+RED+"  <copy>"+NORM);
dup2->set_weight(dup->query_weight() * 2);
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
if(present("duplicator",dup)) 
  present("duplicator",dup)->set_num(present("duplicator",dup)->query_num() + 1);
else {
 move_object(clone_object("/players/mythos/myth/crafter/spells/duplicator.c"),
  dup); present("duplicator",dup)->set_num(1); }
move_object(clone_object("/players/mythos/myth/crafter/spells/duplicator.c"),dup2);
present("duplicator",dup2)->set_num(69);
write("\n");
return 1;}