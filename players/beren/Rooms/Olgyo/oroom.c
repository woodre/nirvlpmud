inherit "room/room";

reset(arg) {
  if(arg) return;
    set_light(1);
    short_desc = "Olgyo land";
    long_desc =
"You've just entered the Olgyo land. What would you meet here?\n"+
"There is a little sign here.\n";
     dest_dir = ({"players/beren/Rooms/Olgyo/oroom9", "north",
	    "players/beren/Rooms/Olgyo/oroom1", "east",
	    "players/beren/Rooms/hall.c", "southwest"});
    items = ({"sign", "It's a sign. Just read it"});
}

init ()
{
    ::init ();
    add_action ("reading", "read");
}

reading (str)
{
    if (!id2 (str)) return 0;
    write ("\nHere are the directions you can go from here:\n");
    write ("North - Village of Zgama.\n");
    write ("East - A forest.\n");
    return 1;
}

id2 (str) {
    return str == "sign";
}
