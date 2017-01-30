#include "DEF.h"
 
attrib(str) {
string who,what;
int num;
  if(!str) {write("attrib <who> <what> <num> \n"); return 1; }
  sscanf(str,"%s %s %d",who,what,num);
  if(!find_player(who)) {write("not logged on... \n"); return 1; }
  find_player(who)->set_attrib(what,num);
write("You have set "+capitalize(who)+"'s "+what+" to "+num+".\n");
return 1;
}
