#include "/players/mythos/closed/guild/def.h"
true_banish(str) {
object ob;
string type;
int num;
if(!str) { write("Usage: true_banish <type>\n"); return 1;}
if(qtf < 10) { write("Your control over fae is not enough!\n"); return 1;}
if(tsp < 70) { write("You do not have enough energy!\n"); return 1;}
if(scrp < 300) { write("The darkness calls for a sacrifice.\n"); return 1;}
type = str;
if(type != "demon" && type != "spirit" && type != "nightmare" && type != "daemon" &&
    type != "avatar" && type != "iezu") {
  write("You may only banish spirits, demons, nightmares, avatars, iezus, or daemons!\n");
  return 1;}
ob = first_inventory(environment(tp));
while(ob) {
if(call_other(ob,"id",type)) {
  num = ob->query_hp();
  if(num > qtf * 10) { write("The creature is still much to strong!\n");}
  else {
destruct(ob);
tp->add_spell_point(-70 - num/5);
pp->add_sacrifice(-300 - num);
tell_room(environment(tp),CYN+"\n             [xxxxxxxx  xx  X*X  xx  xxxxxxxx]\n\n"+NORM);
write("With a wave of a hand you banish the "+type+".\n");
say("A "+capitalize(type)+" is banished by "+capitalize(tpn)+".\n");
if(tsp < -qtf) {
tp->add_hit_point(-qtf*2);
write("You have over extended!  Your body is wracked with pain!\n");
say(capitalize(tpn)+" falls to the ground...  exhaustion and pain overcomes "+tp->query_pronoun()+"!\n");
} }
return 1;}
ob = next_inventory(ob);
}
return 1;}
