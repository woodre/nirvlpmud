inherit "room/room";
int flag;
string owner;
reset(arg) {
   flag = 0;
   if(arg)
      return;
short_desc="Forest of Blood";
long_desc="The forest is extremely dark here.  You can't tell which way you\n"+
   "came from because of the over-grown vegetation that surrounds you and\n"+
   "seems to move towards you.  The best thing to do is to keep moving.\n"+
   "There seems to be a large steel grate under some leaves next to a nearby\n"+
   "tree.\n",
items=({"vegetation","It is a great mass of thorns with red and black leaves\n"+
   "that seem to be drawn by the blood in your body!","grate",
   "As you examine the grate you notice a passage below it."});
dest_dir=({"players/grimm/frst/forest11","north",
           "players/grimm/frst/forest20","south",
           "players/grimm/frst/forest17","east",
           "players/grimm/frst/forest15","west"});
set_light(0);
}
init() {
   add_action("lift","lift");
    add_action("lift","move");
   ::init();
}
lift(str) {
/*
   if(flag==1 && this_player()->query_name() != owner) {
      write("You search the room, but the entrance has been blocked!\n");
      return 1;
   }
*/
if(!str) {
  write("What do you want to lift?\n");
  return 1;
}
if(str!="grate") {
  write(capitalize(str)+" cannot be moved.\n");
  return 1;
}
   write("As you search the room you find a secret entrance leading down.\n");
   write("Feeling brave you decide to enter it!\n");
   owner = this_player()->query_name();
   move_object(this_player(),"players/grimm/caverns/cavern1");
   flag = 1;
   return 1;
}
