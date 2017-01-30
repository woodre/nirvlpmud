/* reshuffled Path names [6.6.01] - verte */

#define MAX_CONFIGS 4
#include "/players/feldegast/defines.h"
#define PATH "/players/feldegast/darkcity/"

int config;

reset(arg) {
  if(arg) return;
  restore_object("players/feldegast/darkcity/matrix");
}
int query_config() {
  return config;
}

void set_city_config(int arg) {
  string *rooms;
  string junk;
  string tmp;
  int size,i;

  config=arg;
  rooms=get_dir(PATH);
  size=sizeof(rooms);
  for(i=0; i<size; i++) {
    if(sscanf(rooms[i],"street%s.c",tmp)==1) {
      tell_room(PATH+rooms[i],"\n"+
"Dark City twists and writhes like a living being as the buildings\n\
surrounding you shrivel and grow like urban flowers.\n\n");
      call_other(PATH+rooms[i],"set_config",arg);
    }
  }
  save_object("players/feldegast/darkcity/matrix");
}
