#include "../DEFS.h"

status main(string str) {
  /* allows ninja to lower spam seen by him/her */
  object wepobj;
  status spam;
  if( !(wepobj = present(WEAPON_ID, TP)) ) {
    write("No guild weapon is in your inventory.\n");
    return 1;
  }
  spam = (status)wepobj->query_spam();
  if(!spam) spam = 1;
  else      spam = 0;
  if(spam == 0)
    write("You toggle your weapon spam to HIGH.\n");
  if(spam == 1)
    write("You toggle your weapon spam to LOW.\n");
  wepobj->set_spam(spam);
  return 1;
}