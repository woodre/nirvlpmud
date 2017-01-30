inherit "players/nightshade/new_room";
reset(arg){
   if(arg) return;
        set_light(1);
        short_desc = "Deep Forest";
     long_desc =
"Thick Bronzewood trees make up most of this portion of the forest.\n"+
"Most are about 40 feet tall and have reddish brown bark that is\n"+
"very hard. THe leaves are narrow and toothed about eight inches\n"+
"long.\n";
      dest_dir = 
      ({ "/players/nightshade/room/forest10", "south",
    "players/nightshade/room/forest5", "east",
"players/nightshade/room/trail3", "west",
      });
}
