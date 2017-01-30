inherit "room/room";
 
init ()
{
  ::init ();
  this_player()->set_fight_area();
}

reset (arg) 
{
  int i;
  if (!present ("gangbanger")) 
  {
    for(i = 0; i < 2; i++) 
    {
      move_object(clone_object("players/pathfinder/detroit/monsters/gangbanger"), this_object());
    }
  }
 
  if (arg) return;
  set_light(1);
  short_desc = "Commercial District";
  long_desc = "\n"+
"There are many tall, well kept buildings around you.  The area around here\n" +
"is well kept.  You notice a couple of police officers roaming the streets.\n" +"This area appears to be relatively safe from the looks of it.\n";

  dest_dir = ({
    "players/pathfinder/detroit/rooms/hood2", "north",
    "players/pathfinder/detroit/rooms/war1", "south",
    "players/pathfinder/detroit/rooms/entrance", "west",
    "players/pathfinder/detroit/rooms/hood4", "east",
  });
}
