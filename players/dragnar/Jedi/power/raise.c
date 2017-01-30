#include "defs.h"

main(string str){
  if(!str){ write("raise what?\n"); return 1; }
  if(USER->query_attrib(str) >= 15){
    write("You must use skill points to raise your stats above 15.\n");
      return 1;
  }
}
