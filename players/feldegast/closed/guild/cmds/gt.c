#include "/players/feldegast/closed/guild/defines.h"
do_command(str) {
  if(!str) {
    write("Usage: gt <string>\n");
    return 1;
  }
  CHANNEL->broadcast(TPN+" says: "+str);
  return 1;
}
