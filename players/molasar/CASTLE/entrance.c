

reset(arg) {
     if(!arg)
       set_light(1);
     extra_reset();
}

object fountain;

extra_reset() {
     if(!present("fountain")) {
       fountain = clone_object("players/molasar/OBJ/fountain");
       move_object(fountain, this_object());
     }
}

short() { return "The main courtyard of the castle"; }

long() {
     write("This is a lavishly decorated courtyard of the castle.  Numerous\n");
     write("colorful trees line the sides while a beatiful fountain lies\n");
     write("in the center.  A cobblestone road lies to the south while\n");
     write("you can see a garden to the north.\n");
     write("   There are four obvious exits:  north, south, east, and west\n");
}

init() {
     add_action("north","north");
     add_action("south","south");
     add_action("east","east");
     add_action("west","west");
}

north() {
     call_other(this_player(),"move_player",
                     "north#players/molasar/CASTLE/garden1");
     return 1;
}

south() {
     call_other(this_player(), "move_player",
                    "south#players/molasar/CASTLE/road1");
     return 1;
}

east() {
     if(!this_player()->query_npc()) {
     call_other(this_player(), "move_player",
                    "east#players/molasar/CASTLE/entry");
     return 1;
     } else return 1;
}

west() {
     call_other(this_player(),"move_player",
                    "west#players/molasar/CASTLE/cpath1");
     return 1;
}

