#include "/players/jenny/define.h"
main(str) { 
string name,where;
object targ; 
 if(!str) return 0;
 if(sscanf(str,"%s %s",name,where) != 2) return 0;
 targ = find_player(name);
 if(!targ) { write("Target not in play.\n"); return 1; }
 if(move_object(targ,where)) {
  write("You have moved "+name+" to "+where+"\n");
  tell_object(targ,"You have been moved to "+
                   environment(targ)->short()+" by "+
                   BOLD+RED+TPN+NORM+"\n");
 } else { write("ERROR: move not completed.\n"); }
return 1; }
