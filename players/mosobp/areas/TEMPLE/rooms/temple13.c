inherit "room/room";
reset(arg) { 
  if(arg) return;

short_desc = "A Temple Foyer";
long_desc = 
"This room is bare except for a couple of maps hanging from\n"+
"the wall. There is also a pedestal in front of the room. The pedestal\n"+
"is illuminated by a giant candle right beside it.\n";
  items= ({
"maps","A couple of maps showing the major cities on planet Namek",
"pedestal","A pedestal with a collection plate on top of it for people to put change in",
"candle","A giant floor candle illuminating the room beside the pedestal",
"giant candle","A giant floor candle illumination the room beside the pedestal",
"wall","The north wall in the room has a map hanging on it",
"plate","A plate that was used to collect money",
"collection plate","A plate that was used to collect money",
});
set_light(1);

dest_dir = ({
"/players/mosobp/areas/TEMPLE/rooms/temple14.c","east",
"/players/mosobp/areas/TEMPLE/rooms/temple8.c","south",
"/players/mosobp/areas/TEMPLE/rooms/temple12.c","west",
"/players/mosobp/areas/BATTLE/rooms/bb00.c","out",
});
move_object(clone_object("/players/mosobp/areas/TEMPLE/NPC/noble1.c"), this_object());
return 1;
}
