#include "/players/eurale/closed/ansi.h"

id(str)  { return str == "fratell"; }

drop()   { return 1; }
get()    { return 1;}

init(){
    
    add_action("fratell","fratell");
   
}


fratell(str) {
  object player;
  string who;
  string what;
	            
     if(!str) 
            {
             write("Tell what?\n"); 
     return 1;
            }
     if(sscanf(str,"%s %s",who,what)==2)
            {
             player = find_player(who);
     if(!player) 
            {
             write(capitalize(who) + " is not online now.\n"); 
    return 1; 
            }
    if(this_player()->query_invis() > 1) 
            {
       tell_object(player, HIW+this_player()->query_name()+" politely speaks: "+NORM+what+" \n");
             write(HIW+"You invisibly fratell "+capitalize(who)+NORM+": "+what+"\n");
             player->add_tellhistory(what);
    return 1; 
            }
    if(this_player()->query_invis() < 1) 
            {
       tell_object(player, HIW+this_player()->query_name()+" politely speaks: "+NORM+what+" \n");
	     write(HIW+"You fratell "+capitalize(who)+NORM+": "+what+"\n");
    return 1; 
            }
    return 1;
            }
    return 1;
            }
