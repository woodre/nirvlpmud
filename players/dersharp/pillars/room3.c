inherit "room/room";
reset(arg) {
        if(!present("tree")) {
        move_object(clone_object("players/dersharp/monsters/tree"), this_object());
}
        if(arg) return;
        set_light(1);
        short_desc=("The Pillars");
        long_desc ="Here you find a large tree that has numerous arrows \n"+
        "protruding from it's bark.  Sap flows swiftly through the holes in the\n"+
        "bark. It looks like it is in great pain.\n";
        dest_dir = ({
                     "players/dersharp/pillars/enter.c", "north",
                     "players/dersharp/pillars/room4.c", "south",
                      });
}
