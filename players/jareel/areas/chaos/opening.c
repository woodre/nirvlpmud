inherit "obj/treasure";

reset(arg){
    set_id("dpath");
    call_out("removeme",60);
}

init(){
    add_action("down","d");
    add_action("down","down");
}

int down(){
say(this_player()->query_name()+" leaves down.\n");
move_object(this_player(),"/players/wocket/caves/maincroom.c");
say(this_player()->query_name()+" falls down into the caves.\n");
command("look",this_player());
return 1;
}

removeme(){
if(!environment(this_object())) { destruct(this_object()); return 1; }
tell_room(environment(this_object()),"The passageway down closes.\n");
destruct(this_object());
return 1;
}
