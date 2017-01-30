inherit "room/room";
reset(arg) {
  if(arg) return;

short_desc = "A Temple Foyer";
long_desc = 
"A bookshelf sits in each corner of the room. A few pictures are \n"+
"hanging along the walls. There is a large pillar in the center of the \n"+
"room. Plaques hang along the walls.\n";
  items= ({
"bookshelf","Every bookshelf in the room appears to be empty",
"bookshelves","Every bookshelf in the room appears to be empty",
"pillar","The pillar is covered in intricate artwork engraved into the sides of it",
"pictures","Pictures of various places on planet Namek",
"artwork","Intricate art engraved by a famous Namekian artist",
"candle","The candles along the walls make the plaques more visible",
"candles","The candles along the walls make the plaques more visible",
"plaques","Plaques hang along the wall by each candle in the room",
});
set_light(1);

dest_dir = ({
"/players/mosobp/areas/TEMPLE/rooms/temple10.c","north",
"/players/mosobp/areas/TEMPLE/rooms/temple4.c","west",
});
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
  if(str != "plaques")
  {
    notify_fail("You can only read the plaques.\n");
    return 0;
  }
  write("The plaques are written in a language that you\n"+
        "do not understand.\n");
  return 1;
}
