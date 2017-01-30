#include "../DEFS.h"

status main(string str) {
  write("Saving data to CyberNinja Database...\n");
  if( !(previous_object()->save_me()) )
    tell_object(TP, "Cyberlink error...\n");
  write("Ok.\n");
  return 1;
}
