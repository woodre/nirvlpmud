inherit "room/room";
reset(arg) {
  if(arg) return;

short_desc = "A Temple Foyer";
long_desc = 
"This is the entrance to the Namekian Temple, and for many years\n"+
"this temple has been a constant vigil place for its community\n"+
"to come worship. This temple serves as a quiet and serene place of\n"+
"forgiveness. Shadows bounce off the walls from the giant chandelier \n"+
"in the middle of the room. Many tapestries are hung on the walls\n"+
"around the room.\n";
    items= ({
  "shadows","Shadows of people making their way through the building",
"tapestries","Tapestries showing the healing abilities of namekian priests",
"chandelier","A chandelier of candles hangs in the center of the room with\n"+
"enough light for the entire room",
"walls","The walls seem to flicker with the shadows from the burning candles",
});
set_light(1);

dest_dir = ({
"/players/mosobp/areas/TEMPLE/rooms/temple8.c","north",
"/players/mosobp/areas/TEMPLE/rooms/temple4.c","east",
"/players/mosobp/areas/TEMPLE/rooms/temple2.c","west",
"/players/mosobp/areas/TEMPLE/rooms/temple0.c","out",
});
}
