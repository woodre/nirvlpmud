/* players/pathfinder/detroit/rooms/agency */
 
/* A Travel Agency! */
 
inherit "room/room";
 
reset(arg) {
if(!present("computer")) {
  move_object(clone_object("players/pathfinder/detroit/items/computer"), this_object());
  }
if(!present("agent")) {
  move_object(clone_object("players/pathfinder/detroit/monsters/agent"), this_object());
  }
 
if(!arg) {
  set_light(1);
  short_desc = "A Travel Agency";
  long_desc = "\n"+
"You are in the Nirvana Travel Agency.  It seems like a busy place\n"+
"with having to keep track of all the Wizards areas and such.  You see\n"+
"an open Travel Agent ahead of you.\n"+
"\nTo get information on a particular Wizards area type 'info <wizs name>'\n";
  dest_dir = ( {
    "players/pathfinder/detroit/rooms/city1", "west",
    "room/church", "church",
    });
  items = ({
    "brochures", "Informational brochures on all the areas on Nirvana.",
    });
  }
}
 
