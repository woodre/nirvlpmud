
#include "/players/khrell/ansi.h"
inherit "/obj/treasure";

reset(arg){
	if(arg) return;
	set_id("rune");
	set_alias("teller");
	set_short(""+BOLD+BLK+"A Vox-Caster"+NORM+"");
	set_long("This is Khrell's special teller.\n");

	set_weight(0);
	set_value(0);
	}

drop(){
	write("You may not drop your rune.\n");
	return 1;
	}

init(){
    ::init();
    add_action("rune","rune");
    add_action("runee","runee"); 
    add_action("runef","runef");
}


rune(str) {
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
             tell_object(target, RED+"[invis] Khrell tells you: "+HIW+what+NORM+" \n");
             write(RED+"You tell "+capitalize(who)+": "+HIW+what+NORM+"\n");
             target->add_tellhistory(this_player()->query_real_name()+" tells you: "+what);

	return 1; 
            }
    if(this_player()->query_invis() < 1) 
            {
             tell_object(target,HIR+"Khrell tells you: "+HIW+what+NORM+" \n");
             write(""+HIR+"You tell "+capitalize(who)+": "+HIW+what+NORM+"\n");
             target->add_tellhistory(this_player()->query_real_name()+" tells you: "+what);
             target->Replyer("khrell");

	return 1; 
            }
   return 1;
     }
return 1;
}


runee(str) {
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
             tell_object(target,CYN+"[invis] Khrell "+HIW+what+NORM+" \n");
             write(""+CYN+"You faremote to " +capitalize(who)+": "+HIW+what+NORM+"\n");
             
    return 1; 
            }

    if(this_player()->query_invis() < 1) 
            {
             tell_object(target,""+CYN+"Khrell "+HIW+what+NORM+" \n");
             write(""+CYN+"You faremote to " +capitalize(who)+": "+HIW+what+NORM+"\n");
    return 1; 
            }
  return 1;
     }
return 1;
  }


runef(str) {
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
             tell_object(target,""+NORM+what+NORM+" \n");
             write(""+WHT+"You echo to " +capitalize(who)+": "+what+NORM+"\n");
             
    return 1; 
            }
    if(this_player()->query_invis() < 1) 
            {
             tell_object(target,""+NORM+what+NORM+" \n");
             write(""+WHT+"You echo to " +capitalize(who)+": "+what+NORM+"\n");

    return 1; 
         }
   return 1;
     }
return 1;
   }


