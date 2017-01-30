#include "DEF.h"

tel(str) {
string ob, who, msg;
  if(lower_case(this_player()->query_real_name()) != "eurale") return 0;
  if(!str || sscanf(str,"%s %s",who,msg) != 2) {
  write("Use:  et <who> <msg> \n"); return 1; }
  ob = find_living(lower_case(who));
  if(!ob) { write("not here.... \n"); return 1; }
  if(!this_player()->query_invis() < 1) {
  tell_object(ob,BOLD+"Eurale whispers: "+NORM+msg+"\n");
    ob->add_tellhistory("Eurale whispers: "+msg+"\n");
  write(BOLD+"You whisper to "+capitalize(who)+": "+NORM+msg+"\n");
  return 1; }
  tell_object(ob,BOLD+"Eurale speaks: "+NORM+msg+"\n");
    ob->add_tellhistory("Eurale speaks: "+msg+"\n");
  write(BOLD+"You tell "+capitalize(who)+": "+NORM+msg+"\n");
return 1;
}
