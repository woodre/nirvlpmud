#include "/players/guilds/bards/def.h"

status main(){
  string current_home;
  current_home=(string)TP->query_home();
  if((int)TP->query_level() > 19) return 0;
  if(current_home == "/room/church" || current_home == 0 || current_home == "room/church" || current_home == "/room/church.c" || current_home == "room/church.c") {
    TP->set_home("/players/guilds/bards/bardrooms/common.c");
    write("Home now set to Bard Common Room.\n");
    return 1;
  } else if(current_home == "/players/guilds/bards/bardrooms/common.c") {
    TP->set_home("/room/church");
    write("Home now set to the Village Church.\n");
    return 1;
  } else {
    write("Your home isn't set to the Common Room or the Village Church.\n"+
          "You're probably in the middle of something; finish that first.\n"+
          "Otherwise, see a wizard.\n");
    return 1;
  }
}
