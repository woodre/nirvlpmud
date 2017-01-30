#include "/players/vital/closed/headers/vital.h"
#include <ansi.h>

status main(string str) {
    object *obs;
    int x;
    string message, verb;

    if(!str || str == "history" || str == "list") return 0;
    verb = "wiz";

    if(str[0] == ':') message = "(" + verb + ") "+HIW+"Vital "+NORM+ str[1..strlen(str) -1] + "\n";
    else
    message = HIW+"Vital "+NORM+ verb + "s: " + str + "\n";
    obs = users();

    for(x = 0; x < sizeof(obs); x ++)
      if((status)obs[x]->on_channel(verb) && (int)obs[x]->query_level() > 20) tell_object(obs[x], message);
    

    "/obj/user/chistory"->add_history(verb, message); 
       
    return 1;
}
