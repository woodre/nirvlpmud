inherit "room/room";
reset(arg) {
  if(arg) return;

short_desc = "A Temple Foyer";
long_desc = 
"There is a few felt rugs laying around the room spaced evenly apart,\n"+
"and all are facing the north wall. The room has a couple of giant floor\n"+
"candles in between the rugs, and a giant pillar in the middle\n"+
"of the room.\n";
  items= ({
"rugs","The rugs in the room are evenly spaced apart and facing the north wall, perhaps\n"+
"the rugs are for people to kneel on while they pray",
"felt rugs","The rugs in the room are evenly spaced apart and facing the north wall,\n"+
"perhaps the rugs are for people to kneel on while they pray",
"candles","Giant candles on a long rod attached to the floor that light the room",
"pillar","A giant pillar in the center of the room with entricate artwork all around it",
"north wall","There doesnt appear to be anything on the wall",
"rod","The rod holding the floor candle up",
"long rod","The rod holding the floor candle up",
"floor","The floor is covered with rugs evenly spaced apart",
"floor candles","Candles lighting the entire room",
"giant floor candles","Candles lighting the entire room",
});
set_light(1);

dest_dir = ({
"/players/mosobp/areas/TEMPLE/rooms/temple13.c","east",
"/players/mosobp/areas/TEMPLE/rooms/temple7.c","south",
"/players/mosobp/areas/TEMPLE/rooms/temple11.c","west",
});
move_object(clone_object("/players/mosobp/areas/TEMPLE/NPC/peasant1.c"), this_object());
return 1;
}
