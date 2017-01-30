#include "../DEFS.h"

status main(string str) {
  string fight, myarea;
  object myenv;
  fight = (string)TP->query_fight_area();
  myenv = environment(TP);
  myarea = file_name(myenv);
  if(fight && fight == myarea) {
    write(RED+"You are in a pk area.\n"+OFF); return 1; }
  write(BLUE+"You are not in a pk area.\n"+OFF);
   return 1;
}
