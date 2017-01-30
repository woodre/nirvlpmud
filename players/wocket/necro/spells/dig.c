#include "../defs.h"

cmd(str) {
object ob;

  ob = GOB;
  if(!GOB->checklev(3,7)) return 1;
  if(!str || str != "grave"){
    notify_fail("What would you like to dig?\n");
    return 0;
  }
  if(!present("shovel",tp)){
    notify_fail("You do not have a shovel to dig with.\n");
    return 0;
  }
  if(!(GRAVESITE)) {
    write("This needs to be done at a consecrated gravesite.\n");
    return 1;
  }
  if(present("grave_heal",environment(tp))) {
    write("There is already a grave dug here.\n");
    return 1;
  } 
  if(!present("corpse dust",tp)){
    write("You do not have any corpse dust to prepare the grave after it is dug.\n");
    return 1;
  }
  if(tp->query_hp() < 10){
    write("You are not healthy enough to dig.\n");
    return 1;
  }
  tp->add_hit_point(-10);
  write("With great effort you strike the dirt with your shovel and dig out a 6 foot deep\n"+
        "grave.  You then line the bottom of the grave with a dash of corpse dust energize\n"+
        "the grave.\n");
  write("As you whisper some arcane words the grave glows for a second and then fades.\n");
  say(tpn+" strikes the dirt with his shovel and digs out a 6 foot deep grave.\n");
  move_object(clone_object(OBJ+"/misc/grave_heal.c"),environment(tp));
  return 1;
}

