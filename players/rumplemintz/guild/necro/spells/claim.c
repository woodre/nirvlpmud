#include "../defs.h"

cmd(str) {
  if(!str){
    notify_fail("What would you like to claim?\n");
    return 0;
  }
  if(str != "dagger"){
    notify_fail("That is not something you can claim.\n");
    return 0;
  }
  if(tp->query_sp() < 50) { 
    write("You do not have the availble magic.\n"); 
    return 1; 
  }
  if(present(TOOL_ID,tp)){
    write("You have already got one.\n");
    return 1;
  }
  write("You whisper dark words calling the realm of the dead.\n");
  write("The room darkens.\n");
  say("The room darkens.\n");
  call_out("get_dagger",3,tp);
  return 1;
}

get_dagger(arg){
  tell_object(arg,"\n"+
        ROD+BOLD+BLK+"The room darkens as a swirl of purple mist surrounds your\n"+
        "      "+"hand.  As the mist dissipates a gleaming dagger is left in its\n"+
        "      "+"place."+OFF+"  You have claimed a dagger to help in your dark deeds.\n->>");
  arg->add_spell_point(-50);
  move_object(clone_object(OBJ+"/wep/harvester.c"),arg);
  arg->remote_say("Darkness swirls around the hand of "+arg->query_name()+" and a dagger forms.\n");
}
