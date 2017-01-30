inherit "room/room";
reset(arg) {
  if(arg) return;

short_desc = "A Temple Foyer";
long_desc = 
"This room is lit up partly by the chandelier from the entrance but\n"+
"also by the candles spaced out around the room. There are quite a \n"+
"few candles around a certain picture in the center of the south wall.\n"+
"There are also many tapestries around the room.\n";
  items= ({
"tapestries","Pictures showing the fighting techniques of the namekian priests",
"candles","Candles light the larger portion of the room",
"picture","A picture of Dende the current guardian of the temple",
"chandelier","A dim glow comes from the main entrance to the temple\n"+
"where the chandelier hangs",
"entrance","The entrance to the temple",
"wall","This is the south wall to the temple",
"south wall","This is the south wall to the temple",
});
set_light(1);

dest_dir = ({
"/players/mosobp/areas/TEMPLE/rooms/temple7.c","north",
"/players/mosobp/areas/TEMPLE/rooms/temple3.c","east",
"/players/mosobp/areas/TEMPLE/rooms/temple1.c","west",
});
}
