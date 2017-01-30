#include "/bin/ghost.c"
 
#pragma strict_types
#pragma save_types
 
int cmd_mchuckle() {
  if(ghost())
    return 0;
  write("You chuckle merrily.\n");
  say(this_player()->query_name()+" chuckles merrily.\n");
  return 1;
}
