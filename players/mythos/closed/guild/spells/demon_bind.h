#include "/players/mythos/closed/guild/def.h"
demon_bind(str) {
object ob;
int num, bef;
if(!str) { write("How many spell points do you wish to use?\n"); return 1;}
if(qtf < 10) { write("Your control over fae is not enough!\n"); return 1;}
if(scrp < 300) { write("The darkness calls for a sacrifice.\n"); return 1;}
if(!present("mirror",tp)) { write("You do not have the right material!\n"); return 1;}
if(sscanf(str,"%d",num) != 1) { write("What?\n"); return 1;}
if(tp->query_sp() < num) { write("You do not have that much energy!\n"); return 1;}
if(num < 1) { write("You can not do that.\n"); return 1; }
tp->add_spell_point(-num);
pp->add_sacrifice(-300);
write("You pour energy into the mirror.\n");
say(capitalize(tpn)+" pours energy into the mirror!\n");
if(!present("count",tp)) {
ob = clone_object("/players/mythos/closed/guild/spells/count.c");
ob->set_count(num);
move_object(ob,tp); }
else {
bef = present("count",tp)->query_count();
present("count",tp)->set_count(bef + num);
if(present("count",tp)->query_count() > 666) {
destruct(present("count",tp));
move_object(clone_object("/players/mythos/closed/guild/spells/b_ring.c"),tp);
destruct(present("mirror",tp));
write("A black ring appears in your hands!\n");
pp->set_dring(1);
command("dsave",tp);
command("uu",tp);
} }
return 1;}
