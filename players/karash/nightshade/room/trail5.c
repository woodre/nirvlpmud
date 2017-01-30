inherit "players/nightshade/new_room";
reset(arg){
   if(arg) return;
        set_light(1);
        short_desc = "Forest Trail";
     long_desc =
"You are walking caustiously along a trail going south through the forest.\n";
      dest_dir = 
      ({ "/players/nightshade/room/trail6", "south",
      "players/nightshade/room/trail4", "north",
    "players/nightshade/room/forest16", "east",
 "players/nightshade/room/forest15", "west",
      });
}
