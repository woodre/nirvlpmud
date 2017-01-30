#include "/bin/posessive.c"
#include "/bin/ghost.c"
 
#pragma strict_types
#pragma save_types
 
int cmd_llick() {
  if(ghost())
    return 0;
  write("You lick your lips, leaving them slightly moist.\n");
  say(this_player()->query_name()+" licks "+posessive()+
      " lips leaving them slightly moist.\n");
  return 1;
}
