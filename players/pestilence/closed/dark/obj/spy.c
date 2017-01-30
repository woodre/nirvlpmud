inherit "obj/treasure";
#include "/players/pestilence/ansi.h"
#define OWNER find_living(owner)

string owner;
int done;

reset(){
        set_id("dorder_spy");
        set_short(""+HIK+"Dark Messenger"+NORM+"");
        set_weight(50000000);
        set_value(0);
        call_out("destroy_this", 300);
        call_out("done", 4);
}

destroy_this(){ destruct(this_object()); }

done(){
if((!owner || !OWNER) && !root()) { destruct(this_object()); return; }
tell_object(OWNER, "Your dark messenger takes its spot, and is ready to report any entrance to this room.\n");
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
                                tell_object(find_living(owner),
                                        "Dark messenger tells you: at "+environment()->short()+"-> "+HIR+this_player()->query_name()+NORM+" has entered the area.\n\n"+
                                "Dark messenger will continue to report to you.\n\n");
                                destruct(this_object());
                        }
                }
        }
}
