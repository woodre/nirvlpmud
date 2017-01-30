#include "defs.h"

status main(string str, int glevel) {
  status muffled;

  if(!str) {
    write("Usage: muffles <on/off>\n");
    return 1;
  }

  muffled = (status)present(MGOB_ID, this_player())->query_muffle();

  if(str == "on") {
    if(muffled == 1) {
      write("You already have your muffles on.\n");
      return 1;
    } 
    command("mtalk off", this_player());
    return 1;
  }
  if(str == "off") {
    if(muffled == 0) {
      write("Your muffles are not on.\n");
      return 1;
    } 
    command("mtalk on", this_player());
    return 1;
  }
}
