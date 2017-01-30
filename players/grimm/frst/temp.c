inherit "room/room";
int flag;
reset(arg) {
if(arg)
      return;
short_desc="Forest of Blood";
long_desc="The forest is extremely dark here.  You can't tell which way you\n"+
   "came from because of the over-grown vegetation that surrounds you and\n"+
   "seems to move towards you.  The best thing to do is to keep moving.\n"+
   "There is also an old rusty looking grate on the floor here.\n",
items=({"vegetation","It is a great mass of thorns with red and black leaves\n"+
   "that seem to be drawn be the blood in your body!",
   "grate","This is an extremly heavy looking grate"});
dest_dir=({"players/grimm/frst/forest4","northwest",
           "players/grimm/frst/forest25","south",
           "players/grimm/frst/forest27","east"});
set_light(0);
}
init() {
   add_action("lift","lift");
   add_action("down","down");
   ::init();
}
lift(str) {
   if(!str) {  write("Lift what?\n");  return 1;  }
   if(str!="grate") return 0;
   if(flag==1) {  write("It is already open.\n");  return 1;  }
   write("You use all your strength to lift the grate up.\n");
   flag = 1;
   return 1; 
}
down() {
   if(flag==0) { write("The grate blocks your way!\n");  return 1;  }
   flag = 0;
   this_player()->move_player("down into the grate#players/grimm/frst/forest40");
   return 1; 
}
