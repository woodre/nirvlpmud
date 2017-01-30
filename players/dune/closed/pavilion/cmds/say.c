#include "../DEFS.h"
  
status main(string str) {
  /* allows pilot to say things to the room */
  if(!str) {
    write("What do you say?\n");
    return 1;
  }
  tell_room(ROOM, "A voice from "+capitalize((string)ETP->query_myname())+
    "'s speaker says: "+str+"\n");
  return 1;
} 
