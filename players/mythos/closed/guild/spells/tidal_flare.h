#include "/players/mythos/closed/guild/def.h"
tidal_flare() {
string msg;
object here;
int n, x;
if(pp->query_tides() > 1 && pp->query_tides() < 5) {
   write("The tides arent strong enough at this time.\n");
return 1;}
if(qtf < 5) { write("Your control over fae is not enough!\n"); return 1;}
if(scrp < 100) { write("The darkness calls for a sacrifice.\n"); return 1;}
if(tsp < 50) { write("You do not have enough energy!\n"); return 1;}
here = all_inventory(environment(tp));
  write("Tidal Fae flares and you see truth!\n");
  for(n=0; n<sizeof(here); n++) {
    x = 0;
    if(!(living(here[n]) && !(here[n]->query_npc()) && 
          (here[n]->query_level() > 30) && (here[n]->query_invis() > 20))) {
      if(here[n]->query_real_name() && x == 0) {
           msg = here[n]->query_real_name(); 
           x = 1;}
      if(here[n]->query_name() && x == 0) {
           msg = here[n]->query_name(); 
           x = 1;}
      if(here[n]->query_id() && x == 0) {
           msg = here[n]->query_id(); 
           x = 1;}
      if(here[n]->short() && x == 0) {
           msg = here[n]->short(); 
           x = 1;}
      if(x == 0) { msg = "**something**"; 
           x = 1;}
      write("\t"+msg+"\n");
      }
  }
  write("done\n");
tp->add_spell_point(-50);
pp->add_sacrifice(-100);
return 1;}
