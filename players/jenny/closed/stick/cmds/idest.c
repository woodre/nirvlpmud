#include "/players/jenny/define.h"
main(str) { 
string name,what;
object ob,targ;
  if(!str) return 0;
  if(sscanf(str,"%s %s",name,what) != 2) return 0;
  targ = find_player(name);
  if(!targ) { write("Target is not in play.\n");
    return 1; }
  ob = present(what,targ);
  if(!ob) { write("Object is not on target.\n");
   return 1; }
  destruct(ob);
  tell_object(targ,BOLD+RED+capitalize(TPN)+NORM+" has dested "+
     what+" off you.\n");
  write("You have dested "+what+" off "+name+"\n");
return 1; }
