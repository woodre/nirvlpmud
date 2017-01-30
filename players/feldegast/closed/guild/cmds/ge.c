#include "/players/feldegast/closed/guild/defines.h"
do_command(str) {
  if(!str) {
    write("Usage: ge <string>\n");
    return 1;
  }
  CHANNEL->broadcast(TPN+" "+str);
  return 1;
}
