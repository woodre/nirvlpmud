inherit "/room/room";

void reset(int arg){
    if(!present("warrior"))
	move_object(clone_object("/players/rumplemintz/mon/bane/skwarr"), this_object());
    if(arg) return;
    set_light(1);
    short_desc = "Entrance to Lord Bane's grounds";
    long_desc = "\
     This is the entrance to Lord Bane's grounds.  There is an open fence \n"+
"that looks rusty and unused.  Off in the distance, there appears to be a \n"+
"castle.  The air is thick with humidity.  Moss and other fungi appear to be\n"+
"growing on everything.\n";
    items = ({
      "fence", "It appears rusty and unused",
      "castle", "It's hard to make out from this distance",
      "moss", "It's moss.  Not very interesting",
      "fungi", "It looks like the moss, not very interesting",
    });
    dest_dir = ({
      "players/rumplemintz/room/eastland", "southwest",
      "players/rumplemintz/room/bane/room2", "south",
      "players/rumplemintz/room/bane/room3", "north",
      "players/rumplemintz/room/bane/room5", "east",
    });
}
