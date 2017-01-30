inherit "players/nightshade/new_room";
reset(arg){
   if(arg) return;
        set_light(1);
        short_desc = " Ledsville";
     long_desc =
"This is Ledsville. It is a small but wealthy village, profiting\n"+
"from the gems mined in the caves to the northeast. South if you\n"+
"is a beautiful fountain.\n";
      dest_dir = 
      ({ "/players/nightshade/room/vroad3", "south",
      "players/nightshade/room/vroad1", "north",
/*
   "players/nightshade/room/blood_bank", "east",
*/
      });
}
