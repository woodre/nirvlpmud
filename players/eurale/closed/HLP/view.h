#include "DEF.h"
 
view(str) {
string who,type;
object ob;
  if(!str) {write("view name a/h \n"); return 1; }
  sscanf(str,"%s %s",who,type);
  if(!find_player(who)) {write("Not here.... \n"); return 1; }
  if(!present("qt",find_player(who))) {write("no...qt.. \n"); return 1; }
  ob = present("qt",find_player(who));
  if(type == "a") { call_other(ob,"alias"); }
  if(type == "h") { call_other(ob,"history"); }
return 1;
}
