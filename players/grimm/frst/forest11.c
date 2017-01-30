inherit "room/room";
reset(arg) {
monst();
if(arg)
      return;
short_desc="Forest of Blood";
long_desc="The forest is extremely dark here.  You can't tell which way you\n"+
   "came from because of the over-grown vegetation that surrounds you and\n"+
   "seems to move towards you.  The best thing to do is to keep moving.\n",
items=({"vegetation","It is a great mass of thorns with red and black leaves\n"+
   "that seem to be drawn by the blood in your body!"});
dest_dir=({"players/grimm/frst/forest7","north",
           "players/grimm/frst/forest16","south",
           "players/grimm/frst/forest12","east"});
set_light(0);
}
monst() {
   object dog;
   int count;
   if(!present("dog",this_object())) {
      while(count<4) {  count += 1;
         dog = clone_object("players/grimm/monster/vampdog");
         move_object(dog,this_object());
      }
   }
return 1; }
