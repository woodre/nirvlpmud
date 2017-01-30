#include "../DEFS.h"

status main(string str) {
/* Guild channel muffle */
  int muff;
  muff = (status)IPTP->muffled();
  if(!str) {
    write("Usage: line <on/off>\n");
    return 1;
  }
  if(str == "off") {
    if(muff == 1) {
       write("You already are muffled.\n");
       return 1;
    }
    else muff = 1;
    write("You are now muffled.\n");
    IPTP->set_muffle(muff);
      call_other(CHANNELD,"resetchannel");
    return 1;
  }
  if(str == "on") {
    if(muff == 0) {
      write(" You were not muffled.\n");
      return 1;
    }
    else muff = 0;
    write("You are now on the CyberNet.\n");
    IPTP->set_muffle(muff);
      call_other(CHANNELD,"resetchannel");
    return 1;
  }
  return 1;
}

