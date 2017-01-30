inherit "room/room";
reset(arg) {
  if(arg) return;

short_desc = "A Temple Foyer";
long_desc = 
"This is a foyer within the temple to the east is the altar. Scrolls\n"+
"hang in frames on the wall telling the past of this temple. Pictures of \n"+
"some of the fighters who have helped save this planet are also\n"+
"hanging around the room. A dull roar comes from the east as if it is\n"+
"someone chanting a hymn.\n";
  items=({
"pictures","Pictures of different fighters hang around the room\n"+
"On the east wall pictures of Goku, Krillin, and Tien are hanging up.\n"+
"On the south wall pictures of Yamcha, Yajirobe, and Piccolo are hanging up.\n"+
"On the west wall pictures of Gohan, Dende, and Vegeta, are hanging up.\n"+
"On the north wall pictures of Trunks, Nail, and Kami are hanging up",
"scrolls","There are scrolls hanging up that are telling the whole story of this temple\n"+
"from its first few months it was built",
"foyer","This is a foyer within the temple",
"altar","To the east you can make out the altar",
});
add_listen("main","You hear a dull roar to the east.\n");
set_light(1);

dest_dir = ({
"/players/mosobp/areas/TEMPLE/rooms/temple12.c","north",
"/players/mosobp/areas/TEMPLE/rooms/temple8.c","east",
"/players/mosobp/areas/TEMPLE/rooms/temple2.c","south",
"/players/mosobp/areas/TEMPLE/rooms/temple6.c","west",
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
  if(str != "scrolls")
  {
    notify_fail("You can only read the scrolls.\n");
    return 0;
  }
  write("The scrolls are written in a language that you\n"+
        "do not understand.\n");
  return 1;
}
