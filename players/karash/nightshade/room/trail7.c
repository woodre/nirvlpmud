inherit "players/nightshade/new_room";
reset(arg){
monster();
   if(arg) return;
        set_light(1);
        short_desc = "Road to Ledsville";
     long_desc =
"The forest is now behind you. You are on a road that seems to be\n"+
"well used and leads south to Ledsville. The Phostwood Forest is \n"+
"to the north.\n";
      dest_dir = 
      ({ "/players/nightshade/room/trail8", "south",
      "players/nightshade/room/trail6", "north",
      });
}
monster() {
object shit;
if(!present("guard")) {
shit=clone_object("players/nightshade/mons/crysguard");
move_object(shit, this_object());
}
}
