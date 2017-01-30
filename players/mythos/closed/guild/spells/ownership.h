#include "/players/mythos/closed/guild/def.h"

ownership(str) {
object dup, owns;
string name;
if(qtf < 5) { write("Your control over fae is not enough!\n"); return 1;}
if(tsp < 10) { write("You do not have enough energy!\n"); return 1;}
if(scrp < 20) { write("The darkness calls for a sacrifice.\n"); return 1;}
if(!str) {
  write("Usage: ownership <object name>\n");
  return 1;
}
if(sscanf(str,"%s",name) != 1) return 0;
dup = present(name,tp);
if(!dup) { write("You do not have "+name+".\n"); return 1;}
if(dup->id("lgoop") || dup->id("lblast")) { write("That may not be owned.\n"); return 1; }
if((dup->drop()) || dup->query_auto_load()  || living(dup) ||
   !(dup->query_weight()) || !(dup->query_value())) {
   write("You may not place an ownership on that.\n");
return 1;}
if(present("owned",dup)) {
  write("That object already has an ownership on it!\n");
return 1;}
owns = clone_object("/players/mythos/closed/guild/spells/own.c");
owns->set_owner(tpn);
owns->set_level(tgl);
move_object(owns,dup);
dup->set_value(0);
write("You scribe your sigil deep within the essence of the object!\n"+
      "You can no longer sell it at a store.\n");
say("The "+dup->short()+" seems to be cloaked in shadow as "+
     capitalize(tpn)+" lightly strokes it.\n");
tp->add_spell_point(-10);
pp->add_sacrifice(-20);
return 1;}
