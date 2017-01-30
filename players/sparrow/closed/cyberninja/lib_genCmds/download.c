#include "../DEFS.h"

status main(string str) {
  write("Downloading data from CyberNinja Database...\n");
  if( !(previous_object()->restore_me()) )
    tell_object(TP, "Cyberlink error...\n");
  write("Ok.\n");
  return 1;
}
