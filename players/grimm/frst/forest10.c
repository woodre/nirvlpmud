inherit "room/room";
reset(arg) {
if(arg)
      return;
short_desc="Forest of Blood";
long_desc="The forest is extremely dark here.  You can't tell which way you\n"+
   "came from because of the over-grown vegetation that surrounds you and\n"+
   "seems to move towards you.  The best thing to do is to keep moving.\n",
items=({"vegetation","It is a great mass of thorns with red and black leaves\n"+
   "that seem to be drawn by the blood in your body!"});
dest_dir=({"players/grimm/frst/forest6","north",
           "players/grimm/frst/forest15","south",
           "players/grimm/frst/forest14","southwest"});
set_light(0);
}
