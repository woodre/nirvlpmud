inherit "room/room";
reset(arg) {
  if(arg) return;

short_desc = "A Temple Foyer";
long_desc = 
"This room is full of shrubbery, there are plants hanging from the\n"+
"ceiling. Plants also sit in the corners, and along the walls of the room.\n"+
"There is also a giant window in the north wall of the room.\n";
  items= ({
"shrubbery","Plants are all over the room hanging from the ceiling and sitting on the floor",
"plants","Plants are all over the room, hanging from the ceiling and sitting on the floor",
"window","The window appears to be here only to allow sunlight into the room,\n"+
"and to help the plants grow",
"floor","The floor is made of marble, and has a plant in each corner of the room",
"ceiling","There are plants hanging all over the ceiling",
"walls","The walls are partially hidden by plants",
"corners","The corners are fully hidden behind the plants",
});
set_light(1);

dest_dir = ({
"/players/mosobp/areas/TEMPLE/rooms/temple15.c","east",
"/players/mosobp/areas/TEMPLE/rooms/temple9.c","south",
"/players/mosobp/areas/TEMPLE/rooms/temple13.c","west",
});
}
