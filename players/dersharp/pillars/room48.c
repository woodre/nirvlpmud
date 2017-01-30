inherit "room/room";
int i;
id(str) { return str == "pillar"; }
reset(arg) {
   if (arg) return;
   short_desc="The foundation";
   long_desc ="This room is barren except for a huge pillar rising up from\n"+
              "from the floor.  With all the protection you would have \n"+
              "thought there was something here.\n";
   set_light(1);
   dest_dir =
   ({
             "players/dersharp/pillars/room47.c", "north",
   });
   items = ({
          "pillar", "This huge pillar doesn't seem to be holding anything\n"+
                    "Just about anything could be hidden beneath it.....\n"
           });
}
init() {
    ::init();
    add_action ("lift", "lift");
    add_action("lift","pull");
     add_action("lift","push");
}
lift(str) {
     if(str == "pillar") {
     write("You are able to move the pillar about one foot to the left and\n"+
           "let it come crashing down.  There might be something there.\n");
     move_object(this_player(), "players/dersharp/pillars/roomb");
    command("look",this_player());
}
return 1;
}
