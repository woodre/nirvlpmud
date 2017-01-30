#include "/players/mythos/closed/guild/def.h"

remove_ownership(str) {
object dup, owns;
string name;
if(qtf < 5) { write("Your control over fae is not enough!\n"); return 1;}
if(tsp < 10) { write("You do not have enough energy!\n"); return 1;}
if(scrp < 20) { write("The darkness calls for a sacrifice.\n"); return 1;}
if(!str) {
  write("Usage: remove_ownership <object name>\n");
  return 1;
}
if(sscanf(str,"%s",name) != 1) return 0;
dup = present(name,tp);
if(!dup) { write("You do not have "+name+".\n"); return 1;}
if(!present("owned",dup)) {
  write("That object doesnt have an owership on it!\n");
return 1;}
if(present("owned",dup)->query_owner() != tpn && 
   tgl < present("owned",dup)->query_level()) {
  write("You are not the owner nor are you high enough!\n");
return 1;}
write("You release the bindings that are scribed deep within the object.\n");
say("The "+dup->short()+" glows slightly as "+capitalize(tpn)+" lightly strokes it.\n");
destruct(present("owned",dup));
tp->add_spell_point(-10);
pp->add_sacrifice(-20);
return 1;}
