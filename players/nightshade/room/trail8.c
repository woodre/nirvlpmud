inherit "players/nightshade/new_room";
reset(arg){
   if(arg) return;
        set_light(1);
        short_desc = "Road to Ledsville";
     long_desc =
"Ledsville looms closer. Over the village you can see the smoke from\n"+
"the different houses and and especially large cloud billowing up from\n"+"the smithy. You can see the forest to the north, glowing softly.\n";
      dest_dir = 
      ({ "/players/nightshade/room/vroad1", "south",
      "players/nightshade/room/trail7", "north",
      });
}
