/*  Alarm Object - reports when someone enters then destructs.
will last 20 minutes otherwise. */

inherit "obj/treasure";
#include "/players/maledicta/ansi.h"
#define OWNER find_living(owner)

string owner;
int done;

reset(){
	set_id("invis_alarm_symb");
	set_weight(50000000);
	set_value(0);
	call_out("destroy_this", 1200);
        call_out("done", 4);
}

destroy_this(){ destruct(this_object()); }

done(){
if((!owner || !OWNER) && !root()) { destruct(this_object()); return; }
tell_object(OWNER, "Your symbiotic alarm burrows into the ground and is ready.\n");
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
					"Your alarm at "+environment()->short()+" rises from the earth and reports that\n"+
					HIR+this_player()->query_name()+NORM+" has entered the area.\n\n"+
				"  It then slides up to your foot and reenters your body.\n\n");
				destruct(this_object());
			}
		}
	}
}

