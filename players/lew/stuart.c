inherit "room/room";

reset(arg) {
    object guard;
    if(!arg) {
    

    set_light(1);
    short_desc = "Stuart building";
    long_desc =
"As you wiggle through the screen, you are greeted by a scream of anger.\n"+
/*
"Apparently Keivjam is pissed that you killed his process.  You better duck.\n";
*/
"Apparently Keivjam is pissed you killed his process.  What a little shit.\n"+
"Even the Gods want his head on a silver platter...\n";
    guard=clone_object("players/lew/elof/keivjam2");
    move_object(guard, this_object());

    dest_dir = ( {
        "players/lew/state_st", "south",
    } );
}
}
