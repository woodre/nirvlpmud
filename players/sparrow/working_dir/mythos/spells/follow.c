#include "/players/mythos/closed/guild/def.h"

int ref;
string reff, foldn;
object targ, reft, fold;

id(str) { return str == "follow_1"; }

set_reference(str) { reff = str; }
set_foll(str) { foldn = str; fold = find_living(foldn); }
query_reference() { return ref; }

start() {
if(!ep) return 1;
if(!fold || ep->query_ghost() || !(ep->query_interactive())) { 
    tell_object(ep,"What you are following is no longer in play.\n");
    command("dfollow stop",ep);
    return 1;}
    if(!present(reff,fold)) { fold = find_living(foldn); 
    call_out("start",4);
return 1;}
  if(environment(fold) && environment(ep)) {
  if(environment(fold) != environment(ep)) {
  if(environment(fold)->realm() != "NT") {
  tell_room(environment(ep),capitalize(ep->query_real_name())+
    " leaves quietly after "+capitalize(fold->query_name())+".\n");
    move_object(ep,environment(fold)); 
      command("look",ep);
  tell_room(environment(ep),capitalize(ep->query_real_name())+
    " enters quietly after "+capitalize(fold->query_name())+".\n");}
    }
    }
  call_out("start",4);
return 1;}

drop() { return 1; }
