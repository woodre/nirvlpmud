#include "../defs.h"

cmd(str) {
  if(!str){
    notify_fail("What would you like to conjure?\n");
    return 0;
  }
  if(str != "sword"){
    notify_fail("That is not something you can conjure.\n");
    return 0;
  }
  if(tp->query_sp() < 50) { 
    write("You do not have the availble magic.\n"); 
    return 1; 
  }
  if(present(bonecleaver,tp)){
    write("You have already got one.\n");
    return 1;
  }
  write("You whisper dark words calling the realm of the dead.\n");
  write("The room darkens.\n");
  say("The room darkens.\n");
  call_out("get_sword",3,tp);
  return 1;
}

get_sword(arg){
  tell_object(arg,"\n"+
        ROD+BOLD+BLK+"The room darkens as a swirl of purple mist surrounds your\n"+
        "      "+"hand.  As the mist dissipates a gleaming dagger is left in its\n"+
        "      "+"place."+OFF+"  You have conjured the necromantic sword of legend\n->>");
  arg->add_spell_point(-50);
  move_object(clone_object(/players/sami/closed/nsword.c"),arg);
  arg->remote_say("Darkness swirls around the hand of "+arg->query_name()+" and a sword forms.\n");
}