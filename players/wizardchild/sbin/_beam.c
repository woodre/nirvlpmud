#include "/bin/ghost.c"
 
#pragma strict_types
#pragma save_types
 
int cmd_beam() {
  if(ghost())
    return 0;
  write("You beam brightly with happiness!!!\n");
  say(this_player()->query_name()+" beams brightly with happiness!!! :)\n");
  return 1;
}
