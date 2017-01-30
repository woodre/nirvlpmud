inherit "obj/treasure";

reset(arg){
   set_id("epath");
    call_out("removeme",60);
}

init(){
    add_action("west","w");
    add_action("west","west");
}

int west(){
say(this_player()->query_name()+" leave west.\n");
move_object(this_player(),"/players/wocket/mushrooms/mg1.c");
say(this_player()->query_name()+" arrives from the east.\n");
command("look",this_player());
return 1;
}

removeme(){
if(!environment(this_object())) { destruct(this_object()); return 1; }
tell_room(environment(this_object()),"The passageway to the west closes.\n");
destruct(this_object());
return 1;
}
