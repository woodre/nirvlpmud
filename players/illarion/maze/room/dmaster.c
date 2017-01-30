#include "/players/illarion/dfns.h"
#define CONTROLLER "/players/illarion/maze/room/vroomcon.c"
#define MAX_LEVEL 25

object *levels;

void reset(status arg) {
  if(arg) return;
  
  if(!levels || !sizeof(levels))
    levels=allocate(MAX_LEVEL);
}

void register_level(object level,int num) {
  levels[num-1]=level;
}

object query_level(int num) {
  return levels[num-1];
}

void destmaze() {
  int x;
  for(x=0;x<MAX_LEVEL;x++)
    if(levels[x])
      levels[x]->destruct_area();
}
