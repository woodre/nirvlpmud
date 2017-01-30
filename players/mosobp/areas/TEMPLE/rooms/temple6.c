inherit "room/room";
reset(arg) {
  if(arg) return;

short_desc = "A Temple Foyer";
long_desc = 
"This is a foyer within the temple, pictures of some fighters are on\n"+
"the walls. Shadows bounce around the room from the flickering of the\n"+
"candle candelier in the center of the room. The candles on\n"+
"the walls around the room flicker as they slowly burn down.\n";
    items  =  ({
  "pictures","These are pictures of the fighters who attempt to protect the earth from evil",
"chandelier","A round metal object holding candles every other inch to provide\n"+
"light in the room",
"candles","Candles illuminating the pictures on the wall",
"foyer","This is the end of a foyer that splits in three directions",
"shadows","Shadows from the flickering candles",
});
set_light(1);

dest_dir = ({
"/players/mosobp/areas/TEMPLE/rooms/temple1.c","south",
"/players/mosobp/areas/TEMPLE/rooms/temple11.c","north",
"/players/mosobp/areas/TEMPLE/rooms/temple7.c","east",
});
}
