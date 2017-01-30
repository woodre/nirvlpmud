#include "../DEFS.h"

status main(string str) {
  if((string)TP->query_home() == "/room/church.c" ||
     (string)TP->query_home() == "room/church.c"  ||
     (string)TP->query_home() == "/room/church"   ||
     (string)TP->query_home() == "room/church"    ) {
    call_other(TP, "set_home", LOGIN);
    TP->save_me();
    write("You will now start in Guild Hall.\n");
    return 1; 
  }
  write("You will now start in the Church.\n");
  call_other(TP, "set_home", "/room/church.c");
  TP->save_me();
  return 1;
}
