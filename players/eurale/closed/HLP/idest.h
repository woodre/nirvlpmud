#include "DEF.h"
 
idest(str) {
string who,what;
  object ob;
  if(!str) { write("idest <who> <item> \n"); return 1; }
  sscanf(str,"%s %s",who,what);
  if(!find_player(who)) { write("player not present... \n"); return 1; }
  ob = present(what, find_player(who));
  if(!ob) { write("object not present... \n"); return 1; }
  destruct(ob);
  write(capitalize(what)+" destroyed...\n");
/*
  tell_object(find_player(who),"You suddenly feel lighter...\n");
*/
return 1;
}
