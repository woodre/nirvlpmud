inherit "room/room";
 
 
short() {
      return "Holding Cell";
}
 
long() 
{
   write("\nYou are in a holding cell in the 13th Precinct.\n");
   write("There are huge steel bars that block your exit.\n");
   write("\nThere are NO exits.\n");
}
 
reset(arg) {
    if (arg) return;
    set_light(1);
}
 
init() {
  if(this_player()->query_level() < 20) {
    move_object(clone_object("/players/pathfinder/detroit/items/thingee.c"),this_player());
  }
 
  if(this_player()->query_level() < 20) {
#ifndef __LDMUD__
      add_action("nope"); add_xverb("");
#else
      add_action("nope", "", 3);
#endif
    }
}
 
nope(str)
{
  long();
  write("\nWhy would you want to do that?\n");
  return 1;
}
 

