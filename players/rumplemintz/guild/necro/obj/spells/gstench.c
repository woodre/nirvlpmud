#include <ansi.h>

object creator;
int level;

id(str){ return str == "fog" || str == "stench" || str == "a fog of ghastly stench" || str == "ghastly stench"; }
short(){ return GRN+"A fog of ghastly stench"+OFF; }
long(){
    write(""+
      "A green fog of a ghastly stench.  The odor reeks and stings as it hits your\n"+
      "nose and mouth.  Luckily, the bulk of it only hovers about a foot off of the\n"+
      "ground.\n");
}

init()
{
    if(this_player() && this_player()->query_guild_name() != "necromancer")
    { 
       write(GRN+"You are hit by the overwelming stench of the fog.\n"+OFF);
       if(!random(10))
       {
	 write("You run away in disgust.\n");
         say(this_player()+" runs away in disgust.\n");
 	 this_player()->run_away();
       }
    }  
}

do_stench_damage(){
    int i,a;
    object *ppl;
    if(!creator) return 0;
    if(!environment(this_object())) return 0;
    ppl = all_inventory(environment(this_object()));
    tell_room(environment(this_object()),GRN+"The ghastly stench fumes.\n"+OFF); 
    for(i=0, a=sizeof(ppl);i<a;i++) {
	if(living(ppl[i])){
	    if(ppl[i]->query_npc()){
		if(!random(10)){  
		    ppl[i]->attacked_by(creator);  
		    ppl[i]->run_away();
		}
		else
                {
                    if(ppl[i]->query_guild_name() != "necromancer")
                    { 
		       tell_room(environment(this_object()),ppl[i]->query_name()+" recoils in pain from the stench.\n"); 
		       ppl[i]->heal_self(-random(level*2));
		       ppl[i]->attacked_by(creator);
                    }
		}
	    }
	    else{
		if(!random(10) && ppl[i]->query_guild_name() != "necronamcer"){
		    ppl[i]->run_away();
		}
	    } 
	}
    }
    call_out("do_stench_damage",10);
}

set_creator(object c){ creator = c; }
set_level(int l){ level = l; }
set_time(t){ call_out("stopstench",t); }

stopstench(){
    tell_room(environment(this_object()),"The ghastly stench disapates from the room clearing the air.\n");
    destruct(this_object());
    return 1;
}  
