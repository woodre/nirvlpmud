id(arg) {return arg=="facade";}

short() {
    return "A giant arched doorway lies to the east";
}

long() {
    write("This is a facade.\n");
}

init() {
    add_action("move","east");
}

move(str) {
    call_other(this_player(), "move_player", "east#players/molasar/ad_room");
    return 1;
}

get() {
    return(call_other(this_player(),"query_level",0) >= 100);
}

reset(arg) {
    if (arg)
        return;
    move_object(this_object(), "room/adv_guild");
}
