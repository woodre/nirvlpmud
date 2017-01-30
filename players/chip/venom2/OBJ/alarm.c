/*  Alarm Object - reports when someone enters then destructs.
will last 30 minutes otherwise. */

inherit "obj/treasure";
#include "/players/chip/ansi.h"
#define OWNER find_living(owner)

string owner;
int done;

reset(){
	set_id("invis_alarm_symb");
	set_weight(50000000);
	set_value(0);
	call_out("destroy_this", 1800); /*changed duration from 20 minutes to 30 minutes to make more reliable -Chip(4-15-09)*/
        call_out("done", 4);
}

destroy_this(){ destruct(this_object()); }

done(){
if((!owner || !OWNER) && !root()) { destruct(this_object()); return; }
tell_object(OWNER, ""+BOLD+"Your symbiotic alarm burrows into the ground, then waits for an intruder."+NORM+".\n");
done = 1;
return 1;
}
set_owner(str){ owner = str; }
query_owner(){ return owner; }

get(){ return 0; }

init(){
if(!done) return;
    if(!environment()) return;
	if(this_player()){
		if(!this_player()->is_npc()){
			if(find_living(owner)){
            remove_call_out("destroy_this");
				tell_object(find_living(owner),
					""+YEL+"Your alarm at "+environment()->short()+" "+YEL+"rises from the earth and reports that\n"+
					HIR+this_player()->query_name()+NORM+""+YEL+" has entered the area"+NORM+".\n\n"+
				"  "+YEL+"It then slides up to your foot and reenters your body"+NORM+".\n\n");
				destruct(this_object());
			}
		}
	}
}

