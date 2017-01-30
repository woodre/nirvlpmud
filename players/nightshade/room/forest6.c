inherit "players/nightshade/new_room";
reset(arg){
   if(arg) return;
        set_light(1);
        short_desc = "Deep Forest";
     long_desc =
"The forest thins out here some which allows you to see a small cave to the west.\n";
      dest_dir = 
      ({ "/players/nightshade/room/forest12", "south",
 "players/nightshade/room/forest5", "west",
"players/nightshade/room/imp", "east",
      });
}
