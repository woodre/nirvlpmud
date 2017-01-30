#include "/players/guilds/bards/def.h"

status main() {
  object *obs,ob,room;
  int x;

  if (spell(-100, 3, 20) == -1)
    return 0;
  room=environment(TP);
  obs = all_inventory(room);
  
  write("You raise your " + INST + " and play a soothing tune.\n"
       +"Your music fills the area, attempting to stop all fighting.\n");
  say(tp + " raises " + POSS(TP) + " " + INST 
    + " and plays a soothing tune.\n" 
    + POSS(TP) + "music fills the area.\n");

    
  for(x=0;x<sizeof(obs);x++) {
    ob=(object)obs[x]->query_attack();
    if(ob && obs[x] != TP) {
      if(present(ob,room)) {
        tell_object(obs[x],
          "You have a strong urge to stop fighting and listen to " + tp + ".\n");
        tell_room(room,
          NAME(obs[x])+" stops fighting.\n",
          ({obs[x]}));
      } else {
        tell_object(obs[x],
          "The soothing tune erases all thoughts of fighting from your mind.\n");
      }
    }
    obs[x]->stop_fight();
    obs[x]->stop_fight();
    obs[x]->stop_hunter();
    obs[x]->stop_hunted();
  }
  call_other(TP, "add_spell_point", -20);
  return 1;
}
