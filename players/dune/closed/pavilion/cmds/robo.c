#include "../DEFS.h"

status main(string str) {
  /* help files */
  string file;
  if(!str) {
    write(
      "\n"+
      "Welcome Pilot!\n"+
      "\n"+
      "     Here's all the information you'll need about\n"+
      "how to play, weapon/ammo stats, RoboMech physics,\n"+
      "and the utilities available for your use.\n"+
      "     You may get more detailed information by\n"+
      "typing 'robo <topic>' for each of these other topics.\n");
    ls("/players/dune/closed/pavilion/docs");
    return 1;
  }  
  file = "/players/dune/closed/pavilion/docs/"+str;
  if(file_size(file) >= 0) {
    cat(file);
    return 1;  
  }
  write("That file does not exist.\n");
  return 1;
}
