inherit "obj/treasure";

reset(arg){
    set_id("swpath");
    call_out("removeme",60);
}

init(){
    add_action("southwest","sw");
    add_action("southwest","southwest");
}

int southwest(){
say(this_player()->query_name()+" leave southwest.\n");
move_object(this_player(),"/players/wocket/graveyard/gr1.c");
say(this_player()->query_name()+" arrives from the northeast.\n");
command("glance",this_player());
return 1;
}

removeme(){
if(!environment(this_object())){ destruct(this_object()); return 1; }
tell_room(environment(this_object()),"The passageway to the southwest closes.\n");
destruct(this_object());
return 1;
}
