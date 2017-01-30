inherit "players/nightshade/new_room";
reset(arg){
   if(arg) return;
        set_light(1);
        short_desc = "Forest Trail";
     long_desc =
"You are walking along a trail leading south and north through the forest. Further to the south you can see a small village.\n";
      dest_dir = 
      ({ "/players/nightshade/room/trail7", "south",
      "players/nightshade/room/trail5", "north",
    "players/nightshade/room/forest22", "east",
 "players/nightshade/room/forest21", "west",
      });
}
