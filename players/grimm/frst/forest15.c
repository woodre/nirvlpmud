inherit "room/room";
object vampire;
int count;
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
dest_dir=({"players/grimm/frst/forest10","north",
           "players/grimm/frst/forest19","south",
           "players/grimm/frst/forest16","east",
           "players/grimm/frst/forest14","west"});
set_light(0);
}
monst() {
   count = 0;
   if(!present("vampire",this_object())) {
      while(count<5) {
         count += 1;
         vampire=clone_object("players/grimm/monster/yungvamp");
         move_object(vampire,this_object());
      }
   }
}
