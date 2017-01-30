id(arg) { 
     return arg=="shop" || arg=="magic shop";
  }

short() {
    return "The magic shop is to the west";
}

long() {
    write("A small store front, with an old sign reading 'Magic Shop'\n");
}

init() {
  add_action("move", "west");
}

move(str) {
    call_other(this_player(), "move_player", "north#players/morgar/magic");
    return 1;
}

get() {
    return(call_other(this_player(),"query_level",0) >= 20);
}

reset(arg) {
    if (arg)
        return;
    move_object(this_object(), "room/northroad2");
}
is_castle() {return 1;}
