#include "/players/jenny/define.h"
main(str) { 
string what,name;
object ob,targ;
ob = 0;
  if(!str) return 0;
  if(sscanf(str,"%s %s",name,what) != 2) return 0;
  targ = find_player(name);
  if(!targ) { write("Target not in play.\n"); return 1; }
  ob = clone_object(what);
  if(!ob) { write("Object did not clone.\n"); return 1; }
  move_object(ob,targ);
  tell_object(targ,"A soft wind blows and something "+ 
                   "is dropped into your inventory\n"+
                   "     **   From: "+capitalize(TPN)+
                   "    **\n");
  write("You have cloned "+what+" to "+name+"\n");
return 1; }
