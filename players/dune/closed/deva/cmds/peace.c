/*
 * PEACE command for Ascension
 * stop fights within the room
 * Original code from Polymorphs, altered for Templars & Devas. 
 * 
 */
#include "../def.h"
#define  COST 20

status main() {
  object ob;

  needsp(COST);
  ob = first_inventory(environment(TP));
  while(ob) {
    object oc;
    oc = ob;
    ob = next_inventory(ob);
    tell_object(oc, "An overwhelming power of good enforces calm.\n");
    oc->attack_object(); oc->attack_object();
    oc->stop_fight();    oc->stop_fight();
    oc->stop_hunter();   oc->stop_hunter(); 
    }
  
  write("Your power calms all those around you.\n");
  say(TPN+" dispels all aggression.\n");
  say("You feel at peace.\n");
  this_player()->add_spell_point(-COST);
  return 1;
}
