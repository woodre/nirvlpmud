inherit "room/room";
reset(arg) {
  if(arg) return;

short_desc = "A Temple Foyer";
long_desc =
"The walls in this room are lined with shelves holding ceramic\n"+
"bowls, cups, and pitchers. There is a chair with a machine \n"+
"to make pottery.  The walls are a dull grey color, and the room is\n"+
"rather musty due to the pottery machine.\n";
  items= ({
  "shelves","The shelves are lined with bowls, cups, and pitchers",
  "bowls","Bowls that have been made by the pottery machine and hand painted",
  "cups","Cups that have been made and then hand painted",
  "pitchers","Pitchers that have been made and then hand painted",
  "chair","The chair is sitting directly behind the pottery machine",
"machine","A machine used to make pottery",
"pottery machine","A machine used to make pottery",
"walls","There are shelves along the walls of the room",
});
set_light(1);

dest_dir = ({
"/players/mosobp/areas/TEMPLE/rooms/temple14.c","north",
"/players/mosobp/areas/TEMPLE/rooms/temple10.c","east",
"/players/mosobp/areas/TEMPLE/rooms/temple4.c","south",
"/players/mosobp/areas/TEMPLE/rooms/temple8.c","west",
});
}
