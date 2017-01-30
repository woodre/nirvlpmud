#include "/bin/ghost.c"
 
#pragma strict_types
#pragma save_types
 
int cmd_need() {
  if(ghost())
    return 0;
  write("You seem in desperate need of affection!!!\n");
  say(this_player()->query_name()+" seems in desperate need of affection!!!\n");
  return 1;
}
