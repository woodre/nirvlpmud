#include "../DEFS.h"
#include DEFS_ENHANCEMENTS

void stop(mixed jumble);

status main(string str) {
  /* light spell enhancement */
  string name;
  mixed jumble;

  if(!((status)IPTP->item_flash()) && !IPTP->guild_wiz()) return 0;
  if((status)IPTP->query_light_on()) {
    write("You shut down your inner flourescent light.\n");
    IPTP->do_light(-2); IPTP->set_light_on(0);
    return 1; }
  if(!gotsp(TP, ENERGY_GLIMMER)) return 1;
  write("Glowing liquid courses through your veins.\n"+
        "Your body glows with an inner flourescent light.\n");
  say("Glowing liquid courses through "+TPN+"'s veins.\n"+
      TPN+"'s body glows with an inner flourescent light.\n");
  IPTP->do_light(2);
  IPTP->set_light_on(1);
  TP->add_spell_point(-ENERGY_GLIMMER);
  return 1;
}


void stop(mixed jumble) {
  string name;
  object ob;  
  int time;   
  sscanf(jumble, "%s %d", name, time);
  ob = find_player(name);
  time -= 1;
  if(time > 0) {
     jumble = name+" "+time;
     call_out("stop", 1, jumble);
     return; 
  }
  tell_object(ob, "Your bodily glow fades away.\n");
  tell_object(environment(ob), OPN+"'s bodily glow fades.\n"+   
    "The room light dims.\n");   
  IPTP->do_light(-1);
  IPTP->set_light_on(0);
  return;
}
