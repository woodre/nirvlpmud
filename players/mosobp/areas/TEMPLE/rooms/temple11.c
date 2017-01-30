inherit "room/room";
reset(arg) {
  if(arg) return;

short_desc = "A Temple Foyer";
long_desc = 
"There is a window along the west wall of the room and pictures hanging\n"+
"along the north wall of the room from Namekian artists. All the\n"+
"candles in the room are extinguished except for one giant floor\n"+
"candle in the center of the room.\n";
  items= ({
"window","Out the window the outline of the battlefield on which, the\n"+
"fate of the planet has been decided many times. It appears that there is\n"+
"some fighting going on on the battlefield",
"pictures","Pictures of things seen in everyday life on planet Namek",
"candles","All the wall candles are extinguished",
"candle","The giant floor candle appears to light the whole room",
"battlefield","The battlefield seems to be buzzing with action",
"fighting","People appear to be fighting on the battlefield",
"west wall","Pictures by Namekian artists hang on the wall",
"north wall","Pictures by Namekian artists hang on the wall",
"wall candles","Candles lighting up the room along the wall",
"floor candle","A giant candle in the middle of the room on the floor",
"giant floor candle","A giant candle in the middle of the room on the floor",
});
set_light(1);

dest_dir = ({
"/players/mosobp/areas/TEMPLE/rooms/temple12.c","east",
"/players/mosobp/areas/TEMPLE/rooms/temple6.c","south",
});
}
