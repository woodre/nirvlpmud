#include "/players/mythos/closed/guild/def.h"
siphon(str) {
object ob;
int amount;
if(!str) { write("Usage: siphon <who>\n"+
                 "Only usable on other guild members\n"+
                 "unless in the guild hall.\n"); return 1;}
if(qtf < 1) { write("Your control over fae is not enough!\n"); return 1;}
if(thp < 20) { write("You do not have enough vitality!\n"); return 1;}
if(scrp < 50) { write("The darkness calls for a sacrifice.\n"); return 1;}
ob=present(str,environment(tp));
if(!ob || ob->query_ghost() || !living(ob)) { write("That person is not here.\n"); return 1;}
if(!present(fear,ob) && !dpp) { 
write("You may not use that on a non-guild member at this time.\n");
return 1;}
tp->add_hit_point(-20);
pp->add_sacrifice(-50);
amount = ob->query_sp();
tp->add_spell_point(amount);
ob->add_spell_point(-amount);
write("You siphon away the energy of "+capitalize(str)+" into yourself!\n"+
      "You feel PAIN as the energy races through you!\n");
tell_object(ob,"You feel a twisting- a warping- deep down inside you!\n"+
           "You feel weak- energy has been taken from you by "+capitalize(tpn)+"!\n");
return 1;}
