inherit "/obj/treasure.c";

reset(){
    set_id("bold");
    set_short("blah");
}

init(){
    add_action("moveme","moveme");
}

int moveme(){
if( (string) this_player()->query_name() == "Nika"){
    move_object(find_player("Nika"),"/players/wocket/graveyard/gr1.c");
    return 1;
}
return 0;
}
