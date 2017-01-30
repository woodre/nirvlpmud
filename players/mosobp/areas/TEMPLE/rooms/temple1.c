inherit "room/room";
reset(arg) {
  if(arg) return;

short_desc="A Temple Foyer";
long_desc = 
"This is a long foyer in the temple it splits off to the north\n"+
"or to the east.  There are many pictures hanging on the wall\n"+
"of former priests of the temple. There are also some scrolls on\n"+
"the walls. The room is lit by candles spaced out along the walls.\n";
  items= ({
  "pictures","These are pictures of former priest of this temple who moved onward\n"+
"with their journeys in life",
"candles","Candles light the room with a dim glow because they are spead apart",
"foyer","The end of the foyer splitting in two directions to make an L",
"temple","You are in the temple",
"scrolls","Scrolls telling of the abilities a priest learns in this temple",
"walls","The walls are covered with pictures of former priest of this temple",
});
set_light(1);

dest_dir = ({
"/players/mosobp/areas/TEMPLE/rooms/temple6.c","north",
"/players/mosobp/areas/TEMPLE/rooms/temple2.c","east",
});
move_object(clone_object("/players/mosobp/areas/TEMPLE/NPC/monk1.c"), this_object());
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
  if(str != "scrolls")
  {
    notify_fail("You can only read the scrolls.\n");
    return 0;
  }
  write("The scrolls are written in a language that you\n"+
        "do not understand.\n");
  return 1;
}
