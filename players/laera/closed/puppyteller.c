/* Puppy's teller to players */

#include "/players/puppy/ansi.h"
inherit "/obj/treasure";

reset(arg){
	if(arg) return;
	set_id("bone");
	set_alias("teller");
set_short(""+CYN+"Puppy's bone"+NORM+"");
	set_long("This is Puppy's special teller.\n");

	set_weight(0);
	set_value(0);
	}

drop(){
	write("You may not drop your bone.\n");
	return 1;
	}

init(){
    ::init();
    add_action("pup","tt");
    add_action("pupe","te"); 
    add_action("pupf","tf");
}


pup(str) {
  object target;
  string who;
  string what;
                    
     if(!str) 
            {
             write("Tell what?\n"); 
     return 1;
            }
     if(sscanf(str,"%s %s",who,what)==2)
            {
             target = find_player(who);
     if(!target) 
            {
             write(capitalize(who) + " is nowhere to be found.\n"); 
    return 1; 
            }
    if(this_player()->query_invis() > 1) 
            {
             tell_object(target, BOLD+CYN+"[invis] Puppy barks: "+HIB+what+NORM+" \n");
             write(BOLD+CYN+"You tell "+capitalize(who)+": "+HIB+what+NORM+"\n");
             target->add_tellhistory(this_player()->query_real_name()+" tells you: "+what);

	return 1; 
            }
    if(this_player()->query_invis() < 1) 
            {
             tell_object(target,BOLD+CYN+"Puppy barks: "+HIB+what+NORM+" \n");
             write(""+BOLD+CYN+"You tell "+capitalize(who)+": "+HIB+what+NORM+"\n");
             target->add_tellhistory(this_player()->query_real_name()+" tells you: "+what);

	return 1; 
            }
   return 1;
     }
return 1;
}


pupe(str) {
  object target;
  string who;
  string what;
                    
     if(!str) 
            {
             write("Emote to whom?\n"); 
     return 1;
            }
     if(sscanf(str,"%s %s",who,what)==2)
            {
             target = find_player(who);
     if(!target) 
            {
             write(capitalize(who) + " is nowhere to be found.\n"); 
    return 1; 
            }
    if(this_player()->query_invis() > 1) 
            {
             tell_object(target,BOLD+CYN+"[invis] Puppy "+HIB+what+NORM+" \n");
             write(""+BOLD+CYN+"You faremote to " +capitalize(who)+": "+HIB+what+NORM+"\n");
             
    return 1; 
            }

    if(this_player()->query_invis() < 1) 
            {
             tell_object(target,""+BOLD+CYN+"Puppy "+HIB+what+NORM+" \n");
             write(""+BOLD+CYN+"You faremote to " +capitalize(who)+": "+HIB+what+NORM+"\n");
    return 1; 
            }
  return 1;
     }
return 1;
  }


pupf(str) {
  object target;
  string who;
  string what;
                    
     if(!str) 
            {
             write("Emote to whom?\n"); 
     return 1;
            }
     if(sscanf(str,"%s %s",who,what)==2)
            {
             target = find_player(who);
     if(!target) 
            {
             write(capitalize(who) + " is nowhere to be found.\n"); 
    return 1; 
            }
    if(this_player()->query_invis() > 1) 
            {
             tell_object(target,""+BOLD+RED+what+NORM+" \n");
             write(""+BOLD+RED+"You echo to " +capitalize(who)+": "+what+NORM+"\n");
             
    return 1; 
            }
    if(this_player()->query_invis() < 1) 
            {
             tell_object(target,""+BOLD+RED+what+NORM+" \n");
             write(""+BOLD+RED+"You echo to " +capitalize(who)+": "+what+NORM+"\n");

    return 1; 
         }
   return 1;
     }
return 1;
   }


