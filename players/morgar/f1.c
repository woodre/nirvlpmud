id(arg) {return arg=="smithy";}

short() {
    return "The smithy is to the west";
}

long() {
    write("A old store front, the shop appears to sell weapons and armor.\n");
}

init() {
  add_action("move", "west");
}

move(str) {
    call_other(this_player(), "move_player", "west#players/morgar/smithy");
    return 1;
}

get() {
    return(call_other(this_player(),"query_level",0) >= 20);
}

reset(arg) {
    if (arg)
        return;
    move_object(this_object(), "room/northroad1");
}
is_castle() { return 1;}
