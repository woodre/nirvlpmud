inherit "room/room";
 
reset (arg) 
{
/*  
  if (!present ("sign")) 
  {
    move_object (clone_object ("players/pathfinder/realm/items/sign"), this_object());
  }
*/
 
  if(arg) return;
  set_light(1);
  short_desc = "Entrance to Detroit";
  long_desc = "\n"+
"You stand in the shadow of the once-magnificant city of Detroit.  From\n" +
"Its heyday as the Motor City, it has become a crime infested, gang\n" +
"ridden urban area.  Trouble lurks everywhere within its borders.  There\n" +
"is no safety within its huge encompass.  You feel threatened here in its\n" +
"shadow.  To the north is the commercial area, and to the east is the ghetto\n";
  dest_dir = ({
    "players/pathfinder/realm/rooms/comm1.c", "north",
    "players/pathfinder/realm/rooms/ghetto1.c", "east",
    "room/forest5", "exit",
  });
}
 

