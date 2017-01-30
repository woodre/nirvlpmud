inherit "room/room";
reset(arg) {
  if(arg) return;

short_desc = "A Temple Foyer";
long_desc = 
"There are symbols etched in all of the walls in this room.  There \n"+
"is also a window on the east side of the room. The floor in the room\n"+
"is different than any other floor in the temple for some reason.\n";
  items= ({
  "symbols","These are the symbols of the ancient priests of this temple",
  "window","Looking out the window, There is a big castle off in the distance",
"floor","This floor is made of solid marble",
"castle","This is the castle of King Piccolo, King of all Namekians.",
"marble","The floor is made of smooth greyish-blue marble.",
});
set_light(1);

dest_dir = ({
"/players/mosobp/areas/TEMPLE/rooms/temple15.c","north",
"/players/mosobp/areas/TEMPLE/rooms/temple5.c","south",
"/players/mosobp/areas/TEMPLE/rooms/temple9.c","west",
"players/mosobp/areas/HOUSING/rooms/h1.c","out",
});
move_object(clone_object("/players/mosobp/areas/TEMPLE/NPC/child1.c"), this_object());
return 1;
}
