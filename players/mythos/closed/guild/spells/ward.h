#include "/players/mythos/closed/guild/def.h"
ward(str) {
object ob;
string dir;
int n;
n = 0;
if(!str) { n=1;} 
else { dir = str;}
if(qtf < 5) { write("Your control over fae is not enough!\n"); return 1;}
if(tsp < 50) { write("You do not have enough energy!\n"); return 1;}
if(scrp < 3000) { write("The darkness calls for a sacrifice.\n"); return 1;}
ob = clone_object("/players/mythos/closed/guild/spells/ward.c");
ob->set_time(qtf);
ob->set_din(n);
if(!n) {
ob->set_dir(dir); }
move_object(ob,environment(tp));
tp->add_spell_point(-50);
pp->add_sacrifice(-3000);
write("You ward the room.\n");
say(capitalize(tpn)+" mutter something....\n");
tell_room(environment(tp),"Suddenly.....\n"+BOLD+"DARKNESS shrouds the room....\n"+NORM);
return 1;}
