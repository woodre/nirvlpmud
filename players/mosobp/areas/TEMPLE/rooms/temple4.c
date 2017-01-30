inherit "room/room";
reset(arg) {
  if(arg) return;

short_desc = "A Temple Foyer";
long_desc = 
"This room is lit by two large candles on both sides of the room.\n"+
"There are paintings on the walls, and drapes hanging over a window.\n"+
"The entrance is to the west a chandelier can just barely\n"+
"be made out from the doorway. A large desk sits in one corner\n"+
"of the room.\n";
  items= ({
  "candles","Two large candles light the room from the east and west walls\n",
"paintings","They appear to be paintings of certain places on the namekians\n"+
"home planet, Planet Namek",
"drapes","Curtains hanging over a window blocking the sunlight for some reason",
"papers","Forms from citizens requesting a certain service from the temple",
"window","The window can not be seen because the drapes are in the way\n",
"desk","A desk sits in the corner with a stack of papers on it",
"doorway","This doorway leads west to the entrance of the temple",
});
set_light(1);
dest_dir = ({
"/players/mosobp/areas/TEMPLE/rooms/temple9.c","north",
"/players/mosobp/areas/TEMPLE/rooms/temple5.c","east",
"/players/mosobp/areas/TEMPLE/rooms/temple3.c","west",
});
move_object(clone_object("/players/mosobp/areas/TEMPLE/NPC/mother1.c"), this_object());
return 1;
}
init()
{
  ::init();
  add_action("cmd_read", "read");
}

cmd_read(str)
{
  if(!str)
  {
    notify_fail("What would you like to read?\n");
    return 0;
  }
  if(str != "papers")
  {
    notify_fail("You can only read the papers.\n");
    return 0;
  }
  write("The papers are written in a language that you\n"+
        "do not understand.\n");
  return 1;
}
