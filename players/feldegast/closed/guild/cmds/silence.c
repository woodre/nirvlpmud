#include "/players/feldegast/closed/guild/defines.h"

do_command() {
  if(!MYOB->query_silence()) {
    write("Guild Channel: OFF\n");
    MYOB->set_silence(1);
  }
  else {
    write("Guild Channel: ON\n");
    MYOB->set_silence(0);
  }
  return 1;
}
